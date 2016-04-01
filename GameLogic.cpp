#include "../vc2013/GameLogic.h"

GameLogic::GameLogic()
{
	NewGame();
}

void GameLogic::NewGame()
{

	ChessPieceModel BlackRook = ChessPieceModel(Rook, Black);
	ChessPieceModel BlackKnight = ChessPieceModel(Knight, Black);
	ChessPieceModel BlackBishiop = ChessPieceModel(Bishop, Black);
	ChessPieceModel BlackKing = ChessPieceModel(King, Black);
	ChessPieceModel BlackQueen = ChessPieceModel(Queen, Black);
	ChessPieceModel BlackPawn = ChessPieceModel(Pawn, Black);

	ChessPieceModel WhiteRook = ChessPieceModel(Rook, White);
	ChessPieceModel WhiteKnight = ChessPieceModel(Knight, White);
	ChessPieceModel WhiteBishiop = ChessPieceModel(Bishop, White);
	ChessPieceModel WhiteKing = ChessPieceModel(King, White);
	ChessPieceModel WhiteQueen = ChessPieceModel(Queen, White);
	ChessPieceModel WhitePawn = ChessPieceModel(Pawn, White);


	setSquare(BlackRook, a8);
	setSquare(BlackKnight, b8);
	setSquare(BlackBishiop, c8);
	setSquare(BlackKing, e8);
	blackKingLoc = e8;
	setSquare(BlackQueen, d8);
	setSquare(BlackBishiop, f8);
	setSquare(BlackKnight, g8);
	setSquare(BlackRook, h8);

	setSquare(BlackPawn, a7);
	setSquare(BlackPawn, b7);
	setSquare(BlackPawn, c7);
	setSquare(BlackPawn, d7);
	setSquare(BlackPawn, e7);
	setSquare(BlackPawn, f7);
	setSquare(BlackPawn, g7);
	setSquare(BlackPawn, h7);

	setSquare(WhiteRook, a1);
	setSquare(WhiteKnight, b1);
	setSquare(WhiteBishiop, c1);
	setSquare(WhiteKing, e1);
	whiteKingLoc = e1;
	setSquare(WhiteQueen, d1);
	setSquare(WhiteBishiop, f1);
	setSquare(WhiteKnight, g1);
	setSquare(WhiteRook, h1);

	setSquare(WhitePawn, a2);
	setSquare(WhitePawn, b2);
	setSquare(WhitePawn, c2);
	setSquare(WhitePawn, d2);
	setSquare(WhitePawn, e2);
	setSquare(WhitePawn, f2);
	setSquare(WhitePawn, g2);
	setSquare(WhitePawn, h2);



}

int GameLogic::GetLocX(Locations loc)
{
	switch (loc)
	{
	case a1:
	case a2:
	case a3:
	case a4:
	case a5:
	case a6:
	case a7:
	case a8:
		return 0;
	case b1:
	case b2:
	case b3:
	case b4:
	case b5:
	case b6:
	case b7:
	case b8:
		return 1;
	case c1:
	case c2:
	case c3:
	case c4:
	case c5:
	case c6:
	case c7:
	case c8:
		return 2;
	case d1:
	case d2:
	case d3:
	case d4:
	case d5:
	case d6:
	case d7:
	case d8:
		return 3;
	case e1:
	case e2:
	case e3:
	case e4:
	case e5:
	case e6:
	case e7:
	case e8:
		return 4;
	case f1:
	case f2:
	case f3:
	case f4:
	case f5:
	case f6:
	case f7:
	case f8:
		return 5;
	case g1:
	case g2:
	case g3:
	case g4:
	case g5:
	case g6:
	case g7:
	case g8:
		return 6;
	case h1:
	case h2:
	case h3:
	case h4:
	case h5:
	case h6:
	case h7:
	case h8:
		return 7;
	case invalid:
		break;
	default:
		break;
	}

	return 0;
}

int GameLogic::GetLocY(Locations loc)
{
	switch (loc)
	{
	case a1:
	case b1:
	case c1:
	case d1:
	case e1:
	case f1:
	case g1:
	case h1:
		return 0;

	case a2:
	case b2:
	case c2:
	case d2:
	case e2:
	case f2:
	case g2:
	case h2:
		return 1;

	case a3:
	case b3:
	case c3:
	case d3:
	case e3:
	case f3:
	case g3:
	case h3:
		return 2;

	case a4:
	case b4:
	case c4:
	case d4:
	case e4:
	case f4:
	case g4:
	case h4:
		return 3;

	case a5:
	case b5:
	case c5:
	case d5:
	case e5:
	case f5:
	case g5:
	case h5:
		return 4;

	case a6:
	case b6:
	case c6:
	case d6:
	case e6:
	case f6:
	case g6:
	case h6:
		return 5;

	case a7:
	case b7:
	case c7:
	case d7:
	case e7:
	case f7:
	case g7:
	case h7:
		return 6;

	case a8:
	case b8:
	case c8:
	case d8:
	case e8:
	case f8:
	case g8:
	case h8:
		return 7;
	case invalid:
		break;
	default:
		break;
	}

	return 0;
}

bool GameLogic::setSquare(ChessPieceModel p, Locations loc)
{
	int x = GetLocX(loc);
	int y = GetLocY(loc);

	board[x][y].MoveTo(p);
	return true;

}

bool GameLogic::IsSquareOccupied(Locations loc)
{
	int x = GetLocX(loc);
	int y = GetLocY(loc);

	return board[x][y].IsOccupied();
}

bool GameLogic::IsSquareOccupied(int x, int y)
{
	return board[x][y].IsOccupied();
}

team GameLogic::WhatTeamOwnsSquare(Locations loc)
{
	int x = GetLocX(loc);
	int y = GetLocY(loc);

	ChessPieceModel p = board[x][y].GetPiece();
	return p.GetTeam();
}

ChessPieceModel GameLogic::GetWhatIsInSquare(Locations loc)
{
	int x = GetLocX(loc);
	int y = GetLocY(loc);

	return board[x][y].GetPiece();
}

Locations GameLogic::GetLocation(int x, int y)
{
	switch (x)
	{
	case 0:
		switch (y)
		{
		case 0:
			return a1;
		case 1:
			return a2;
		case 2:
			return a3;
		case 3:
			return a4;
		case 4:
			return a5;
		case 5:
			return a6;
		case 6:
			return a7;
		case 7:
			return a8;
		default:
			return invalid;
		}
	case 1:
		switch (y)
		{
		case 0:
			return b1;
		case 1:
			return b2;
		case 2:
			return b3;
		case 3:
			return b4;
		case 4:
			return b5;
		case 5:
			return b6;
		case 6:
			return b7;
		case 7:
			return b8;
		default:
			return invalid;

		}
	case 2:
		switch (y)
		{
		case 0:
			return c1;
		case 1:
			return c2;
		case 2:
			return c3;
		case 3:
			return c4;
		case 4:
			return c5;
		case 5:
			return c6;
		case 6:
			return c7;
		case 7:
			return c8;
		default:
			return invalid;

		}
	case 3:
		switch (y)
		{
		case 0:
			return d1;
		case 1:
			return d2;
		case 2:
			return d3;
		case 3:
			return d4;
		case 4:
			return d5;
		case 5:
			return d6;
		case 6:
			return d7;
		case 7:
			return d8;
		default:
			return invalid;

		}
	case 4:
		switch (y)
		{
		case 0:
			return e1;
		case 1:
			return e2;
		case 2:
			return e3;
		case 3:
			return e4;
		case 4:
			return e5;
		case 5:
			return e6;
		case 6:
			return e7;
		case 7:
			return e8;
		default:
			return invalid;

		}
	case 5:
		switch (y)
		{
		case 0:
			return f1;
		case 1:
			return f2;
		case 2:
			return f3;
		case 3:
			return f4;
		case 4:
			return f5;
		case 5:
			return f6;
		case 6:
			return f7;
		case 7:
			return f8;
		default:
			return invalid;

		};
	case 6:
		switch (y)
		{
		case 0:
			return g1;
		case 1:
			return g2;
		case 2:
			return g3;
		case 3:
			return g4;
		case 4:
			return g5;
		case 5:
			return g6;
		case 6:
			return g7;
		case 7:
			return g8;
		default:
			return invalid;

		}
	case 7:
		switch (y)
		{
		case 0:
			return h1;
		case 1:
			return h2;
		case 2:
			return h3;
		case 3:
			return h4;
		case 4:
			return h5;
		case 5:
			return h6;
		case 6:
			return h7;
		case 7:
			return h8;
		default:
			return invalid;

		}
	default:
		return invalid;
	}
}

bool GameLogic::AttemptMove(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);


	team team = board[Ox][Oy].GetTeam();

	if (team != playersTurn)
	{
		return false;
	}

	bool originOccupied = board[Ox][Oy].IsOccupied();

	if (!originOccupied)
	{
		return false;
	}

	ChessPieceModel pieceToMove = GetWhatIsInSquare(origin);

	ResultOfMove successful = Failure;

	pieceType type = pieceToMove.GetType();

	switch (type)
	{
	case King:
		successful = moveKing(origin, destination);
		break;
	case Queen:
		successful = moveQueen(origin, destination);
		break;
	case Knight:
		successful = moveKnight(origin, destination);
		break;
	case Bishop:
		successful = moveBishiop(origin, destination);
		break;
	case Rook:
		successful = moveRook(origin, destination);
		break;
	case Pawn:
		successful = movePawn(origin, destination);
		break;
	case Invalid:
		successful = Failure;
		break;
	default:
		successful = Failure;
		break;
	}

	if ((successful == EnemyInCheck) || (successful == Success))
	{
		if (playersTurn == Black)
		{
			playersTurn = White;
		}
		else
		{
			playersTurn = Black;
		}
	}

	if ((successful == EnemyInCheck) || (successful == Success))
		return true;
	else
		return false;

}

ResultOfMove GameLogic::IsKingInCheck(team colorOfKing)
{
	ResultOfMove result = Success;
	Locations locationOfKing;

	team attackingColor;

	vector<Locations> listOfPiecesThreateningTheKing;

	if (colorOfKing == Black)
	{
		attackingColor = White;
		locationOfKing = blackKingLoc;
	}
	else
	{
		attackingColor = Black;
		locationOfKing = whiteKingLoc;
	}

	// traverse board and see if any opposing peices can attack the king.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j].IsOccupied())
			{
				if (board[i][j].GetTeam() == attackingColor)
				{
					if (canThisPeiceMakeThisMove(GetLocation(i, j), locationOfKing))
					{
						PrintBoard();
						listOfPiecesThreateningTheKing.push_back(GetLocation(i, j));
						result = EnemyInCheck;
					}
				}
			}
		}
	}

	for (Locations l : listOfPiecesThreateningTheKing)
	{
		cout << "The peice in location " << LocationsToString(l) << " is threatening the king." << endl;
	}

	return result;


}

bool GameLogic::canThisPeiceMakeThisMove(Locations origin, Locations destination)
{
	ChessPieceModel pieceToMove = GetWhatIsInSquare(origin);

	bool successful = false;

	pieceType type = pieceToMove.GetType();

	switch (type)
	{
	case King:
		successful = tryKing(origin, destination);
		break;
	case Queen:
		successful = tryQueen(origin, destination);
		break;
	case Knight:
		successful = tryKnight(origin, destination);
		break;
	case Bishop:
		successful = tryBishiop(origin, destination);
		break;
	case Rook:
		successful = tryRook(origin, destination);
		break;
	case Pawn:
		successful = tryPawn(origin, destination);
		break;
	case Invalid:
		successful = false;
		break;
	default:
		successful = false;
		break;
	}

	return successful;
}

ResultOfMove GameLogic::checkForCheckandMove(int Ox, int Oy, int Dx, int Dy)
{
	// Add checks for checkmate

	ChessPieceModel capturedPiece = ChessPieceModel(Invalid, Neutral);
	bool pieceWasCaptured = false;

	bool moveItselfValid = false;
	ResultOfMove stateOfCheck;


	ChessPieceModel pieceToMove = board[Ox][Oy].GetPiece();
	board[Ox][Oy].MoveAway();

	team MovingTeam = pieceToMove.GetTeam();
	team OpposingTeam;

	if (MovingTeam == Black)
	{
		OpposingTeam = White;
	}
	else
	{
		OpposingTeam = Black;
	}

	// Find locations of the kings.

	Locations locationOfMovingTeamsKing;
	Locations locationOfOpposingTeamsKing;

	if (MovingTeam == Black)
	{
		locationOfMovingTeamsKing = blackKingLoc;
		locationOfOpposingTeamsKing = whiteKingLoc;
	}
	else
	{
		locationOfMovingTeamsKing = whiteKingLoc;
		locationOfOpposingTeamsKing = blackKingLoc;
	}


	if (board[Dx][Dy].IsOccupied())
	{
		if (board[Dx][Dy].GetTeam() == MovingTeam)
		{
			return Failure;
		}

		capturedPiece = board[Dx][Dy].GetPiece();
		board[Dx][Dy].Capture(pieceToMove);
		moveItselfValid = true;
		pieceWasCaptured = true;
	}
	else
	{
		board[Dx][Dy].MoveTo(pieceToMove);
		moveItselfValid = true;
	}

	// If Move Is invalid don't waste time checking for check
	if (!moveItselfValid)
	{
		return Failure;
	}


	// Check to see if the move is invalid by putting a player in check
	stateOfCheck = IsKingInCheck(MovingTeam);

	if (stateOfCheck == EnemyInCheck)
	{
		pieceToMove = board[Dx][Dy].GetPiece();
		board[Dx][Dy].MoveAway();
		board[Ox][Oy].MoveTo(pieceToMove);

		if (pieceWasCaptured)
		{
			board[Dx][Dy].MoveTo(capturedPiece);
		}

		return Failure;
	}

	// check to see if the opposing king is in check or checkmate.
	return IsKingInCheck(OpposingTeam);
}

void GameLogic::FindAvailableMoves(std::vector<Locations> &validMoves, Locations origin)
{
	/*for (int i = 0; i < 65; i++)
	{
	Locations loc = (Locations)i;
	if (canThisPeiceMakeThisMove(origin, loc))
	{

	}
	}*/

	//ChessBoardViewManager & CBVM = ChessBoardViewManager::GetInstance();
	Locations debug;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			
			debug = GetLocation(i, j);
			if (debug == a3)
				debug = a3;

			if (FindPotentialMove(origin, GetLocation(i, j)))
			{
				validMoves.push_back(GetLocation(i, j));		
			}

		}
	}

}


bool GameLogic::tryKing(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	vector<Locations> list;

	Locations temporary;

	temporary = GetLocation((Ox + 1), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			return true;
		}
	}

	return false;
}
bool GameLogic::tryQueen(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	bool obsticleDownLeft = false;
	bool obsticleDownRight = false;
	bool obsticleUpLeft = false;
	bool obsticleUpRight = false;

	bool obsticleLeft = false;
	bool obsticleRight = false;
	bool obsticleUp = false;
	bool obsticleDown = false;

	team team = board[Ox][Oy].GetTeam();

	int x = Ox;
	int y = Oy;

	while (!obsticleDownLeft)
	{
		x--;
		y--;

		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleDownRight)
	{
		x++;
		y--;

		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpLeft)
	{
		x--;
		y++;

		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpRight)
	{
		x++;
		y++;

		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;
	// Look to the left of the rook for the correct move.
	while (!obsticleLeft)
	{
		x -= 1;
		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;

	while (!obsticleRight)
	{
		x += 1;
		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;

	// now check up

	while (!obsticleUp)
	{
		y += 1;
		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUp = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	y = Oy;

	while (!obsticleDown)
	{
		y -= 1;
		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDown = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	return false;
}
bool GameLogic::tryKnight(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();



	vector<Locations> list;

	Locations temporary;

	temporary = GetLocation((Ox + 1), (Oy - 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 2), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 2), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy + 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy + 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 2), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 2), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy - 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			return true;
		}
	}

	return false;
}
bool GameLogic::tryBishiop(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	bool obsticleDownLeft = false;
	bool obsticleDownRight = false;
	bool obsticleUpLeft = false;
	bool obsticleUpRight = false;

	team team = board[Ox][Oy].GetTeam();

	int x = Ox;
	int y = Oy;

	while (!obsticleDownLeft)
	{
		x--;
		y--;

		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleDownRight)
	{
		x++;
		y--;

		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpLeft)
	{
		x--;
		y++;

		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpRight)
	{
		x++;
		y++;

		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}


	return false;
}
bool GameLogic::tryRook(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	bool obsticleLeft = false;
	bool obsticleRight = false;
	bool obsticleUp = false;
	bool obsticleDown = false;


	int x = Ox;
	int y = Oy;
	// Look to the left of the rook for the correct move.
	while (!obsticleLeft)
	{
		x -= 1;
		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;

	while (!obsticleRight)
	{
		x += 1;
		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;

	// now check up

	while (!obsticleUp)
	{
		y += 1;
		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUp = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	y = Oy;

	while (!obsticleDown)
	{
		y -= 1;
		// We don't need to check off the edge of the board
		if ((x < 0) || (x > 7) || (y > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDown = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	return false;
}
bool GameLogic::tryPawn(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	vector<Locations> list;

	Locations temporary;

	// black moves down, white moves up.



	switch (team)
	{
	case Black:

		// capture left
		temporary = GetLocation((Ox - 1), (Oy - 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}

		// capture right
		temporary = GetLocation((Ox + 1), (Oy - 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}


		break;

	case White:


		// capture left
		temporary = GetLocation((Ox - 1), (Oy + 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}

		// capture right
		temporary = GetLocation((Ox + 1), (Oy + 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}

		break;

	default:
		return false;

	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			return true;
		}

	}

	// remember to take into account diagnal capture

	return false;
}

ResultOfMove GameLogic::movePawn(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	ResultOfMove success = Failure;

	team team = board[Ox][Oy].GetTeam();

	vector<Locations> list;

	Locations temporary;

	// black moves down, white moves up.

	switch (team)
	{
	case Black:


		// If pawn is at origin it can move 2 spaces forward
		if (Oy == 6)
		{
			temporary = GetLocation(Ox, 4);
			bool isJumpedSpotOccupied = IsSquareOccupied(GetLocation(Ox, 5));
			if (!isJumpedSpotOccupied)
			{
				list.push_back(temporary);
			}
		}

		// move forward
		temporary = GetLocation(Ox, (Oy - 1));
		if (temporary != invalid)
		{
			if (!IsSquareOccupied(temporary))
			{
				list.push_back(temporary);
			}
		}

		// capture left
		temporary = GetLocation((Ox - 1), (Oy - 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}

		// capture right
		temporary = GetLocation((Ox + 1), (Oy - 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}



		break;

	case White:

		// If pawn is at origin it can move 2 spaces forward
		if (Oy == 1)
		{
			temporary = GetLocation(Ox, 3);
			bool isJumpedSpotOccupied = IsSquareOccupied(GetLocation(Ox, 2));
			if (!isJumpedSpotOccupied)
			{
				list.push_back(temporary);
			}
		}

		// move forward
		temporary = GetLocation(Ox, (Oy + 1));
		if (temporary != invalid)
		{
			if (!IsSquareOccupied(temporary))
			{
				list.push_back(temporary);
			}
		}

		// capture left
		temporary = GetLocation((Ox - 1), (Oy + 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}

		// capture right
		temporary = GetLocation((Ox + 1), (Oy + 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}



		break;

	default:
		return Failure;

	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			success = checkForCheckandMove(Ox, Oy, Dx, Dy);
			if ((Dy == 7) && (team == White))
			{
				//board[Dx][Dy].piece.Promote();
			}
			if ((Dy == 0) && (team == Black))
			{
				//board[Dx][Dy].piece.Promote();
			}
			break;
		}

	}

	// remember to take into account diagnal capture

	return success;
}
ResultOfMove GameLogic::moveRook(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	bool obsticleLeft = false;
	bool obsticleRight = false;
	bool obsticleUp = false;
	bool obsticleDown = false;


	int x = Ox;
	int y = Oy;
	// Look to the left of the rook for the correct move.
	while (!obsticleLeft)
	{
		x -= 1;
		// We don't need to check off the edge of the board
		if (x < 0)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;

	while (!obsticleRight)
	{
		x += 1;
		// We don't need to check off the edge of the board
		if (x > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;

	// now check up

	while (!obsticleUp)
	{
		y += 1;
		// We don't need to check off the edge of the board
		if (y > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUp = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	y = Oy;

	while (!obsticleDown)
	{
		y -= 1;
		// We don't need to check off the edge of the board
		if (y > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDown = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	return Failure;
}
ResultOfMove GameLogic::moveBishiop(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	bool obsticleDownLeft = false;
	bool obsticleDownRight = false;
	bool obsticleUpLeft = false;
	bool obsticleUpRight = false;

	team team = board[Ox][Oy].GetTeam();

	int x = Ox;
	int y = Oy;

	while (!obsticleDownLeft)
	{
		x--;
		y--;

		// We don't need to check off the edge of the board
		if ((x < 0) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleDownRight)
	{
		x++;
		y--;

		// We don't need to check off the edge of the board
		if ((x > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpLeft)
	{
		x--;
		y++;

		// We don't need to check off the edge of the board
		if ((x < 0) || (y > 7))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpRight)
	{
		x++;
		y++;

		// We don't need to check off the edge of the board
		if ((x > 7) || (y > 7))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	return Failure;
}
ResultOfMove GameLogic::moveKnight(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	vector<Locations> list;

	Locations temporary;

	temporary = GetLocation((Ox + 1), (Oy - 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 2), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 2), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy + 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy + 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 2), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 2), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy - 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			if (IsSquareOccupied(destination))
			{
				if (team != WhatTeamOwnsSquare(destination))
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
			else
				return checkForCheckandMove(Ox, Oy, Dx, Dy);			
		}
	}

	return Failure;

}
ResultOfMove GameLogic::moveQueen(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	bool obsticleDownLeft = false;
	bool obsticleDownRight = false;
	bool obsticleUpLeft = false;
	bool obsticleUpRight = false;

	bool obsticleLeft = false;
	bool obsticleRight = false;
	bool obsticleUp = false;
	bool obsticleDown = false;

	team team = board[Ox][Oy].GetTeam();

	int x = Ox;
	int y = Oy;

	while (!obsticleDownLeft)
	{
		x--;
		y--;

		// We don't need to check off the edge of the board
		if ((x < 0) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleDownRight)
	{
		x++;
		y--;

		// We don't need to check off the edge of the board
		if ((x > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpLeft)
	{
		x--;
		y++;

		// We don't need to check off the edge of the board
		if ((x < 0) || (y > 7))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpRight)
	{
		x++;
		y++;

		// We don't need to check off the edge of the board
		if ((x > 7) || (y > 7))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;
	y = Oy;
	// Look to the left of the rook for the correct move.
	while (!obsticleLeft)
	{
		x -= 1;
		// We don't need to check off the edge of the board
		if (x < 0)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleRight)
	{
		x += 1;
		// We don't need to check off the edge of the board
		if (x > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	x = Ox;

	// now check up

	while (!obsticleUp)
	{
		y += 1;
		// We don't need to check off the edge of the board
		if (y > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUp = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	y = Oy;

	while (!obsticleDown)
	{
		y -= 1;
		// We don't need to check off the edge of the board
		if (y > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDown = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return checkForCheckandMove(Ox, Oy, Dx, Dy);
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return checkForCheckandMove(Ox, Oy, Dx, Dy);
		}
	}

	return Failure;
}
ResultOfMove GameLogic::moveKing(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	vector<Locations> list;

	Locations temporary;

	temporary = GetLocation((Ox + 1), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			if (team == Black)
			{
				blackKingLoc = destination;
			}
			else
			{
				whiteKingLoc = destination;
			}


			ResultOfMove returnValue = checkForCheckandMove(Ox, Oy, Dx, Dy);

			if (returnValue == Failure)
			{
				if (team == Black)
				{
					blackKingLoc = origin;
				}
				else
				{
					whiteKingLoc = origin;
				}
			}

			return returnValue;
		}
	}

	return Failure;
}

bool GameLogic::EvaluateMovePawn(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	ResultOfMove success = Failure;

	team team = board[Ox][Oy].GetTeam();

	vector<Locations> list;

	Locations temporary;

	// black moves down, white moves up.

	switch (team)
	{
	case Black:


		// If pawn is at origin it can move 2 spaces forward
		if (Oy == 6)
		{
			temporary = GetLocation(Ox, 4);
			bool isJumpedSpotOccupied = IsSquareOccupied(GetLocation(Ox, 5));
			if (!isJumpedSpotOccupied)
			{
				list.push_back(temporary);
			}
		}

		// move forward
		temporary = GetLocation(Ox, (Oy - 1));
		if (temporary != invalid)
		{
			if (!IsSquareOccupied(temporary))
			{
				list.push_back(temporary);
			}
		}

		// capture left
		temporary = GetLocation((Ox - 1), (Oy - 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}

		// capture right
		temporary = GetLocation((Ox + 1), (Oy - 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}



		break;

	case White:

		// If pawn is at origin it can move 2 spaces forward
		if (Oy == 1)
		{
			temporary = GetLocation(Ox, 3);
			bool isJumpedSpotOccupied = IsSquareOccupied(GetLocation(Ox, 2));
			if (!isJumpedSpotOccupied)
			{
				list.push_back(temporary);
			}
		}

		// move forward
		temporary = GetLocation(Ox, (Oy + 1));
		if (temporary != invalid)
		{
			if (!IsSquareOccupied(temporary))
			{
				list.push_back(temporary);
			}
		}

		// capture left
		temporary = GetLocation((Ox - 1), (Oy + 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}

		// capture right
		temporary = GetLocation((Ox + 1), (Oy + 1));
		if (temporary != invalid)
		{
			if (IsSquareOccupied(temporary))
			{
				if (team != WhatTeamOwnsSquare(temporary))
				{
					list.push_back(temporary);
				}
			}
		}



		break;

	default:
		return false;

	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			return true;
		}

	}

	// remember to take into account diagnal capture

	return false;
}
bool GameLogic::EvaluateMoveRook(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	bool obsticleLeft = false;
	bool obsticleRight = false;
	bool obsticleUp = false;
	bool obsticleDown = false;


	int x = Ox;
	int y = Oy;
	// Look to the left of the rook for the correct move.
	while (!obsticleLeft)
	{
		x -= 1;
		// We don't need to check off the edge of the board
		if (x < 0)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;

	while (!obsticleRight)
	{
		x += 1;
		// We don't need to check off the edge of the board
		if (x > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;

	// now check up

	while (!obsticleUp)
	{
		y += 1;
		// We don't need to check off the edge of the board
		if (y > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUp = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	y = Oy;

	while (!obsticleDown)
	{
		y -= 1;
		// We don't need to check off the edge of the board
		if (y > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDown = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	return false;
}
bool GameLogic::EvaluateMoveBishiop(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	bool obsticleDownLeft = false;
	bool obsticleDownRight = false;
	bool obsticleUpLeft = false;
	bool obsticleUpRight = false;

	team team = board[Ox][Oy].GetTeam();

	int x = Ox;
	int y = Oy;

	while (!obsticleDownLeft)
	{
		x--;
		y--;

		// We don't need to check off the edge of the board
		if ((x < 0) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleDownRight)
	{
		x++;
		y--;

		// We don't need to check off the edge of the board
		if ((x > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpLeft)
	{
		x--;
		y++;

		// We don't need to check off the edge of the board
		if ((x < 0) || (y > 7))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpRight)
	{
		x++;
		y++;

		// We don't need to check off the edge of the board
		if ((x > 7) || (y > 7))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	return false;
}
bool GameLogic::EvaluateMoveKnight(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	vector<Locations> list;

	Locations temporary;

	temporary = GetLocation((Ox + 1), (Oy - 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 2), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 2), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy + 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy + 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 2), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 2), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy - 2));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			if (IsSquareOccupied(destination))
			{
				if (team != WhatTeamOwnsSquare(destination))
				{
					return true;
				}
			}
			else
				return true;
		}
	}

	return false;

}
bool GameLogic::EvaluateMoveQueen(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	bool obsticleDownLeft = false;
	bool obsticleDownRight = false;
	bool obsticleUpLeft = false;
	bool obsticleUpRight = false;

	bool obsticleLeft = false;
	bool obsticleRight = false;
	bool obsticleUp = false;
	bool obsticleDown = false;

	team team = board[Ox][Oy].GetTeam();

	int x = Ox;
	int y = Oy;

	while (!obsticleDownLeft)
	{
		x--;
		y--;

		// We don't need to check off the edge of the board
		if ((x < 0) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleDownRight)
	{
		x++;
		y--;

		// We don't need to check off the edge of the board
		if ((x > 7) || (y < 0))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDownRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpLeft)
	{
		x--;
		y++;

		// We don't need to check off the edge of the board
		if ((x < 0) || (y > 7))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleUpRight)
	{
		x++;
		y++;

		// We don't need to check off the edge of the board
		if ((x > 7) || (y > 7))
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUpRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;
	// Look to the left of the rook for the correct move.
	while (!obsticleLeft)
	{
		x -= 1;
		// We don't need to check off the edge of the board
		if (x < 0)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleLeft = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;
	y = Oy;

	while (!obsticleRight)
	{
		x += 1;
		// We don't need to check off the edge of the board
		if (x > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleRight = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	x = Ox;

	// now check up

	while (!obsticleUp)
	{
		y += 1;
		// We don't need to check off the edge of the board
		if (y > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleUp = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	y = Oy;

	while (!obsticleDown)
	{
		y -= 1;
		// We don't need to check off the edge of the board
		if (y > 7)
		{
			break;
		}
		if (IsSquareOccupied(x, y))
		{
			obsticleDown = true;
			if (team != board[x][y].GetTeam())
			{
				if (GetLocation(x, y) == destination)
				{
					return true;
				}
			}
		}
		else if (GetLocation(x, y) == destination)
		{
			return true;
		}
	}

	return false;
}
bool GameLogic::EvaluateMoveKing(Locations origin, Locations destination)
{
	int Ox = GetLocX(origin);
	int Oy = GetLocY(origin);

	int Dx = GetLocX(destination);
	int Dy = GetLocY(destination);

	team team = board[Ox][Oy].GetTeam();

	vector<Locations> list;

	Locations temporary;

	temporary = GetLocation((Ox + 1), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox + 1), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy + 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	temporary = GetLocation((Ox - 1), (Oy - 1));
	if (temporary != invalid)
	{
		list.push_back(temporary);
	}

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == destination)
		{
			if (IsSquareOccupied(destination))
			{
				if (team != WhatTeamOwnsSquare(destination))
				{
					return true;
				}
			}
			else
				return true;
		}
	}

	return false;
}

bool GameLogic::FindPotentialMove(Locations origin, Locations destination)
{
	ChessPieceModel pieceToMove = GetWhatIsInSquare(origin);

	bool successful = false;

	pieceType type = pieceToMove.GetType();

	switch (type)
	{
	case King:
		successful = EvaluateMoveKing(origin, destination);
		break;
	case Queen:
		successful = EvaluateMoveQueen(origin, destination);
		break;
	case Knight:
		successful = EvaluateMoveKnight(origin, destination);
		break;
	case Bishop:
		successful = EvaluateMoveBishiop(origin, destination);
		break;
	case Rook:
		successful = EvaluateMoveRook(origin, destination);
		break;
	case Pawn:
		successful = EvaluateMovePawn(origin, destination);
		break;
	case Invalid:
		successful = false;
		break;
	default:
		successful = false;
		break;
	}
	return successful;
}

void GameLogic::PrintBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j].IsOccupied())
			{
				ChessPieceModel p = board[i][j].GetPiece();

				cout << LocationsToString(GetLocation(i, j)) << " is occupied with : " << TeamToString(p.GetTeam()) << " " << PieceTypeToString(p.GetType()) << endl;
			}
			else
			{
				cout << LocationsToString(GetLocation(i, j)) << " is not occupied." << endl;
			}
		}
	}
}