#include "../vc2013/GraphicalObject.h"


using namespace ci;
using namespace ci::app;
using namespace std;



bool GraphicalObject::IsEventInsideBoundary(MouseEvent event)
{

	int X = (int)topLeftBoxPoint.x;
	int Y = (int)topLeftBoxPoint.y;


	// if Event exists within the graphical objects bounding box return true, else false.
	if ((event.getX() >= X) && (event.getX() <= X + width))
	{
		if ((event.getY() >= Y) && (event.getY() <= Y + height))
		{
			//cout << "Top left point of selected peice x: " << X << " Y: " << Y << endl;
			return true;
		}
	}

	return false;
}

bool GraphicalObject::IsPointInsideBoundary(cinder::Vec2f point)
{
	float X = topLeftBoxPoint.x;
	float Y = topLeftBoxPoint.y;
	// if Event exists within the graphical objects bounding box return true, else false.
	if ((point.x >= X) && (point.x <= X + width))
	{
		if ((point.y >= Y) && (point.y <= Y + height))
		{
			return true;
		}
	}

	return false;
}

int GraphicalObject::GetWidth()
{
	return width;
}

int GraphicalObject::GetHeight()
{
	return height;
}

cinder::Vec2f GraphicalObject::GetCenterBoxPoint()
{
	return centerBoxPoint;
}

cinder::Vec2f GraphicalObject::GetTopLeftBoxPoint()
{
	return topLeftBoxPoint;
}



void GraphicalObject::MoveEvent(int x, int y)
{ 
	topLeftBoxPoint.x += x; 
	topLeftBoxPoint.y += y; 
	centerBoxPoint.x += x; 
	centerBoxPoint.y += y; 
};

void GraphicalObject::MouseDrag(MouseEvent event)
{
	float oldMx = mousePoint.x;
	float oldMy = mousePoint.y;

	float newMx =(float) event.getX();
	float newMy = (float)event.getY();

	float diffX = newMx - oldMx;
	float diffY = newMy - oldMy;

	topLeftBoxPoint.x += diffX; 
	topLeftBoxPoint.y += diffY;

	SetMousePoint(newMx, newMy);
	SetCenterBoxPoint();

}

void GraphicalObject::SetTopLeftBoxPoint(cinder::Vec2f p) 
{ 
	topLeftBoxPoint.x = p.x; 
	topLeftBoxPoint.y = p.y;  
	SetCenterBoxPoint(); 
}

void GraphicalObject::SetTopLeftBoxPoint(int x, int y)
{
	topLeftBoxPoint.x = (float)x; 
	topLeftBoxPoint.y = (float)y; 
	SetCenterBoxPoint();
}

void GraphicalObject::SetCenterBoxPoint() 
{ 
	centerBoxPoint.x = topLeftBoxPoint.x + (width / 2); 
	centerBoxPoint.y = topLeftBoxPoint.y + (height / 2); 
};