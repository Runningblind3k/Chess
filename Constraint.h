#ifndef ___Constraint___
#define ___Constraint___
#include <functional>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

/**********************************************************************************************//**
 * @def	formula
 *
 * @brief	A macro that defines formula.
 *
 * @author	David
 * @date	4/27/2015
 **************************************************************************************************/

#define formula [&]()

/**********************************************************************************************//**
 * @def	setFormula(x) setFormulaEx([&]
 *
 * @brief	A macro that defines setFormula. This macro makes it much easier too set the value of a constraint
 * 			object's formula. This macro leverages the SetFormulaEx function.
 *
 * @author	David
 * @date	4/27/2015
 *
 * @param	x	The void to process.
 **************************************************************************************************/

#define setFormula(x) setFormulaEx([&]() {return ((x)); })

/**********************************************************************************************//**
 * @class	Constraint
 *
 * @brief	The constraint class allows for users to create objects that can depend on the values of other objects. 
 * 			Similarly if other constraint objects depend on this object they will be notified if the value of this 
 * 			constraint changes. 
 *
 * @author	David
 * @date	4/27/2015
 **************************************************************************************************/

class Constraint{
public:
	/** @brief	Stack of constraints. */
	static stack<Constraint *> Constraint_stack;

	using Formula = function <int()>;
	/** @brief	The default eval. */
	Formula default_eval = [&](){return 0; /* value;*/ };

	/** @brief	true to valid. */
	bool valid;

	/**********************************************************************************************//**
	 * @fn	Constraint::Constraint()
	 *
	 * @brief	Default constructor. This constructor uses a default evaluation that simply returns a value.
	 * 			This can be useful for instances where other things depend on this but this value does not depend 
	 * 			on another constraint object. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 **************************************************************************************************/

	Constraint() : eval(default_eval){} 

	/**********************************************************************************************//**
	 * @fn	Constraint::Constraint(int& v)
	 *
	 * @brief	This constructor is functionally similarly to the default constructor with the simple exception that
	 * 			it defines a value for the object during construction while still using the default evaluation function.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param [in,out]	v	The int&amp; to process.
	 **************************************************************************************************/

	Constraint(int v) : value(v), eval(default_eval){}

	/**********************************************************************************************//**
	 * @fn	Constraint::Constraint(Formula f)
	 *
	 * @brief	This constructor accepts a formula that replaces the default evaluation formula.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	f	The Formula to process.
	 **************************************************************************************************/

	Constraint(Formula f) : eval(f){} 

	/**********************************************************************************************//**
	 * @fn	Constraint::Constraint(Constraint & f) = default;
	 *
	 * @brief	Copy constructor.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	f	The Constraint &amp; to process.
	 **************************************************************************************************/

	Constraint(Constraint & f) = default; // Copy constructor

	/**********************************************************************************************//**
	 * @fn	Constraint& Constraint::operator=(int _value)
	 *
	 * @brief	Assignment operator overload to use the set function.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	_value	The value.
	 *
	 * @return	A shallow copy of this object.
	 **************************************************************************************************/

	Constraint& operator=(int _value)
	{
		set(_value);
		return *this;
	};

	/**********************************************************************************************//**
	 * @fn	operator Constraint::int()
	 *
	 * @brief	Allows implicit use of get via usage of operators. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @return	The result of the operation.
	 **************************************************************************************************/

	operator int(){
		return (int)get();
	};

	/**********************************************************************************************//**
	 * @fn	int Constraint::get()
	 *
	 * @brief	This function returns the evaluation of the constraint object. The function ensures that
	 * 			only valid values are returned. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @return	An int.
	 **************************************************************************************************/

	int get()
	{
		if (!Constraint_stack.empty()){
			this->dependantendantList.push_back(Constraint_stack.top());
		}
		if (!valid){
			this->valid = true;
			Constraint_stack.push(this);
			this->value = eval();
			Constraint_stack.pop();
		}
		return value;
	};

	/**********************************************************************************************//**
	 * @fn	void Constraint::set(int argument)
	 *
	 * @brief	This function sets the value of the object and invalidates any objects that may depend on 
	 * 			this object. Those objects can request the current value of this object at a later time 
	 * 			as they need it.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	argument	The argument to set.
	 **************************************************************************************************/

	void set(int argument)
	{
		value = argument;
		for (Constraint* dependant : dependantendantList){
			if (dependant->valid){
				dependant->invalidate();
			}
		}
	};

	/**********************************************************************************************//**
	 * @fn	void Constraint::invalidate()
	 *
	 * @brief	Invalidates this object.
	 *
	 * @author	David
	 * @date	4/27/2015
	 **************************************************************************************************/

	void invalidate(){
		valid = false;
		for (auto& dependant : dependantendantList){
			if (dependant->valid){
				dependant->invalidate();
			}
		}
		dependantendantList.clear();
	};

	/**********************************************************************************************//**
	 * @fn	void Constraint::setFormulaEx(Formula f)
	 *
	 * @brief	Sets the evaluation for the object to the argument formula. This function is often used 
	 * 			via the setFormula macro. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	f	The Formula to process.
	 **************************************************************************************************/

	void setFormulaEx(Formula f){
		eval = f;
		invalidate();
	};

//private:
	/** @brief	The evaluation formula. */
	Formula eval;
	/** @brief	The value retained by the constraint object */
	int value;
	/** @brief	List of dependantendants. */
	vector<Constraint *> dependantendantList;
};

stack<Constraint *> Constraint::Constraint_stack;

#endif // ___Constraint___
