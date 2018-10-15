/*************************************************************

Made By: Michael Vallee | mv836315@ohio.edu

The purpose of this file is to declare the piece
class

Last Modified: 11/27/17

**************************************************************/

#ifndef PIECE_H
#define PIECE_H

#include <iostream>


class piece {

public:

	piece() {
		state = 0;
	}

	void assign_state(int a);
	int return_state() const { return state; }
	void flip();

private:

	int state; //0 for empty, 1 for white, and -1 for black

};

#endif