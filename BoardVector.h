#ifndef _BOARDVECTOR_H_
#define _BOARDVECTOR_H_

#include "AbstractBoard.h"

class Vector::BoardVector
{
	private:
		vector<vector <int>> board;
		int x;
		int y;
		int row;
		int column;
		int totalMoves;
		string previousMove;

	public:
		BoardVector() {
			totalMoves = x = y = 0;
			previousMove = "S";
		}

		void print() const;

		void readFromFile(string filename);
		void writeToFile(string filename);

		void reset();
		void setSize();

		int move(int direction);
		bool isSolved() const;
		void moveIntelligent();

		int numberOfMoves() const { return totalMoves; };
		int resetNumberOfMoves() { totalMoves = 0; }
		string lastMove() const { return previousMove; };

		int operator ()(int indexOne, int indexTwo) const { return board[indexOne][indexTwo]; };
		bool operator == (const Vector::BoardVector &x) const;

		int findBiggest(int x, int y, int z, int w) const;

		int getRow() const { return row; };
		int getColumn() const { return column; };
		int getX() const { return x; };
		int getY() const { return y; };

		void setRow(int a) { row = a; };
		void setColumn(int a) { column = a; };
		void setX(int a) { x = a; };
		void setY(int a) { y = a; };
};

#endif
