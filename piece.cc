/*************************************************************

Made By: Michael Vallee | mv836315@ohio.edu

The purpose of this file is to impliment the functions
in the piece class

Last Modified: 11/27/17

**************************************************************/

#include <iostream>
#include "piece.h"

using namespace std;


//this function assigns the state of a piece
void piece::assign_state(int a) {

	if (a == 1) {
		state = 1;
	}
	else if (a == -1) {
		state = -1;
	}
	else if (a == 0) {
		state = 0;
	}
	else {
		return;
	}

}

//this function flips a piece
void piece::flip() {

	if (state == -1) {
		state = 1;
	}
	else if (state == 1) {
		state = -1;
	}
	else {
		return;
	}

}