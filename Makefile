output: main.o GlobalVar.o Bot.o
	g++ main.o GlobalVar.o Bot.o -o TicTacToe -static

main.o: main.o
	g++ -c main.cpp

GlobalVar.o: GlobalVar.cpp Global
	g++ -c GlobalVar.cpp

Bot.o: Bot.cpp Global
	g++ -c Bot.cpp

clean:
	del *.o
