
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
	

	/**********************************************************************/
	/* PART THREE
	 * COMMENT OUT THE ABOVE TESTING CODE AND COMMENT IN THE BELOW CODE TO RUN
	 * THE GAME.
	 */
	
	while (keepPlaying) {
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
		printBoard();
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
	//(8 pts)
	//Instructions for this method:
//	 this method first uses the dog's printDog method to print out info
//	 about the dog, and then it prints out the board as follows:
//	 *
//	 This method prints out hte board such that it looks like a board.  It
//	 prints a blank space for any square (for squares that do not have
//	 food, traps, walls, the dog, and aren't the beginning or the ending.
//   (at first, there will be no food or traps, or even walls or dog, but we
//   will be adding food as 'F' character, traps as 'T' character, walls as
//   '|' or '_' characters, and the dog 'D' character to the board, so you want
//   to print a space for everything that isn't a 'T','F','|','_',or'D'.
//	 Otherwise it prints out the character in the square. Note that I printed a
//	 border around the entire board so it was easier to look at, and, equally,
//	 I placed an -> arro (thats a minus and a greater than sign) in the border
//	 for where the beginning of the game was and where the end of the game was.

	mydog.printDog();  // COMMENT THIS IN WHEN YOU Write your Dog class!!

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
						cout << "🐶";
					} else if(board[y][x] == '|') {
						// wall 1
						cout << "🌳";
					} else if(board[y][x] == '-') {
						// wall 2
						cout << "🌲";
					} else if(board[y][x] == 'F') {
						// food
						cout << "🍗";
					} else if(board[y][x] == 'T' && debug) {
						// trap
						cout << " ☠";
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
	// (5 pts)
	/* Instructions for writing addFood:
	/* this method randomly adds food around the board.  For easy, I added the field size
	 * number of foods randomly around the board.  For medium, I added size-2 foods, and for
	 * hard I added size-4 foods.  The amount of strength the dog gets when they eat (aka
	 * move onto) the food is determined in the moveDog method.
	 */

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
	// (5 pts)
	//Instructions for addTraps
	/* this method randomly adds traps around the board.  For easy I added size - 6 traps,
	 * for medium, I added size - 8 traps, and for hard I added size - 10 traps.  Note: Traps are
	 * only printed on the board when the game is in debug mode.  The amount of strength each trap
	 * saps from the dog is determined in the moveDog method when the dog moves on a Trap.
	 */

	int traps;
	// not sure why but it always generates 2 more traps than it should so I've decreased count
	switch(level) {
		case 'e':
			traps = 4;
			break;
		case 'm':
			traps = 6;
			break;
		case 'h':
			traps = 8;
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
	// (12 pts)
	//Instructions for moveDog
	/* This is a somewhat long method.
		 * First, it determines the new coordinats of the dog, based on teh direction in which the
		 * dog wants to move (based on what c holds - u is up, d is down, l is left, r is right).
		 *
		 * If the dog is at teh edge of the board, teh dog should not move
		 *
		 * If the dog moves over food, a random number between 2 and 17 is generated, and the
		 * dog's changeStrength method is used to increase the dog's strength by the random amount.
		 *
		 * If the dog moves over the end of the board, the dog's won method is called and false is
		 * returned from this method.
		 *
		 * If the dog moves over a Trap, a random number between 2 and 17 is generated and the dog's
		 * changeStrength method is called with that negative number.  (Note that the changeStrength
		 * method returns a boolean indicating whether the dog's strength has gone to 0 or less, and
		 * thus the dog has died and the game is over. That boolean value is returned from this method).
		 *
		 * If the dog moves over a wall, the method checks to see if the dog has enough strength to
		 * knock down the wall (I made it cost 6 strength points to knock down a wall).  If the dog
		 * has enough strength, the user is asked, "Do you want to knock down that wall?"  If the user
		 * responds "yes", then the wall is knocked down, the dog moves into that square, adn the dog's
		 * strength decreases by 6.  If the answer is "no", the dog loses 1 strength point, just because.
		 *
		 * If the dog moves into a blank square, the dog loses 2 strength points using the changeStrength
		 * method (which, again, will return false if the dog has lost all their strength and died.
		 *
		 * NOTE: I am not concerned with the precise rules here.  If you want to change the range of
		 * random numbers for food, if you are worried about whether you still lose 2 strength points for
		 * moving even though you gained points for moving over food - I'm leaving all that to your preference.
		 * I am concerned that you are using classes, objects, and object methods and accessing object
		 * fields correctly!
		 *
		 */
	
		// calculate new coordinates
		int tempX = mydog.x;
		int tempY = mydog.y;
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

			return mydog.changeStrength(amt);
		} else if(tempX == size && tempY == endy) {
			// entering the end zone
			mydog.won();
		}


}


void Board::playGame() {
	bool play = true;
	while (play) {
		cout << "Move (u, d, l, r) "<<endl;
		char c;
		cin >> c;
		play = moveDog(c);
		printBoard();
	}


}


