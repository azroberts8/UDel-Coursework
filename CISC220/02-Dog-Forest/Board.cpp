
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
	/*********************************************************************/
	//FOR TESTING!!!
	// Here's where there's code for getting your initial methods working
	// Once you've got this part working, you can comment it out and then
	// just play the game.
	//
	// First:  Write and test printBoard following the instructions inside of
	// the printBoard Method below.  Then test it to make sure it's working
	// properly.
	printBoard();
	// Your output should be this:
	//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//		| 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 |
	//		| 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 |
	//		| 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 |
	//		| 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 |
	//		| 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 |
	//		| 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 |
	//		| 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 |
	//		| 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 |
	//		| 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 |
	//		| 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 |
	//		| 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 |
	//		| 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 |
	//		| 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 |
	//		| 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 |
	//		| 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 |
	//		| 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 |
	//		| 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 |
	//		| 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 |
	//		| 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 |
	//		| 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 |
	//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//
	//
	// Next:
	// Write the boardConfig Method using the instructions inside the BoardConfig
	// method below, and then test it.
	startx = 1;
	starty = 0;
	endx = 1;
	endy = size-1;
	boardConfig();
	printBoard();
	// Your results should look something like the following (walls are random, so
	// yours will be unique:
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|   |                           |   |     |
//		->D     |               |       |       E ->
//		|                       |       |   |     |
//		|               |               |   |     |
//		|   |   |       |       |                 |
//		|   |   |         _ _ _   _ _ _ _     _ _ |
//		|       |       |                         |
//		|   |           |               |         |
//		|   |                   |           |     |
//		|   _ _ |     _ _ _ _ _ _           | _   |
//		|       |               |       |         |
//		|   |   |                       |   |     |
//		|               |       |                 |
//		|   _     _ _   | _ _ _ |   _   _   _     |
//		|   |           |               |         |
//		|                                   |     |
//		|   |           |       |           |     |
//		|   |   |                                 |
//		|                       |                 |
//		|       |       |               |   |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//
	//
	// Next, let's write the addFood method to add food and print the board:
	level = 'e';
	addFood();
	printBoard();
	cout << "***************************************" << endl;
	boardConfig();
	level = 'm';
	addFood();
	printBoard();
	cout << "***************************************" << endl;
	boardConfig();
	level = 'h';
	addFood();
	printBoard();
	cout << "***************************************" << endl;
	// OUTPUT Should be something like this (note the different number of Food
	// items depending on the differing level of difficulty):
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|       | F               F         |     |
//		->D     _ _ _ _ _ _ _ _   _   _     _   E ->
//		|       |   |                 F     |     |
//		|       |   |           F           |     |
//		|       |   |                 F     |     |
//		|       |   |                       | F   |
//		|     F |   |                 F           |
//		| _ _ _ | _ | _ F   _   _ _ _   _ _ _ _   |
//		|       |                           |     |
//		| _ _   _ _ | _ _ _ _ _   _ _     _ _   F |
//		|                                   |     |
//		| _ _ _   _ | _     _ _   _ F _ _ _ _   _ |
//		|           |                     F |     |
//		| _ _ _ |   |   _ _ _ _ _ _     _ _ _   _ |
//		|                 F                 |     |
//		| _ _   | _ | _     _   _ _ _ _ _ _ _ _   |
//		|       |   |         F F         F |     |
//		|       |       F                   |     |
//		|         F                         |     |
//		|     F |   |   F                   |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
//
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|                               |   |   F |
//		->D _ _       _ _   | _     | _ _       E ->
//		|       |           |                     |
//		|                   |           |   |   F |
//		|       |                                 |
//		| _ F     _ _ _       F _ _ F _ | _     _ |
//		|       |           |       |       |     |
//		| _ _   _   F _ _     _   _ _   | _ |     |
//		|       |               F   |   |   |     |
//		|       |   F                       |     |
//		|                   |   F   |           F |
//		| _     _   _   _         _ | _ _ _ _ F   |
//		|       |   F       |       |   |   |     |
//		|       |           |       |   |       F |
//		|                           |       |   F |
//		|       |           |                     |
//		|     F             |     F   F |   |     |
//		|                               |         |
//		|       |                   |             |
//		| F                                       |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
//
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|       F       F           |             |
//		->D _ _ _       _     _ _ _ | _ _ _ _ _ E ->
//		|       |                   |             |
//		|                                 F       |
//		|       |                   |   F         |
//		| _   _ | _ _ _ _   _ _ _ _ _ _       _   |
//		|       |                   |             |
//		|     _ | _ _   _ _ _ _ _ _ | _     _ _ _ |
//		|       |                   |       F     |
//		| _   _ _ _   _     _   _ _ | _ _ _   _ _ |
//		|       |               F   |             |
//		| _ _   | _ _     _ F _   _ _ _ _ _ _   _ |
//		|     F |                                 |
//		|       |                   | F           |
//		|                     F     |             |
//		| _ _   | _   _   _ _ _ _ _ _ _   _ _     |
//		|       |               F   | F           |
//		| _ _   |   _ _ _ _   _ _ _ _ _ _   _     |
//		|     F       F                           |
//		|                   F     F |             |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************

	//Once you have this working, you must add the traps. Write the addTraps
	// method, as described below.  Your output should be as follows:


	level = 'e';
	addFood();
	addTraps();
	printBoard();
	cout << "***************************************" << endl;
	boardConfig();
	level = 'm';
	addFood();
	addTraps();
	printBoard();
	cout << "***************************************" << endl;
	boardConfig();
	level = 'h';
	addFood();
	addTraps();
	printBoard();
	cout << "***************************************" << endl;
	// Your output should look something like this:
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|           F F   F | F | F   F     |     |
//		->D   _ _ _ _       _ _ _     _ _ _ _ _ E ->
//		|   F     F         |   |           |     |
//		|     F       T     |           F   |     |
//		|   F   |           |     T               |
//		|   _   | _     _ _ _ _ _ _ _ _     _ _ _ |
//		|             F     |   |           |     |
//		| _ _ _ | F _     _ | _ _ _ _   _   _ _ _ |
//		|       |       T       |         T | F   |
//		|             F     F   |           |     |
//		|   F   |           | F |     F     |     |
//		|       |   F   F   |   |   T F     | T   |
//		|     F | F     F       |           |     |
//		| _ _ _ | _   _ _ _ F _ | _   _   _ _ _   |
//		|       | F         | F |                 |
//		| _ _ _ | _ _ _ _ _ |   _ _     _     _ _ |
//		|       |               |           |     |
//		| T F   | F         |   |       F F |     |
//		| T     |           |         F     |     |
//		|   F     F T       |   |   F T     |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
//
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|       |       F       |                 |
//		->D _ _ _   | _   _ | _     T   _   _   E ->
//		| T         |       |         T |   | T   |
//		|   F   |   |     F   F         |         |
//		|           |           |     T           |
//		|       | F         |           |   |     |
//		|                   |   |       |   | F   |
//		| _ F _       _ F   | _ F   _   _ _ | _ _ |
//		|       |                   F             |
//		|                   |   | T     |   |     |
//		|       |           |           |   F     |
//		|       |   |       T                     |
//		|             F         |               T |
//		| _     | _ |     _ _ _   _   _ _ _ |     |
//		|           |           |       F       F |
//		|           |           |       | T       |
//		|       | T |       |               |   F |
//		|       |     T     |   |     F     F     |
//		|                       F       |   |     |
//		|                       |       | T |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
//
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|   |       F   |   F   T       |   |     |
//		->D |           |   T       |           E ->
//		|                         T     |   |     |
//		| _ |   _ _     _ _ _ _     _   _ _ _ _ _ |
//		|   |           |           |   |   |     |
//		| _ | _ _   _ _ _ _ _ _ _   _   _   | F _ |
//		|   | F         | T         F   |         |
//		|   |     F     |           |   |   | T   |
//		|   |           |   T       |   |   |     |
//		|   |   _ _   _ _ _ _ _ _ _ _   _ _ _     |
//		|     T   F T   |     F     |   |         |
//		| _ | _ _ T _ _ |   _ _ _ _ |   _ _   _ _ |
//		| F | T         |           |   |   |     |
//		|             F     T               |     |
//		|                     T     |   |   |     |
//		|   |     T     |           | F |   |     |
//		|   |           |         F | F |   |   F |
//		|         T           F     |   |     F   |
//		|               |           |       |     |
//		|               |           |   |   |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
// ****************************************************************************
//  Part 2:
//  Dog.hpp and Dog.cpp
// *****************************************************************************
//	Now you'll have to write the Dog class and header file before you can write'
//	and test the moveDog method.
//  The instructions for this are below the Board.hpp and Board.cpp files in the
//  lab instructions.
//	Once you are done writing the Dog class and header, you'll need to do the '
//	uncomment out (comment in?) the following
//	 * 1) in the .hpp class, you'll have to comment in the Dog myDog line Board.hpp
//	 * (it's around line 47)
//	 * 2) In the 3rd Board Constructor, you'll need to comment in the mydog.name line
//	 *  (it's around line 37 in this file)
//	 * 3) And you'll have add to your printBoard method a line for printing out
//	 *    the dog object's name and the dog object's strength.
//
// And now write moveDog() as described inside the  moveDog method, below.
// Once done, uncomment out the following 4 lines and test with the following code:
//	moveDog('d');
//	moveDog('u');
//	moveDog('r');
//	moveDog('l');
	// your dog should move down, up, right, and then left.  If you hit a food
	// or a trap, you should get a message as described in the moveDog method, below.





	/*********************************************************************/
	//End of Testing.  Now comment out the above testing stuff, and
	// comment in the rest of the init method, below
	/*********************************************************************/


	/**********************************************************************/
	/* PART THREE
	 * COMMENT OUT THE ABOVE TESTING CODE AND COMMENT IN THE BELOW CODE TO RUN
	 * THE GAME.
	 */
	/*
	while (keepPlaying) {
		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		startx = rand() % size;
		starty = 0;
		endx = rand() % size;
		endy = size-1;

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
	*/
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
	for(int y = -1; y < 21; y++) {
		for(int x = -1; x < 21; x++) {
			if(y == -1) {
				// draw top border
				if(x == -1) {
					// left corner
					if(starty == 0) {
						cout << "  ━━━";
					} else {
						cout << "    ┏";
					}
				} else if(x == 20) {
					// right corner
					if(endy == 0) {
						cout << "━━━━";
					} else {
						cout << "━┓";
					}
				} else {
					cout << "━━";
				}
			} else if(y == 20) {
				// draw bottom border
				if(x == -1) {
					// left corner
					if(starty == 19) {
						cout << "  ━━━";
					} else {
						cout << "    ┗";
					}
				} else if(x == 20) {
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
				} else if(x == 20) {
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
					if(board[y][x] == '|') {
						// wall 1
						cout << "🌳";
					} else if(board[y][x] == '-') {
						// wall 2
						cout << "🌲";
					} else if(board[y][x] == 'F') {
						// food
						cout << "🍗";
					} else if(board[y][x] == 'T') {
						// trap
						cout << "🪤";
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
	for(y = 0; y < 20; y++) {
		for(x = 0; x < 20; x++) {
			board[y][x] = ' ';
		}
	}


	// there will be 12 walls total; randomly select how many will be vertical/horizontal with at least 2 on each axis
	int horizontal = (rand() % 10) + 2;
	int vertical = 12 - horizontal;

	// add horizontal walls
	int i;
	int j;
	int length;
	float positionRange = 10.0 / horizontal;
	int position[2] = {0, 0};
	cout << "rows: " << horizontal << "; columns: " << vertical << "; positionRange: " << positionRange << endl;
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
		position[1] = rand() % 20;

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
		position[1] = rand() % 20;

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


}

void Board::addTraps() {
	// (5 pts)
	//Instructions for addTraps
	/* this method randomly adds traps around the board.  For easy I added size - 6 traps,
	 * for medium, I added size - 8 traps, and for hard I added size - 10 traps.  Note: Traps are
	 * only printed on the board when the game is in debug mode.  The amount of strength each trap
	 * saps from the dog is determined in the moveDog method when the dog moves on a Trap.
	 */


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


