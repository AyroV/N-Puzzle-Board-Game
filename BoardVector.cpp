#include "BoardVector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void Vector::BoardVector::print() const {
	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {

		if(board[i][j] == -1)
			cout << "  " << "\t";

		else if(board[i][j] == -2)
			;

		else if(board[i][j] < 10 && board[i][j] != -1)
			cout << '0' << board[i][j] << "\t";

		else
			cout << board[i][j] << "\t";
		}

		cout << endl;
	}

	cout << endl;
}

void Vector::BoardVector::readFromFile(string filename) {
	ifstream input;
	string line;
	string word;

	int counterX = -1;
	int counterY = 0;
	int element;

	this->board.clear();

	input.open(filename);

	while(getline(input, line)) {
		istringstream ss(line);
		vector <int> tempVector;
		while(ss) {
			counterX++;	

			ss >> word;
			if(word != "bb")
				element = stoi(word);

			else {
				element = -1;
				this->x = counterX;
				this->y = counterY;
			}

			tempVector.push_back(element);
		}

		counterY++;
		column = counterX;
		counterX = -1;

		tempVector.pop_back();
		this->board.push_back(tempVector);
	}

	row = counterY;

	cout << "Loaded!" << endl;
	input.close();
}

void Vector::BoardVector::writeToFile(string filename) {
	ofstream save;
	save.open(filename);

	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {
			if(board[i][j] == 0)
				save << "00";

			else if(board[i][j] == -1)
				save << "bb";

			else if(board[i][j] < 10 && board[i][j] >= 0)
				save << '0' << board[i][j];

			else
				save << board[i][j];

			if(j != board[i].size() - 1)
				save << ' ';
		}
		save << endl;
	}

	cout << "Saved!" << endl;
	save.close();
}

void Vector::BoardVector::reset() {
	int number = 1;

	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {

			if(board[i][j] == 0 || board[i][j] == -2) {
				//empty
			}

			else {
				board[i][j] = number;
				number++;
			}

			if(number == board.size() * board[i].size()) {
				board[i][j + 1] = -1;
				x = j + 1;
				y = i;
				return;
			}
		}
	}
}

void Vector::BoardVector::setSize() {
	int boardSize;
	int number = 1;

	vector <int> tempVector;
	board.clear();

	cout << "Please enter the problem size" << endl;
	cin >> boardSize;

	for(int i = 0; i < boardSize; i++) {
		for(int j = 0; j < boardSize; j++) {
			tempVector.push_back(number);
			number++;

			if(number == boardSize * boardSize) {
				tempVector.push_back(-1);
				break;
			}
		}

		board.push_back(tempVector);
		tempVector.clear();
	}

	x = y = boardSize - 1;
	row = column = boardSize;
}

int Vector::BoardVector::move(int direction) {
	if(direction == 0 && x != board[y].size() - 1 && board[y][x + 1] != 0) {
		board[y][x] = board[y][x + 1];
		board[y][x + 1] = -1;

		x += 1;
		previousMove = "Right";
		totalMoves++;
		return 1;
	}

	else if(direction == 1 && x != 0 && board[y][x - 1] != 0) {
		board[y][x] = board[y][x - 1];
		board[y][x - 1] = -1;

		x -= 1;
		previousMove = "'Left";
		totalMoves++;
		return 1;
	}

	else if(direction == 2 && y != 0 && board[y - 1][x] != 0) {
		board[y][x] = board[y - 1][x];
		board[y - 1][x] = -1;

		y -= 1;
		previousMove = "Up";
		totalMoves++;
		return 1;
	}

	else if(direction == 3 && y != board.size() - 1 && board[y + 1][x] != 0) {
		board[y][x] = board[y + 1][x];
		board[y + 1][x] = -1;

		y += 1;
		previousMove = "Down";
		totalMoves++;
		return 1;
	}

	else {
		previousMove = "N";
		return 0;
	}
}

bool Vector::BoardVector::isSolved() const {
	int check = 0;
	int checkCounter = 1;


	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {
			if(board[i][j] == checkCounter) {
				check++;
				checkCounter++;
			}

			else if(board[i][j] == 0)
			{
				//empty
			}
			
			else
				break;

			if(check == (board.size() * board[0].size()) - 1)
				return true;
		}
	}

	return false;
}

void Vector::BoardVector::moveIntelligent() {
	int biggest;
	int pointOne = 0, pointTwo = 0, pointThree = 0, pointFour = 0;
	int numberCounter = 1;

	if(x != board[0].size() - 1) {
		board[y][x] = board[y][x + 1];
		board[y][x + 1] = 0;

		for(int i = 0; i < board.size(); i++)
			for(int j = 0; j < board[0].size(); j++) {
				if(board[i][j] == numberCounter)
					pointOne++;

				numberCounter++;
			}

		board[y][x + 1] = board[y][x];
		board[y][x] = 0;

		numberCounter = 1;
	}

	if(x != 0) {
		board[y][x] = board[y][x - 1];
		board[y][x - 1] = 0;

		for(int i = 0; i < board.size(); i++)
			for(int j = 0; j < board[0].size(); j++) {
				if(board[i][j] == numberCounter)
					pointTwo++;

				numberCounter++;
			}

		board[y][x - 1] = board[y][x];
		board[y][x] = 0;

		numberCounter = 1;
	}

	if(y != board.size() - 1) {
		board[y][x] = board[y + 1][x];
		board[y + 1][x] = 0;

		for(int i = 0; i < board.size(); i++)
			for(int j = 0; j < board[0].size(); j++) {
				if(board[i][j] == numberCounter)
					pointThree++;

				numberCounter++;
			}

		board[y + 1][x] = board[y][x];
		board[y][x] = 0;

		numberCounter = 1;
	}

	if(y != 0) {
		board[y][x] = board[y - 1][x];
		board[y - 1][x] = 0;

		for(int i = 0; i < board.size(); i++)
			for(int j = 0; j < board[0].size(); j++) {
				if(board[i][j] == numberCounter)
					pointFour++;

				numberCounter++;
			}

		board[y - 1][x] = board[y][x];
		board[y][x] = 0;
	}

	biggest = Vector::BoardVector::findBiggest(pointOne, pointTwo, pointThree, pointFour);

	switch(biggest) {
		case 1:
			move(0);
			cout << "Intelligent move chose R" << endl;
			break;

		case 2:
			move(1);
			cout << "Intelligent move chose L" << endl;
			break;

		case 3:
			move(3);
			cout << "Intelligent move chose U" << endl;
			break;

		case 4:
			move(2);
			cout << "Intelligent move chose D" << endl;
			break;

		default:
			cout << "Intelligent didn't move" << endl;
			break;
	}
}

int Vector::BoardVector::findBiggest (int x, int y, int z, int w) const {

	if(x >= y && x >= z && x >= w)
		return 1;

	if(y >= x && y >= z && y >= w)
		return 2;

	if(z >= y && z >= x && z >= w)
		return 3;

	if(w >= y && w >= z && w >= x)
		return 4;
}

bool Vector::BoardVector::operator ==(const Vector::BoardVector &a) const {
	if(this->board.size() != a.board.size() || this->board[0].size() != a.board[0].size())
		return false;

	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {
			if(this->board[i][j] != a.board[i][j])
				return false;
		}
	}

	return true;
}
