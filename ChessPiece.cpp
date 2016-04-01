#include <vector>
#include <iostream>
#include <cmath>
#include "cinder/app/AppNative.h"
#include "cinder/cairo/Cairo.h"
#include "cinder/Rand.h"
#include "../vc2013/ChessPiece.h"



void ChessPiece::Render(cairo::Context &ctx)
{

	/*if (team = Black)
	{
		ctx.setSourceRgb(0.3, 0.3, 0.3);
	}
	else
	{
		ctx.setSourceRgb(0.7, 0.7, 0.7);
	}

	switch (type)
	{
	case King:		
		ctx.showText("King");
		break;
	case Queen:
		ctx.showText("Queen");
		break;
	case Knight:
		ctx.showText("Knight");
		break;
	case Bishop:
		ctx.showText("Bishop");
		break;
	case Rook:
		ctx.showText("Rook");
		break;
	case Pawn:
		ctx.showText("Pawn");
		break;
	case Invalid:
		break;
	default:
		break;
	}*/

	int verticalOffset;
	int horizontalOffset;

	switch (type)
	{
	case King:
		horizontalOffset = 37;
		verticalOffset = 17;
		break;
	case Queen:
		horizontalOffset = 35;
		verticalOffset = 17;
		break;
	case Knight:
		horizontalOffset = 26;
		verticalOffset = 17;
		break;
	case Bishop:
		horizontalOffset = 33;
		verticalOffset = 17;
		break;
	case Rook:
		horizontalOffset = 27;
		verticalOffset = 17;
		break;
	case Pawn:
		horizontalOffset = 26;
		verticalOffset = 17;
		break;
	case Invalid:
		break;
	default:
		break;
	}


	cinder::Vec2f TLPoint = GetTopLeftBoxPoint();

	horizontalOffset += (int)TLPoint.x;
	verticalOffset += (int)TLPoint.y;

	ctx.translate(horizontalOffset, verticalOffset);
	
	cinder::cairo::SurfaceImage siPiece(surface);
	cinder::cairo::SurfaceBase* sb = &siPiece;

	ctx.setSourceSurface(siPiece, 0, 0);
	ctx.maskSurface(sb, 0, 0);


	ctx.stroke();

	ctx.translate(-horizontalOffset, -verticalOffset);
}

Colorf ChessPiece::getColor(Surface32f surface, Vec2i pixel)
{
	float r = *surface.getDataRed(pixel);
	float g = *surface.getDataGreen(pixel);
	float b = *surface.getDataBlue(pixel);
	return Colorf(r, g, b);
}

void ChessPiece::setTexture()
{
	switch (type)
	{
	case King:
		if (team == Black)
		{
			surface = loadImage("../resources/Black_King.png");
		}
		else
		{
			surface = loadImage("../resources/White_King.png");
		}	
		break;
	case Queen:
		if (team == Black)
		{
			surface = loadImage("../resources/Black_Queen.png");
		}
		else
		{
			surface = loadImage("../resources/White_Queen.png");
		}
		break;
	case Knight:
		if (team == Black)
		{
			surface = loadImage("../resources/Black_Knight.png");
		}
		else
		{
			surface = loadImage("../resources/White_Knight.png");
		}
		break;
	case Bishop:
		if (team == Black)
		{
			surface = loadImage("../resources/Black_Bishop.png");
		}
		else
		{
			surface = loadImage("../resources/White_Bishop.png");
		}
		break;
	case Rook:
		if (team == Black)
		{
			surface = loadImage("../resources/Black_Castle.png");
		}
		else
		{
			surface = loadImage("../resources/White_Castle.png");
		}
		break;
	case Pawn:
		if (team == Black)
		{
			surface = loadImage("../resources/Black_Pawn.png");
		}
		else
		{
			surface = loadImage("../resources/White_Pawn.png");
		}
		break;
	default:
		break;
	}
}

void ChessPiece::FocusEvent(MouseEvent event)
{
	isSelected = true;

	//cout << "mouse X: " << event.getX() << endl;
	//cout << "mouse Y: " << event.getY() << endl;
	cout << "Focus event on: " << LocationsToString(loc) << endl;

	Vec2f temp = GetCenterBoxPoint();

	//cout << "Center point of selected peice X: " << temp.x << " Y: " << temp.y << endl;

	previousTopLeftPoint = GetTopLeftBoxPoint();
	SetMousePoint(event.getX(), event.getY());

}

void ChessPiece::SetLocation(Locations location)
{ 
	loc = location; 

}

void ChessPiece::UnfocusEvent(MouseEvent event)
{
	isSelected = false;
}