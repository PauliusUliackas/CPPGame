all: output run

output: ./out/*.o
	g++ ./out/*.o -o ./out/game.exe -L src/lib -l sfml-graphics -l sfml-window -l sfml-audio -l sfml-system -l openal32

./out/main.o: main.cpp
	g++ -I src/include -c main.cpp -o ./out/main.o

./out/Game.o: ./Engine/Game.cpp
	g++ -I src/include -c ./Engine/Game.cpp -o ./out/Game.o

run:
	./out/game.exe