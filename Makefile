all: output run

build:
	g++ -I src/include -c main.cpp ./DataStructures/*.cpp ./Engine/*cpp ./Entities/*.cpp ./Map/*.cpp ./Skills/*.cpp ./Animation/*.cpp ./UI/*.cpp

output: *.o
	g++ *.o -o game.exe -L src/lib -l sfml-graphics -l sfml-window -l sfml-audio -l sfml-system -l openal32

./main.o: main.cpp
	g++ -I src/include -c main.cpp -o main.o

./Game.o: ./Engine/Game.cpp
	g++ -I src/include -c ./Engine/Game.cpp -o Game.o

./Token.o: ./Entities/Token.cpp
	g++ -I src/include -c ./Entities/Token.cpp -o Token.o

./Hitbox.o: ./DataStructures/Hitbox.cpp
	g++ -I src/include -c ./DataStructures/Hitbox.cpp -o Hitbox.o

./DeltaTime.o: ./DataStructures/DeltaTime.cpp
	g++ -I src/include -c ./DataStructures/DeltaTime.cpp -o DeltaTime.o

./Inventory.o: ./DataStructures/Inventory.cpp
	g++ -I src/include -c ./DataStructures/Inventory.cpp -o Inventory.o

./TokenHandler.o: ./Engine/TokenHandler.cpp
	g++ -I src/include -c ./Engine/TokenHandler.cpp -o TokenHandler.o

./Character.o: ./Entities/Character.cpp
	g++ -I src/include -c ./Entities/Character.cpp -o Character.o

./Player.o: ./Entities/Player.cpp
	g++ -I src/include -c ./Entities/Player.cpp -o Player.o

./Map.o: ./Map/Map.cpp
	g++ -I src/include -c ./Map/Map.cpp -o Map.o

./Tile.o: ./Map/Tile.cpp
	g++ -I src/include -c ./Map/Tile.cpp -o Tile.o

./Skill.o: ./Skills/Skill.cpp
	g++ -I src/include -c ./Skills/Skill.cpp -o Skill.o

./Firewall.o: ./Skills/Firewall.cpp
	g++ -I src/include -c ./Skills/Firewall.cpp -o Firewall.o

./Animation.o: ./Animation/Animation.cpp
	g++ -I src/include -c ./Animation/Animation.cpp -o Animation.o

./UI.o: ./UI/UI.cpp
	g++ -I src/include -c ./UI/UI.cpp -o UI.o

run:
	./game.exe