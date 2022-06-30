all: output run

build:
	g++ -I src/include -c main.cpp ./DataStructures/*.cpp ./Engine/*cpp ./Entities/*.cpp ./Map/*.cpp ./Skills/*.cpp

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

./out/Inventory.o: ./DataStructures/Inventory.cpp
	g++ -I src/include -c ./DataStructures/Inventory.cpp -o ./out/Inventory.o

./out/TokenHandler.o: ./Engine/TokenHandler.cpp
	g++ -I src/include -c ./Engine/TokenHandler.cpp -o ./out/TokenHandler.o

./out/Character.o: ./Entities/Character.cpp
	g++ -I src/include -c ./Entities/Character.cpp -o ./out/Character.o

./out/Player.o: ./Entities/Player.cpp
	g++ -I src/include -c ./Entities/Player.cpp -o ./out/Player.o

./out/Map.o: ./Map/Map.cpp
	g++ -I src/include -c ./Map/Map.cpp -o ./out/Map.o

./out/Tile.o: ./Map/Tile.cpp
	g++ -I src/include -c ./Map/Tile.cpp -o ./out/Tile.o

./out/Skill.o: ./Skills/Skill.cpp
	g++ -I src/include -c ./Skills/Skill.cpp -o ./out/Skill.o

./out/Firewall.o: ./Skills/Firewall.cpp
	g++ -I src/include -c ./Skills/Firewall.cpp -o ./out/Firewall.o

run:
	./out/game.exe