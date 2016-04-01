#ifndef _CBVM_
#define _CBVM_


#include "../vc2013/BoardSquare.h"
#include "../vc2013/GameLogic.h"
#include "cinder/cairo/Cairo.h"
#include <iostream>




class ChessBoardViewManager
{
public:
	static ChessBoardViewManager &GetInstance();
	void Draw(cairo::Context &ctx);
	cinder::Vec2f GetTopLeftBoxPointByLocation(Locations loc);
	Locations GetSquareLocation(int x, int y);
	void UpdateValidMoves(Locations loc);
	void ClearMoves();
	void MouseDown(MouseEvent event)
	{
		Vec2f point;
		point.x = (float)event.getX();
		point.y = (float)event.getY();
		bool correctSQ = false;
		for (BoardSquare sq : squares)
		{
			correctSQ = sq.IsPointInsideBoundary(point);
			if (correctSQ)
			{
				return sq.FocusEvent(event);
			}
		}
	}

private:
	ChessBoardViewManager();
	~ChessBoardViewManager(){};
	ChessBoardViewManager(const ChessBoardViewManager &){};
	const ChessBoardViewManager &operator =(const ChessBoardViewManager &);
	list<BoardSquare> squares;
	GameLogic &Logic = GameLogic::GetInstance();
	vector<Locations> ValidMoves;
};



ChessBoardViewManager &ChessBoardViewManager::GetInstance()
{
	static ChessBoardViewManager instance;
	return instance;
}

ChessBoardViewManager::ChessBoardViewManager()
{
	Locations loc;

	int x = 0;
	int y = 700;
	int width = 100;
	int height = 100;
	//BoardSquare sq = BoardSquare(x, y, width, height, White, a1);
	int colorCount = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			loc = Logic.GetLocation(j, i);
			if ((colorCount % 2) == 0)
			{
				squares.push_back(BoardSquare(x, y, width, height, White, loc));
			}
			else
			{
				squares.push_back(BoardSquare(x, y, width, height, Black, loc));
			}
			x += width;
			colorCount++;
		}
		x = 0;
		y -= height;
		colorCount++;
	}

}

void ChessBoardViewManager::Draw(cairo::Context &ctx)
{
	for (BoardSquare sq : squares)
	{
		sq.Render(ctx);
	}
}

cinder::Vec2f ChessBoardViewManager::GetTopLeftBoxPointByLocation(Locations loc)
{
	Locations tloc;
	for (BoardSquare sq : squares)
	{
		tloc = sq.GetLocation();
		if (tloc == loc)
		{
			return sq.GetTopLeftBoxPoint();
		}
	}
	Vec2f x;
	return x;
}

Locations ChessBoardViewManager::GetSquareLocation(int x, int y)
{
	Vec2f point;
	point.x = (float)x;
	point.y = (float)y;
	bool correctSQ = false;
	for (BoardSquare sq : squares)
	{
		correctSQ = sq.IsPointInsideBoundary(point);
		if (correctSQ)
		{
			return sq.GetLocation();
		}
	}
	return invalid;
}

void ChessBoardViewManager::UpdateValidMoves(Locations loc)
{
	Locations tloc;
	for (BoardSquare sq : squares)
	{
		tloc = sq.GetLocation();
		if (tloc == loc)
		{
			cout << "Setting " << LocationsToString(sq.GetLocation()) << " constraint." << endl;
			sq.SetConstraint(1);
			
		}
	}
}

void ChessBoardViewManager::ClearMoves()
{
	cout << "Clearing Moves" << endl;
	for (BoardSquare sq : squares)
	{
		sq.SetConstraint(0);
	}
}

#endif 