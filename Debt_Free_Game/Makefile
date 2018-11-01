debtSnowball: main.o DFSGame.o Janitor.o Player.o Expense.o Utilities.o
	g++ -std=c++0x main.o DFSGame.o Janitor.o Player.o Expense.o Utilities.o -o debtSnowball

main.o: main.cpp
	g++ -c -std=c++0x main.cpp

DFSGame.o: DFSGame.cpp DFSGame.hpp
	g++ -c -std=c++0x DFSGame.cpp

Janitor.o: Janitor.cpp Janitor.hpp
    g++ -c -std=c++0x Janitor.cpp

Player.o: Player.cpp Player.hpp
    g++ -c -std=c++0x Player.cpp

Expense.o: Expense.cpp Expense.hpp
    g++ -c -std=c++0x Expense.cpp

Utilities.o: Utilities.cpp Utilities.hpp
    g++ -c -std=c++0x Utilities.cpp

clean:
	rm *.o debtSnowball
