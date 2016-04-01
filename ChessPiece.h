#include <vector>
#include <iostream>
#include <cmath>
#include "cinder/app/MouseEvent.h"
#include "cinder/cairo/Cairo.h"
#include "../vc2013/GraphicalObject.h"
#include "../vc2013/GlobalEnums.h"
#include "cinder/ImageIo.h"




class ChessPiece : public GraphicalObject
{
public:
	ChessPiece(int x, int y, int width, int height, pieceType pieceType, Locations location, team Team)
	{
		SetWidth(width);
		SetHeight(height);
		SetTopLeftBoxPoint(x, y);
		SetCenterBoxPoint();
		type = pieceType;
		loc = location;
		team = Team;
		setTexture();
	}
	void Render(cairo::Context &ctx);
	void RevertToPreviousTopLeft() { SetTopLeftBoxPoint(previousTopLeftPoint); isSelected = false; };
	void FocusEvent(MouseEvent event);
	void UnfocusEvent(MouseEvent event);
	Locations GetLocation() { return loc; };
	void SetLocation(Locations location);

private:
	void setTexture();
	Surface surface;
	pieceType type;
	Locations loc;
	team team;
	Colorf getColor(Surface32f surface, Vec2i pixel);
	cinder::Vec2f previousTopLeftPoint;


protected:
	

};

