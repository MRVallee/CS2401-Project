/*************************************************************

Made By: Michael Vallee | mv836315@ohio.edu

The purpose of this file is to house the main function
which is the heart of the program

Last Modified: 12/10/17

**************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "game.h"
#include "othello.h"
#include "colors.h"

using namespace main_savitch_14;


int main() {

	othello match;    //This variable holds the game

	cout << endl << endl << endl << endl << endl;
	cout << "Welcome to Othello!" << endl;
	cout << "Input moves as column letter and then row number" << endl;
	cout << "Pass twice to end the game.  Whoever has the most pieces then wins." << endl;

	match.play();  //This function allows te user to make a single move

	cout << endl << endl << "BLACK HAS " << match.count_black() << " PIECES." << endl;
	cout << "WHITE HAS " << match.count_white() << " PIECES." << endl;
	if (match.count_black() > match.count_white()) {
		cout << "BLACK WINS!" << endl << endl;
	}
	else if (match.count_black() < match.count_white()) {
		cout << "WHITE WINS!" << endl << endl;
	}
	else {
		cout << "THE MATCH WAS A DRAW!" << endl << endl;
	}

	return 1;

}