all: output run

output: ./out/*.o
	g++ ./out/*.o -o ./out/game.exe -L src/lib -l sfml-graphics -l sfml-window -l sfml-audio -l sfml-system -l openal32

./out/main.o: main.cpp
	g++ -I src/include -c main.cpp -o ./out/main.o

./out/Game.o: ./Engine/Game.cpp
	g++ -I src/include -c ./Engine/Game.cpp -o ./out/Game.o

./out/Token.o: ./Entities/Token.cpp
	g++ -I src/include -c ./Entities/Token.cpp -o ./out/Token.o

./out/Hitbox.o: ./DataStructures/Hitbox.cpp
	g++ -I src/include -c ./DataStructures/Hitbox.cpp -o ./out/Hitbox.o

./out/DeltaTime.o: ./DataStructures/DeltaTime.cpp
	g++ -I src/include -c ./DataStructures/DeltaTime.cpp -o ./out/DeltaTime.o

./out/TokenHandler.o: ./Engine/TokenHandler.cpp
	g++ -I src/include -c ./Engine/TokenHandler.cpp -o ./out/TokenHandler.o

./out/Character.o: ./Entities/Character.cpp
	g++ -I src/include -c ./Entities/Character.cpp -o ./out/Character.o

run:
	./out/game.exe