#ifndef _BoardSquareView_
#define _BoardSquareView_

#include "../vc2013/GraphicalObject.h"
#include "../vc2013/Constraint.h"

//unsigned counter = 0;

class BoardSquare : public GraphicalObject
{
public:
	BoardSquare(int x, int y, int width, int height, team teamColor, Locations location) //: constraint(counter++)
	{
		SetWidth(width);
		SetHeight(height);
		SetTopLeftBoxPoint(x, y);
		SetCenterBoxPoint();
		if (teamColor == Black)
		{
			isBlack = true;
		}
		else
		{
			isBlack = false;
		}
		loc = location;
		
		constraint = new Constraint(0);
		SetConstraint(0);

	}
	//~BoardSquare() {  };
	void Render(cairo::Context &ctx) override
	{

		int val = constraint->get();

		//cout << "The Value of the constraint is: " << val << endl;
		

		if (val != 0)
		{
			//cout << "constraint is not zero" << endl;
			ctx.setSourceRgb(0.3, 0.9, 0.3);
		}
		else if (isBlack)
		{
			ctx.setSourceRgb(0.6, 0.6, 0.6);
		}
		else 
		{

			ctx.setSourceRgb(0.9, 0.9, 0.9);
		}

		

		cinder::Vec2f tlp = GetTopLeftBoxPoint();
		float x = tlp.x;
		Rectf sq(tlp.x, tlp.y, tlp.x + GetWidth(), tlp.y + GetHeight());
		ctx.rectangle(sq);
		ctx.fill();
		ctx.stroke();
	}
	Locations GetLocation() { return loc; };
	void MoveEvent(int x, int y) override { return; };
	void FocusEvent(MouseEvent event) { cout << "Address of  constraint is: " << ios::hex << (&constraint) 
		                                     << "(" << constraint->get() << ")" << endl 
											 << "Address: " << (&loc) << "  " << LocationsToString(loc) << endl; return; };
	void MouseDrag(MouseEvent event) { return; };
	void UnfocusEvent(MouseEvent event) { return; };
	void SetConstraint(int v) 
	{
		if (v != 0)
		{
			constraint->setFormula(1);
			cout << "The Value of the constraint is: " << constraint->get() << endl;
			cout << "Address of  constraint is: " << ((void*)&constraint) << endl;
			cout << "The location of the constraint being modified: " << LocationsToString(loc) << endl;
		}
		else
		{
			constraint->setFormula(0);
		}
		
	};
	void SetColorOveride(int o) { colorOveride = o; };
	void ResetColorOveride() { colorOveride = 0; }

private:
	bool isBlack;
	Locations loc;
	Constraint *constraint;
	int colorOveride = 0;
	
	
protected:
	

};


#endif 