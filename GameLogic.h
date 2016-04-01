#ifndef _GameLogic_
#define _GameLogic_

#include <vector>
#include <iostream>
#include <cmath>
#include <memory>
#include "../vc2013/GlobalEnums.h"
//#include "../vc2013/ChessBoardViewManager.h"


using namespace std;

class ChessPieceModel
{
public:
	ChessPieceModel(pieceType Type, team Team)
	{
		type = Type;
		team = Team;
	}
	pieceType GetType() { return type; }
	team GetTeam() { return team; }

private:
	pieceType type;
	team team;
};

class BoardSquareModel
{
public:
	BoardSquareModel(){ isOccupied = false; }
	bool IsOccupied() { return isOccupied; }

	void MoveTo(ChessPieceModel p) { piece = p; isOccupied = true; }
	void MoveAway()
	{
		isOccupied = false;
		piece = ChessPieceModel(Invalid, Neutral);
	}
	ChessPieceModel GetPiece() { return piece; }
	bool Capture(ChessPieceModel p)
	{
		if (!isOccupied)
		{
			return false;
		}
		piece = p;
		return true;
	}

	team GetTeam() { return piece.GetTeam(); }

private:
	bool isOccupied;
	ChessPieceModel piece = ChessPieceModel(Invalid, Neutral);
	
};

class GameLogic
{
public:
	static GameLogic &GetInstance() { static GameLogic instance; return instance; };
	
	Locations GetLocation(int x, int y);

	int GetLocX(Locations loc);
	int GetLocY(Locations loc);

	bool AttemptMove(Locations origin, Locations destination);

	team WhosTurnIsIt() { return playersTurn; };

	void FindAvailableMoves(std::vector<Locations> &validMoves, Locations origin);
	void PrintBoard();
	void NewGame();
private:

	GameLogic();
	~GameLogic(){};
	GameLogic(const GameLogic &){};
	const GameLogic &operator =(const GameLogic &);
	ResultOfMove IsKingInCheck(team colorOfKing);
	bool canThisPeiceMakeThisMove(Locations origin, Locations destination);
	ResultOfMove checkForCheckandMove(int Ox, int Oy, int Dx, int Dy);
	
	bool setSquare(ChessPieceModel p, Locations loc);
	bool IsSquareOccupied(Locations loc);
	bool IsSquareOccupied(int x, int y);

	bool tryKing(Locations origin, Locations destination);
	bool tryQueen(Locations origin, Locations destination);
	bool tryKnight(Locations origin, Locations destination);
	bool tryBishiop(Locations origin, Locations destination);
	bool tryRook(Locations origin, Locations destination);
	bool tryPawn(Locations origin, Locations destination);

	ResultOfMove movePawn(Locations origin, Locations destination);
	ResultOfMove moveRook(Locations origin, Locations destination);
	ResultOfMove moveBishiop(Locations origin, Locations destination);
	ResultOfMove moveKnight(Locations origin, Locations destination);
	ResultOfMove moveQueen(Locations origin, Locations destination);
	ResultOfMove moveKing(Locations origin, Locations destination);

	bool EvaluateMovePawn(Locations origin, Locations destination);
	bool EvaluateMoveRook(Locations origin, Locations destination);
	bool EvaluateMoveBishiop(Locations origin, Locations destination);
	bool EvaluateMoveKnight(Locations origin, Locations destination);
	bool EvaluateMoveQueen(Locations origin, Locations destination);
	bool EvaluateMoveKing(Locations origin, Locations destination);

	bool FindPotentialMove(Locations origin, Locations destination);
	
	team WhatTeamOwnsSquare(Locations loc);
	ChessPieceModel GetWhatIsInSquare(Locations loc);

	team playersTurn = White;
	BoardSquareModel board[8][8];
	Locations whiteKingLoc;
	Locations blackKingLoc;

};





#endif 