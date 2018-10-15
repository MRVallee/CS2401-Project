game: main.o game.o piece.o othello.o
	g++ -Wall main.o game.o piece.o othello.o -o game

main.o: game.h othello.h colors.h
	g++ -Wall -c main.cc

game.o: game.h
	g++ -Wall -c game.cc

piece.o: piece.h
	g++ -Wall -c piece.cc

othello.o: othello.h game.h colors.h
	g++ -Wall -c othello.cc

clean:
	rm -f game main.o game.o othello.o piece.o
