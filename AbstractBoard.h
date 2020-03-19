#ifndef _ABSTRACTBOARD_H_
#define _ABSTRACTBOARD_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

namespace Abstract {
	class AbstractBoard;
}

namespace Vector {
	class BoardVector;
}

class Abstract::AbstractBoard
{
private:
	static int totalBoards;

public:
	AbstractBoard() {
		totalBoards++;
	}

	virtual void print() const;

	virtual void readFromFile(string filename);
	virtual void writeToFile(string filename);

	virtual void reset();
	virtual void setSize();

	virtual int move(int direction);
	virtual bool isSolved() const;
	virtual void moveIntelligent();

	virtual int numberOfMoves() const;
	virtual int resetNumberOfMoves() const;
	virtual string lastMove() const;

	virtual int operator ()(int indexOne, int indexTwo);
	virtual bool operator == (const Vector::BoardVector &x) const;

	static int NumberOfBoards() { return totalBoards; }

	virtual int getRow() const;
	virtual int getColumn() const;
	virtual int getX() const;
	virtual int getY() const;

	virtual void setRow(int a);
	virtual void setColumn(int a);
	virtual void setX(int a);
	virtual void setY(int a);

	virtual int findBiggest(int x, int y, int z, int w) const;

};

#endif
