
#include "Board.hpp"
#include <iostream>
using namespace std;

Board::Board(char diff, bool d){
	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(bool d){
	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(char diff, string name, bool d) {
	level = diff;
	debug = d;
	mydog.name = name;
	wallStrength = 6;
	InitAll();
}
void Board::InitAll() {
	bool keepPlaying = true;
	
	while (keepPlaying) {
		cout << "Would you like to use special styling? (May effect character spacing) [Y/n]" << endl;
		char e;
		cin >> e;
		if(e == 'Y' || e == 'y') {
			emojis = true;
		} else {
			emojis = false;
		}
		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		starty = rand() % size;
		startx = 0;
		endy = rand() % size;
		endx = size-1;
		mydog.x = startx;
		mydog.y = starty;
		boardConfig();
		addFood();
		addTraps();
		if(emojis) cout << "\x1B[2J\x1B[H" << endl;
		playGame();
		cout << "Play again? " << endl;
		string s = "no";
		cin>>s;
		if (s == "yes" || s == "Yes" || s == "Y" || s == "y") {
			keepPlaying = true;
			mydog.reset();
		}
		else {
			cout <<"Thanks for playing!" << endl;
			keepPlaying = false;
		}
	}
	
}


/***********************************************************************/
/* HERE'S WHERE THE CODE GOES!                                         */
/***********************************************************************/

void Board::printBoard() {

	mydog.printDog();

	// this is about to get messy; I wouldn't even suggest trying to understand it
	for(int y = -1; y < size + 1; y++) {
		for(int x = -1; x < size + 1; x++) {
			if(y == -1) {
				// draw top border
				if(x == -1) {
					// left corner
					if(starty == 0) {
						cout << "  ━━━";
					} else {
						cout << "    ┏";
					}
				} else if(x == size) {
					// right corner
					if(endy == 0) {
						cout << "━━━━";
					} else {
						cout << "━┓";
					}
				} else {
					cout << "━━";
				}
			} else if(y == size) {
				// draw bottom border
				if(x == -1) {
					// left corner
					if(starty == 19) {
						cout << "  ━━━";
					} else {
						cout << "    ┗";
					}
				} else if(x == size) {
					// right corner
					if(endy == 19) {
						cout << "━━━━";
					} else {
						cout << "━┛";
					}
				} else {
					cout << "━━";
				}
			} else {
				if(x == -1) {
					// left border
					if(y == starty - 1) {
						cout << "  ━━┛";
					} else if(y == starty) {
						cout << "  ⮕  ";
					} else if(y == starty + 1) {
						cout << "  ━━┓";
					} else {
						cout << "    ┃";
					}
				} else if(x == size) {
					// right border
					if(y == endy - 1) {
						cout << " ┗━━";
					} else if(y == endy) {
						cout << "  ⮕ ";
					} else if(y == endy + 1) {
						cout << " ┏━━";
					} else {
						cout << " ┃ ";
					}
				} else {
					// board characters
					if(x == mydog.x && y == mydog.y) {
						if(emojis) {
							cout << "🐶";
						} else {
							cout << " D";
						}
						
					} else if(board[y][x] == '|' && emojis) {
						// wall 1
						cout << "🌳";
					} else if(board[y][x] == '-' && emojis) {
						// wall 2
						cout << "🌲";
					} else if(board[y][x] == 'F' && emojis) {
						// food
						cout << "🍗";
					} else if(board[y][x] == 'T' && debug && emojis) {
						// trap
						cout << " ☠";
					} else if(board[y][x] == 'T' && debug && !emojis) {
						//trap
						cout << " T";
					} else if(board[y][x] == 'T' && !debug) {
						cout << "  ";
					} else {
						cout << " " << board[y][x];
					}
				}
			}
		}
		cout << endl;
	}
	
}

void Board::boardConfig() {

	// put "dummy values" in each square
	int y;
	int x;
	for(y = 0; y < size; y++) {
		for(x = 0; x < size; x++) {
			board[y][x] = ' ';
		}
	}


	// there will be 12 walls total; randomly select how many will be vertical/horizontal with at least 2 on each axis
	int horizontal = (rand() % 8) + 2;
	int vertical = 12 - horizontal;

	// add horizontal walls
	int i;
	int j;
	int length;
	float positionRange = 10.0 / horizontal;
	int position[2] = {0, 0};
	cout << "rows: " << horizontal << "; columns: " << vertical << "; mode: " << level << endl;
	for(i = 0; i < horizontal; i++) {
		// select wall length (at least 3 in length, longer lengths & higher probability of longer lengths with harder levels)
		switch(level) {
			case 'e':
				length = (rand() % 6) + 3;
				break;
			case 'm':
				length = (rand() % 8) + 5;
				break;
			case 'h':
				length = (rand() % 10) + 6;
				break;
		}

		// select wall position
		position[0] = (positionRange * i) * 2;
		position[1] = rand() % (size - length + 1);
		//position[1] = rand() % 20;

		// add wall (wall will wrap if too long)
		for(j = 0; j < length; j++) {
			board[position[0]][(position[1] + j) % 20] = '-';
		}
	}

	// add vertival walls
	positionRange = 10.0 / vertical;
	for(i = 0; i < vertical; i++) {
		// select wall length (always at least length 3 cause I kept getting short walls)
		switch(level) {
			case 'e':
				length = (rand() % 6) + 3;
				break;
			case 'm':
				length = (rand() % 10) + 3;
				break;
			case 'h':
				length = (rand() % 13) + 3;
				break;
		}

		// select wall position
		position[0] = (positionRange * i) * 2;
		position[1] = rand() % (size - length + 1);

		// add wall (wall will wrap if too long)
		for(j = 0; j < length; j++) {
			board[(position[1] + j) % 20][position[0] + 1] = '|';
		}
	}

}


void Board::addFood() {

	int treats = 0;
	switch(level) {
		case 'e':
			treats = size;
			break;
		case 'm':
			treats = size - 2;
			break;
		case 'h':
			treats = size - 4;
			break;
		default:
			treats = size;
	}

	int x;
	int y;


	for(int i = 0; i < treats; i++) {
		do {
			x = rand() % size;
			y = rand() % size;
		} while (board[y][x] != ' ');
		board[y][x] = 'F';
	}
}

void Board::addTraps() {

	int traps;
	switch(level) {
		case 'e':
			traps = 6;
			break;
		case 'm':
			traps = 8;
			break;
		case 'h':
			traps = 10;
			break;
	}

	int x;
	int y;
	for(int i = 0; i < traps; i++) {
		do {
			x = rand() % size;
			y = rand() % size;
		} while (board[y][x] != ' ');
		board[y][x] = 'T';
	}

}


bool Board::moveDog(char c) {
		// calculate new coordinates
		int tempX = mydog.x;
		int tempY = mydog.y;
		int rand_number;
		switch(c) {
			case 'u':
				tempY -= 1;
				break;
			case 'd':
				tempY += 1;
				break;
			case 'l':
				tempX -= 1;
				break;
			case 'r':
				tempX += 1;
				break;
		}

		// check if new coordinates are in bounds
		if(tempX >= 0 && tempX < 20 && tempY >= 0 && tempX < 20) {
			// move is in bounds

			int amt = 0;
			bool move = false;
			if(board[tempY][tempX] == '|' || board[tempY][tempX] == '-') {
				// has hit a wall
				if(mydog.strength > 6) {
					char input;
					cout << "You have hit a wall, would you like to break it? ";
					cin >> input;

					if(input == 'y' || input == 'Y') {
						amt = -1 * wallStrength;
						move = true;
					} else {
						amt = -1;
					}
				} else {
					amt = -1;
				}
			} else if(board[tempY][tempX] == 'T') {
				// has landed on a trap
				amt = -1 * ((rand() % 16) + 2);
				move = true;
			} else if(board[tempY][tempX] == 'F') {
				// has landed on food
				amt = (rand() % 16) + 2;
				move = true;
			} else {
				// normal move
				amt = -2;
				move = true;
			}

			if(move) {
				mydog.x = tempX;
				mydog.y = tempY;
				board[tempY][tempX] = ' ';
			}

			bool cont = mydog.changeStrength(amt);
			if(cont && emojis) cout << "\x1B[2J\x1B[H" << endl;
			return cont;
		} else if(tempX == size && tempY == endy) {
			// entering the end zone
			mydog.won();
			return false;
		} else {
			return false; // to suppress warning
		}


}


void Board::playGame() {
	bool play = true;
	while (play) {
		printBoard();
		cout << "Move (u, d, l, r) "<<endl;
		char c;
		cin >> c;
		play = moveDog(c);
	}


}
