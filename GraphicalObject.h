#ifndef _GraphicalObjectApp_
#define _GraphicalObjectApp_

#include <vector>
#include <iostream>
#include <cmath>
#include "cinder/app/MouseEvent.h"
#include "cinder/cairo/Cairo.h"
#include "../vc2013/GlobalEnums.h"
#include "cinder/ImageIo.h"



using namespace ci;
using namespace ci::app;
using namespace std;

/**********************************************************************************************//**
 * @class	GraphicalObject
 *
 * @brief	A abstract base class for the creation of graphical objects. Graphical objects have a 
 * 			bounding box and functions to determine if events or points collide with the graphical 
 * 			object.
 * 			
 *			By default graphical objects can be moved. This may be removed via override if desired. 
 *			Users will need to overwrite several functions including functionality for rendering the object. 
 *
 * @author	David
 * @date	4/27/2015
 **************************************************************************************************/

class GraphicalObject {
public:

	/**********************************************************************************************//**
	 * @fn	virtual GraphicalObject::~GraphicalObject()
	 *
	 * @brief	Destructor. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 **************************************************************************************************/

	virtual ~GraphicalObject(){};

	/**********************************************************************************************//**
	 * @fn	GraphicalObject::GraphicalObject()
	 *
	 * @brief	Default constructor. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 **************************************************************************************************/

	GraphicalObject(){};

	/**********************************************************************************************//**
	 * @fn	bool GraphicalObject::IsEventInsideBoundary(MouseEvent event);
	 *
	 * @brief	This function determines if the event occurs inside the boundary of the graphical object.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	event	The event.
	 *
	 * @return	true if event inside boundary, false if not.
	 **************************************************************************************************/

	bool IsEventInsideBoundary(MouseEvent event);

	/**********************************************************************************************//**
	 * @fn	bool GraphicalObject::IsPointInsideBoundary(cinder::Vec2f point);
	 *
	 * @brief	This function determines if the point is inside the boundary of the graphical object.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	point	The point.
	 *
	 * @return	true if point inside boundary, false if not.
	 **************************************************************************************************/

	bool IsPointInsideBoundary(cinder::Vec2f point);

	/**********************************************************************************************//**
	 * @fn	bool GraphicalObject::IsObjectSelected()
	 *
	 * @brief	Query if this object is selected.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @return	true if object selected, false if not.
	 **************************************************************************************************/

	bool IsObjectSelected() { return isSelected; };

	/**********************************************************************************************//**
	 * @fn	virtual void GraphicalObject::Render(cairo::Context &ctx) = 0;
	 *
	 * @brief	Renders the graphical object. This function will need to be inplemented by any subclass
	 * 			so that it renders the object to the screen.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param [in,out]	ctx	The context.
	 **************************************************************************************************/

	virtual void Render(cairo::Context &ctx) = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void GraphicalObject::FocusEvent(MouseEvent event) = 0;
	 *
	 * @brief	This event can be triggered when there is a mouse event. It must be implemented by subclasses 
	 * 			too any desired functionality. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	event	The event.
	 **************************************************************************************************/

	virtual void FocusEvent(MouseEvent event) = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void GraphicalObject::UnfocusEvent(MouseEvent event) = 0;
	 *
	 * @brief	This event can be triggered when the graphical object goes out of focus. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	event	The event.
	 **************************************************************************************************/

	virtual void UnfocusEvent(MouseEvent event) = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void GraphicalObject::MoveEvent(int x, int y)
	 *
	 * @brief	This event is used to move the graphical object. The window has the origin at the top left. 
	 * 			Positive X values will move the object right on the screen. Positive Y values will move 
	 * 			the object down the screen. Negative values will do the oposite. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	x	The x coordinate.
	 * @param	y	The y coordinate.
	 **************************************************************************************************/

	virtual void MoveEvent(int x, int y);

	/**********************************************************************************************//**
	 * @fn	virtual void GraphicalObject::MouseDrag(MouseEvent event);
	 *
	 * @brief	This event handles Mouse Drag Events. By default the function moves the graphical object
	 * 			by the same amount the mouse has moved since the last time the function was called. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	event	The event.
	 **************************************************************************************************/

	virtual void MouseDrag(MouseEvent event);

	/**********************************************************************************************//**
	 * @fn	int GraphicalObject::GetWidth();
	 *
	 * @brief	Gets the width of the graphical object.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @return	The width.
	 **************************************************************************************************/

	int GetWidth();

	/**********************************************************************************************//**
	 * @fn	int GraphicalObject::GetHeight();
	 *
	 * @brief	Gets the height of the graphical object.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @return	The height.
	 **************************************************************************************************/

	int GetHeight();

	/**********************************************************************************************//**
	 * @fn	cinder::Vec2f GraphicalObject::GetCenterBoxPoint();
	 *
	 * @brief	This function returns a point that is exactly in the center of the graphical object bounding box.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @return	The center box point.
	 **************************************************************************************************/

	cinder::Vec2f GetCenterBoxPoint();

	/**********************************************************************************************//**
	 * @fn	cinder::Vec2f GraphicalObject::GetTopLeftBoxPoint();
	 *
	 * @brief	This function returns a point that is at the top left point of the bounding box.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @return	The top left box point.
	 **************************************************************************************************/

	cinder::Vec2f GetTopLeftBoxPoint();

	/**********************************************************************************************//**
	 * @fn	void GraphicalObject::SetTopLeftBoxPoint(cinder::Vec2f p)
	 *
	 * @brief	This function allows the top left point of the bounding box to be changed. This will result
	 * 			in the graphical object moving on the screen to reflect the changed anchor point. 
	 * 			
	 *			The function also changes the center box point to reflect the movement of the top left point.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	p	The cinder::Vec2f point value to process.
	 **************************************************************************************************/

	void SetTopLeftBoxPoint(cinder::Vec2f p);

	/**********************************************************************************************//**
	 * @fn	void GraphicalObject::SetTopLeftBoxPoint(int x, int y)
	 *
	 * @brief	This function allows the top left point of the bounding box to be changed. This will result
	 * 			in the graphical object moving on the screen to reflect the changed anchor point. 
	 * 			
	 *			This is accomplished by providing x and y coordinates for the API to create a point to use
	 *			as the next anchor. 
	 *			
	 *			The function also changes the center box point to reflect the movement of the top left point.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	x	The x coordinate.
	 * @param	y	The y coordinate.
	 **************************************************************************************************/

	void SetTopLeftBoxPoint(int x, int y);

private:
	/** @brief	The width. */
	int width;
	/** @brief	The height. */
	int height;
	/** @brief	The top left box point. */
	cinder::Vec2f topLeftBoxPoint;
	/** @brief	The center box point. */
	cinder::Vec2f centerBoxPoint;
	/** @brief	The mouse point. */
	cinder::Vec2f mousePoint;

	


protected:
	/** @brief	true if this object is selected. */
	bool isSelected = false;

	/**********************************************************************************************//**
	 * @fn	void GraphicalObject::SetWidth(int Width)
	 *
	 * @brief	This function allows sub classes too set the width value without allowing this value to be
	 * 			public. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	Width	The width.
	 **************************************************************************************************/

	void SetWidth(int Width) { width = Width; };

	/**********************************************************************************************//**
	 * @fn	void GraphicalObject::SetHeight(int Height)
	 *
	 * @brief	This function allows sub classes too set the height value without allowing this value to be
	 * 			public. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	Height	The height.
	 **************************************************************************************************/

	void SetHeight(int Height) { height = Height; };

	/**********************************************************************************************//**
	 * @fn	void GraphicalObject::SetCenterBoxPoint()
	 *
	 * @brief	This function updates the center box point so that it is consistent with the position of the
	 * 			top left box point. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 **************************************************************************************************/

	void SetCenterBoxPoint();

	/**********************************************************************************************//**
	 * @fn	void GraphicalObject::SetMousePoint(cinder::Vec2f mp)
	 *
	 * @brief	Sets mouse point by accepting a point value.
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	mp	The mp.
	 **************************************************************************************************/

	void SetMousePoint(cinder::Vec2f mp) {mousePoint = mp; }

	/**********************************************************************************************//**
	 * @fn	void GraphicalObject::SetMousePoint(int x, int y)
	 *
	 * @brief	creates a point from x and y coordinates to use as the mouse point. 
	 *
	 * @author	David
	 * @date	4/27/2015
	 *
	 * @param	x	The x coordinate.
	 * @param	y	The y coordinate.
	 **************************************************************************************************/

	void SetMousePoint(int x, int y) { mousePoint.x = (float)x; mousePoint.y = (float)y; }

};





#endif /*_GraphicalObjectApp_*/