/*************************************************************

Made By: Michael Vallee | mv836315@ohio.edu

The purpose of this file is to impliment the functions
in the othello class

Last Modified: 12/10/17

**************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "othello.h"
#include "game.h"
#include "colors.h"


namespace main_savitch_14 {

	//this function displays the game board to the user
	void othello::display_status() const {

		cout << endl << endl;

		cout << "     A    B    C    D    E    F    G    H" << endl << endl;

		for (std::size_t i = 1; i < 9; ++i) {
			for (std::size_t n = 0; n < 3; ++n) {
				if (n == 1) {
					cout << RESET << i << "  ";
				}
				else {
					cout << RESET << "   ";
				}
				for (std::size_t j = 1; j < 9; ++j) {

					if (i % 2 == 0) {
						if (j % 2 == 0) {
							if ((board[i][j].return_state() == 1) && (n == 1)) {
								cout << RESET << B_BLUE << WHITE << BOLD << "  @  ";
							}
							else if ((board[i][j].return_state() == -1) && (n == 1)) {
								cout << RESET << B_BLUE << BLACK << "  @  ";
							}
							else {
								cout << RESET << B_BLUE << "     ";
							}
						}
						else {
							if ((board[i][j].return_state() == 1) && (n == 1)) {
								cout << RESET << B_RED << WHITE << BOLD << "  @  ";
							}
							else if ((board[i][j].return_state() == -1) && (n == 1)) {
								cout << RESET << B_RED << BLACK << "  @  ";
							}
							else {
								cout << RESET << B_RED << "     ";
							}
						}
					}
					else {
						if (j % 2 == 0) {
							if ((board[i][j].return_state() == 1) && (n == 1)) {
								cout << RESET << B_RED << WHITE << BOLD << "  @  ";
							}
							else if ((board[i][j].return_state() == -1) && (n == 1)) {
								cout << RESET << B_RED << BLACK << "  @  ";
							}
							else {
								cout << RESET << B_RED << "     ";
							}
						}
						else {
							if ((board[i][j].return_state() == 1) && (n == 1)) {
								cout << RESET << B_BLUE << WHITE << BOLD << "  @  ";
							}
							else if ((board[i][j].return_state() == -1) && (n == 1)) {
								cout << RESET << B_BLUE << BLACK << "  @  ";
							}
							else {
								cout << RESET << B_BLUE << "     ";
							}
						}
					}

				}
				cout << RESET << endl;
			}
		}

		cout << RESET << endl;

	}

	//this function checks to see if the user's move is legal
	bool othello::is_legal(const std::string& move) {

		int c = (tolower(move[0]) - 'a' + 1);
		int r = move[1] - '0';

		//**********BLACK CHECK**********
		if (next_mover() == HUMAN) {
			//check if move is on board
			if (c <= 8 && c >= 1 && r <= 8 && r >= 1) {
				//check if move is on empty piece
				if (board[r][c].return_state() == 0) {
					//check is move is legal up
					if ((board[r - 1][c].return_state() == 1) && (r - 1 >= 1)) {
						int tmp = 2;
						while (true) {
							if ((board[r - tmp][c].return_state() == -1) && (r - tmp >= 1)) {
								return true;
							}
							else if ((board[r - tmp][c].return_state() == 0 || (r - tmp < 1))) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal down
					if ((board[r + 1][c].return_state() == 1) && (r + 1 <= 8)) {
						int tmp = 2;
						while (true) {
							if ((board[r + tmp][c].return_state() == -1) && (r + tmp <= 8)) {
								return true;
							}
							else if ((board[r + tmp][c].return_state() == 0 || (r + tmp > 8))) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal left
					if ((board[r][c - 1].return_state() == 1) && (c - 1 >= 1)) {
						int tmp = 2;
						while (true) {
							if ((board[r][c - tmp].return_state() == -1) && (c - tmp >= 1)) {
								return true;
							}
							else if ((board[r][c - tmp].return_state() == 0) || (c - tmp < 1)) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal right
					if ((board[r][c + 1].return_state() == 1) && (c + 1 <= 8)) {
						int tmp = 2;
						while (true) {
							if ((board[r][c + tmp].return_state() == -1) && (c + tmp <= 8)) {
								return true;
							}
							else if ((board[r][c + tmp].return_state() == 0) || (c + tmp > 8)) {
								break;
							}
							++tmp;
						}
					}
					//check is move is legal up left
					if ((board[r - 1][c - 1].return_state() == 1) && (r - 1 >= 1) && (c - 1 >= 1)) {
						int tmp = 2;
						while (true) {
							if ((board[r - tmp][c - tmp].return_state() == -1) && (r - tmp >= 1) && (c - tmp >= 1)) {
								return true;
							}
							else if ((board[r - tmp][c - tmp].return_state() == 0) || (r - tmp < 1) || (c - tmp < 1)) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal up right
					if ((board[r - 1][c + 1].return_state() == 1) && (r - 1 >= 1) && (c + 1 <= 8)) {
						int tmp = 2;
						while (true) {
							if ((board[r - tmp][c + tmp].return_state() == -1) && (r - tmp >= 1) && (c + tmp <= 8)) {
								return true;
							}
							else if ((board[r - tmp][c + tmp].return_state() == 0) || (r - tmp < 1) || (c + tmp > 8)) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal down left
					if ((board[r + 1][c - 1].return_state() == 1) && (r + 1 <= 8) && (c - 1 >= 1)) {
						int tmp = 2;
						while (true) {
							if ((board[r + tmp][c - tmp].return_state() == -1) && (r + tmp <= 8) && (c - tmp >= 1)) {
								return true;
							}
							else if ((board[r + tmp][c - tmp].return_state() == 0) || (r + tmp > 8) || (c - tmp < 1)) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal down right
					if ((board[r + 1][c + 1].return_state() == 1) && (r + 1 <= 8) && (c + 1 <= 8)) {
						int tmp = 2;
						while (true) {
							if ((board[r + tmp][c + tmp].return_state() == -1) && (r + tmp <= 8) && (c + tmp <= 8)) {
								return true;
							}
							else if ((board[r + tmp][c + tmp].return_state() == 0) || (r + tmp > 8) || (c + tmp > 8)) {
								break;
							}
							++tmp;
						}
					}
				}

			}

		}
		//**********WHITE CHECK**********
		else if (next_mover() == COMPUTER) {

			//check if move is on board
			if (c <= 8 && c >= 1 && r <= 8 && r >= 1) {
				//check if move is on empty piece
				if (board[r][c].return_state() == 0) {
					//check is move is legal up
					if ((board[r - 1][c].return_state() == -1) && (r - 1 >= 1)) {
						int tmp = 2;
						while (true) {
							if ((board[r - tmp][c].return_state() == 1) && (r - tmp >= 1)) {
								return true;
							}
							else if ((board[r - tmp][c].return_state() == 0 || (r - tmp < 1))) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal down
					if ((board[r + 1][c].return_state() == -1) && (r + 1 <= 8)) {
						int tmp = 2;
						while (true) {
							if ((board[r + tmp][c].return_state() == 1) && (r + tmp <= 8)) {
								return true;
							}
							else if ((board[r + tmp][c].return_state() == 0 || (r + tmp > 8))) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal left
					if ((board[r][c - 1].return_state() == -1) && (c - 1 >= 1)) {
						int tmp = 2;
						while (true) {
							if ((board[r][c - tmp].return_state() == 1) && (c - tmp >= 1)) {
								return true;
							}
							else if ((board[r][c - tmp].return_state() == 0) || (c - tmp < 1)) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal right
					if ((board[r][c + 1].return_state() == -1) && (c + 1 <= 8)) {
						int tmp = 2;
						while (true) {
							if ((board[r][c + tmp].return_state() == 1) && (c + tmp <= 8)) {
								return true;
							}
							else if ((board[r][c + tmp].return_state() == 0) || (c + tmp > 8)) {
								break;
							}
							++tmp;
						}
					}
					//check is move is legal up left
					if ((board[r - 1][c - 1].return_state() == -1) && (r - 1 >= 1) && (c - 1 >= 1)) {
						int tmp = 2;
						while (true) {
							if ((board[r - tmp][c - tmp].return_state() == 1) && (r - tmp >= 1) && (c - tmp >= 1)) {
								return true;
							}
							else if ((board[r - tmp][c - tmp].return_state() == 0) || (r - tmp < 1) || (c - tmp < 1)) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal up right
					if ((board[r - 1][c + 1].return_state() == -1) && (r - 1 >= 1) && (c + 1 <= 8)) {
						int tmp = 2;
						while (true) {
							if ((board[r - tmp][c + tmp].return_state() == 1) && (r - tmp >= 1) && (c + tmp <= 8)) {
								return true;
							}
							else if ((board[r - tmp][c + tmp].return_state() == 0) || (r - tmp < 1) || (c + tmp > 8)) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal down left
					if ((board[r + 1][c - 1].return_state() == -1) && (r + 1 <= 8) && (c - 1 >= 1)) {
						int tmp = 2;
						while (true) {
							if ((board[r + tmp][c - tmp].return_state() == 1) && (r + tmp <= 8) && (c - tmp >= 1)) {
								return true;
							}
							else if ((board[r + tmp][c - tmp].return_state() == 0) || (r + tmp > 8) || (c - tmp < 1)) {
								break;
							}
							++tmp;
						}
					}
					//check if move is legal down right
					if ((board[r + 1][c + 1].return_state() == -1) && (r + 1 <= 8) && (c + 1 <= 8)) {
						int tmp = 2;
						while (true) {
							if ((board[r + tmp][c + tmp].return_state() == 1) && (r + tmp <= 8) && (c + tmp <= 8)) {
								return true;
							}
							else if ((board[r + tmp][c + tmp].return_state() == 0) || (r + tmp > 8) || (c + tmp > 8)) {
								break;
							}
							++tmp;
						}
					}
				}

			}

		}

		return false;

	}

	//this function makes the momve that the user declared
	void othello::make_move(const std::string& move) {

		int c = (tolower(move[0]) - 'a' + 1);
		int r = move[1] - '0';
		bool done;

		//checks if player/computer passed.  If they did, "  " was passed in.
		if (move == "  ") {
			++pass_count;
		}
		else {
			pass_count = 0;
		}

		//**********BLACK TURN**********
		if (next_mover() == HUMAN) {

			board[r][c].assign_state(-1);

			//move black up
			if ((board[r - 1][c].return_state() == 1) && (r - 1 >= 1)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r - tmp][c].return_state() == -1) && (r - tmp >= 1)) {
						done = true;
						int run = r - tmp;
						for (int a = r - 1; a > run; --a) {
							board[a][c].flip();
						}
					}
					else if (board[r - tmp][c].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move black down
			if ((board[r + 1][c].return_state() == 1) && (r + 1 <= 8)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r + tmp][c].return_state() == -1) && (r + tmp <= 8)) {
						done = true;
						int run = r + tmp;
						for (int a = r + 1; a < run; ++a) {
							board[a][c].flip();
						}
					}
					else if (board[r + tmp][c].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move black left
			if ((board[r][c - 1].return_state() == 1) && (c - 1 >= 1)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r][c - tmp].return_state() == -1) && (c - tmp >= 1)) {
						done = true;
						int run = c - tmp;
						for (int a = c - 1; a > run; --a) {
							board[r][a].flip();
						}
					}
					else if (board[r][c - tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move black right
			if ((board[r][c + 1].return_state() == 1) && (c + 1 <= 8)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r][c + tmp].return_state() == -1) && (c + tmp <= 8)) {
						done = true;
						int run = c + tmp;
						for (int a = c + 1; a < run; ++a) {
							board[r][a].flip();
						}
					}
					else if (board[r][c + tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move black up left
			if ((board[r - 1][c - 1].return_state() == 1) && (r - 1 >= 1) && (c - 1 >= 1)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r - tmp][c - tmp].return_state() == -1) && (r - tmp >= 1) && (c - tmp >= 1)) {
						done = true;
						int run = r - tmp;
						for (int a = r - 1, b = c - 1; a > run; --a, --b) {
							board[a][b].flip();
						}
					}
					else if (board[r - tmp][c - tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move black up right
			if ((board[r - 1][c + 1].return_state() == 1) && (r - 1 >= 1) && (c + 1 <= 8)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r - tmp][c + tmp].return_state() == -1) && (r - tmp >= 1) && (c + tmp <= 8)) {
						done = true;
						int run = r - tmp;
						for (int a = r - 1, b = c + 1; a > run; --a, ++b) {
							board[a][b].flip();
						}
					}
					else if (board[r - tmp][c + tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move black down left
			if ((board[r + 1][c - 1].return_state() == 1) && (r + 1 <= 8) && (c - 1 >= 1)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r + tmp][c - tmp].return_state() == -1) && (r + tmp <= 8) && (c - tmp >= 1)) {
						done = true;
						int run = r + tmp;
						for (int a = r + 1, b = c - 1; a < run; ++a, --b) {
							board[a][b].flip();
						}
					}
					else if (board[r + tmp][c - tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move black down right
			if ((board[r + 1][c + 1].return_state() == 1) && (r + 1 <= 8) && (c + 1 <= 8)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r + tmp][c + tmp].return_state() == -1) && (r + tmp <= 8) && (c + tmp <= 8)) {
						done = true;
						int run = r + tmp;
						for (int a = r + 1, b = c + 1; a < run; ++a, ++b) {
							board[a][b].flip();
						}
					}
					else if (board[r + tmp][c + tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}

		}
		//**********WHITE MOVE**********
		else if (next_mover() == COMPUTER) {

			board[r][c].assign_state(1);

			//move white up
			if ((board[r - 1][c].return_state() == -1) && (r - 1 >= 1)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r - tmp][c].return_state() == 1) && (r - tmp >= 1)) {
						done = true;
						int run = r - tmp;
						for (int a = r - 1; a > run; --a) {
							board[a][c].flip();
						}
					}
					else if (board[r - tmp][c].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move white down
			if ((board[r + 1][c].return_state() == -1) && (r + 1 <= 8)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r + tmp][c].return_state() == 1) && (r + tmp <= 8)) {
						done = true;
						int run = r + tmp;
						for (int a = r + 1; a < run; ++a) {
							board[a][c].flip();
						}
					}
					else if (board[r + tmp][c].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move white left
			if ((board[r][c - 1].return_state() == -1) && (c - 1 >= 1)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r][c - tmp].return_state() == 1) && (c - tmp >= 1)) {
						done = true;
						int run = c - tmp;
						for (int a = c - 1; a > run; --a) {
							board[r][a].flip();
						}
					}
					else if (board[r][c - tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move white right
			if ((board[r][c + 1].return_state() == -1) && (c + 1 <= 8)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r][c + tmp].return_state() == 1) && (c + tmp <= 8)) {
						done = true;
						int run = c + tmp;
						for (int a = c + 1; a < run; ++a) {
							board[r][a].flip();
						}
					}
					else if (board[r][c + tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move white up left
			if ((board[r - 1][c - 1].return_state() == -1) && (r - 1 >= 1) && (c - 1 >= 1)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r - tmp][c - tmp].return_state() == 1) && (r - tmp >= 1) && (c - tmp >= 1)) {
						done = true;
						int run = r - tmp;
						for (int a = r - 1, b = c - 1; a > run; --a, --b) {
							board[a][b].flip();
						}
					}
					else if (board[r - tmp][c - tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move white up right
			if ((board[r - 1][c + 1].return_state() == -1) && (r - 1 >= 1) && (c + 1 <= 8)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r - tmp][c + tmp].return_state() == 1) && (r - tmp >= 1) && (c + tmp <= 8)) {
						done = true;
						int run = r - tmp;
						for (int a = r - 1, b = c + 1; a > run; --a, ++b) {
							board[a][b].flip();
						}
					}
					else if (board[r - tmp][c + tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move white down left
			if ((board[r + 1][c - 1].return_state() == -1) && (r + 1 <= 8) && (c - 1 >= 1)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r + tmp][c - tmp].return_state() == 1) && (r + tmp <= 8) && (c - tmp >= 1)) {
						done = true;
						int run = r + tmp;
						for (int a = r + 1, b = c - 1; a < run; ++a, --b) {
							board[a][b].flip();
						}
					}
					else if (board[r + tmp][c - tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}
			//move white down right
			if ((board[r + 1][c + 1].return_state() == -1) && (r + 1 <= 8) && (c + 1 <= 8)) {
				done = false;
				int tmp = 2;
				while (done != true) {
					if ((board[r + tmp][c + tmp].return_state() == 1) && (r + tmp <= 8) && (c + tmp <= 8)) {
						done = true;
						int run = r + tmp;
						for (int a = r + 1, b = c + 1; a < run; ++a, ++b) {
							board[a][b].flip();
						}
					}
					else if (board[r + tmp][c + tmp].return_state() == 0) {
						done = true;
					}
					++tmp;
				}
			}

		}

		//inciments turn counter
		game::make_move(move);

	}

	//checks to see if the game was passed twice.  If so, it ends
	bool othello::is_game_over() const {

		if (pass_count >= 2) {
			return true;
		}
		return false;

	}

	//counts the number of pieces black has
	int othello::count_black() {

		int count = 0;

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (board[i][j].return_state() == -1) {
					++count;
				}
			}
		}

		return count;

	}

	//counts the number of pieces white has
	int othello::count_white() {

		int count = 0;

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (board[i][j].return_state() == 1) {
					++count;
				}
			}
		}

		return count;

	}

	int othello::evaluate() const {

		int count = 0;

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (board[i][j].return_state() == 1) {
					++count;
				}
			}
		}

		return count;

	}

	void othello::compute_moves(std::queue<std::string>& moves) {

		string tmp;
		string tmp_r;
		string tmp_c;
		bool have_move = false;

		for (char i = '1'; i < '9'; ++i) {
			for (char j = 'a'; j < 'i'; ++j) {

				tmp_c = string(1, j);
				tmp_r = string(1, i);
				tmp = tmp_c + tmp_r;

				//cout << endl << endl << "tmp = " << tmp << endl << endl;

				if (is_legal(tmp) == true) {
					moves.push(tmp);
					have_move = true;
				}

			}
		}

		if (have_move == false) {
			++pass_count;
			//cout << endl << endl << "The Computer has no valid moves.  They pass." << endl << endl;
		}

	}


}