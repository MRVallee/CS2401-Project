/*************************************************************

Made By: Michael Vallee | mv836315@ohio.edu

The purpose of this file is to declare the othello
class

Last Modified: 12/10/17

**************************************************************/

#ifndef OTHELLO_H
#define OTHELLO_H

#include <iostream>
#include <string>
#include <queue>
#include "game.h"
#include "piece.h"

namespace main_savitch_14 {

	class othello : public game {

	public:

		othello() {
			pass_count = 0;
			for (std::size_t i = 0; i < 10; ++i) {
				for (std::size_t j = 0; j < 10; ++j) {
					board[i][j].assign_state(0);
				}
			}
			board[4][4].assign_state(1);
			board[4][5].assign_state(-1);
			board[5][5].assign_state(1);
			board[5][4].assign_state(-1);
		}

		void make_move(const std::string& move);
		void restart() { return; }
		game* clone() const {
			return new othello(*this);
		}
		void compute_moves(std::queue<std::string>& moves);
		void display_status() const;
		int evaluate() const;
		bool is_game_over() const;
		bool is_legal(const std::string& move);
		int count_black();
		int count_white();

	private:

		piece board[10][10]; //this is the game board.
		int pass_count;

	};

}

#endif