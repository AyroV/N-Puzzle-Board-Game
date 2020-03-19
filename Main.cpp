#include "BoardVector.h"

using namespace std;

int main() {
	Vector::BoardVector gameBoard;

	int number = 1;
	int counter = 0;

	char move;

	srand((int)time(NULL));

	gameBoard.setSize(); //Creating an n x n square gameboard on solution state. N is defined by user input

	counter = (rand() % 15) + 1;
	while(counter != 0)
	{
		number = rand() % 4; //Making random amounts(15 at most) of random moves to set the game.
		if(gameBoard.move(number))
			counter--;
	}

	gameBoard.resetNumberOfMoves();
	gameBoard.print();


	while(true) {
		cout << "Your Move: " << endl;
		cin >> move;

		if(move == 'R' || move == 'r') {
			if(gameBoard.move(0))
				cout << "Moved Right\n" << endl;

			else
				cout << "Illegal Move" << endl;

			if(gameBoard.isSolved()) {
				cout << "Board Solved!\nNumber of moves: " << gameBoard.numberOfMoves() << endl;
				return 1;
			}

		}

		else if(move == 'L' || move == 'l') {
			if(gameBoard.move(1))
				cout << "Moved Left\n" << endl;

			else
				cout << "Illegal Move" << endl;

			if(gameBoard.isSolved()) {
				cout << "Board Solved!\nNumber of moves: " << gameBoard.numberOfMoves() << endl;
				return 1;
			}
		}

		else if(move == 'U' || move == 'u') {
			if(gameBoard.move(2))
				cout << "Moved Up\n" << endl;

			else
				cout << "Illegal Move" << endl;

			if(gameBoard.isSolved()) {
				cout << "Board Solved!\nNumber of moves: " << gameBoard.numberOfMoves() << endl;
				return 1;
			}
		}

		else if(move == 'D' || move == 'd') {
			if(gameBoard.move(3))
				cout << "Moved Down\n" << endl;

			else
				cout << "Illegal Move" << endl;

			if(gameBoard.isSolved()) {
				cout << "Board Solved!\nNumber of moves: " << gameBoard.numberOfMoves() << endl;
				return 1;
			}
		}

		else if(move == 'I' || move == 'i') { //Intelligent move will try to make a move to reach solution. -It is not that intelligent btw
			gameBoard.moveIntelligent();

			if(gameBoard.isSolved()) {
				cout << "Board Solved!\nNumber of moves: " << gameBoard.numberOfMoves() << endl;
				return 1;
			}
		}

		else if(move == 'S' || move == 's') { //Saving the current board to a txt file
			string filename;
			cout << "Enter a file name to save to: ";
			cin >> filename;
			gameBoard.writeToFile(filename);
		}

		else if(move == 'W' || move == 'w') { //Loading a game board from a txt file
			string filename;
			cout << "Enter a file name to load from: ";
			cin >> filename;
			gameBoard.readFromFile(filename);
			gameBoard.resetNumberOfMoves();
		}

		else {
			cout << "Wrong input, try again." << endl;
		}
		gameBoard.print();
	}
}
