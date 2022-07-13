all: output run

build:
	g++ -I src/include -c main.cpp ./DataStructures/*.cpp ./Engine/*cpp ./Entities/*.cpp ./Map/*.cpp ./Skills/*.cpp ./Animation/*.cpp ./UI/*.cpp

output: *.o
	g++ *.o -o game.exe -L src/lib -l sfml-graphics -l sfml-window -l sfml-audio -l sfml-system -l openal32

./main.o: main.cpp
	g++ -I src/include -c main.cpp -o main.o

./Game.o: ./Engine/Game.cpp
	g++ -I src/include -c ./Engine/Game.cpp -o Game.o

./PlayerStats.o: ./Engine/PlayerStats.cpp
	g++ -I src/include -c ./Engine/PlayerStats.cpp -o PlayerStats.o

./Spawner.o: ./Engine/Spawner.cpp
	g++ -I src/include -c ./Engine/Spawner.cpp -o Spawner.o

./Token.o: ./Entities/Token.cpp
	g++ -I src/include -c ./Entities/Token.cpp -o Token.o

./Shop.o: ./Engine/Shop.cpp
	g++ -I src/include -c ./Engine/Shop.cpp -o Shop.o

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

./Enemy.o: ./Entities/Enemy.cpp
	g++ -I src/include -c ./Entities/Enemy.cpp -o Enemy.o

./Player.o: ./Entities/Player.cpp
	g++ -I src/include -c ./Entities/Player.cpp -o Player.o

./Swat.o: ./Entities/Swat.cpp
	g++ -I src/include -c ./Entities/Swat.cpp -o Swat.o

./Building.o: ./Entities/Building.cpp
	g++ -I src/include -c ./Entities/Building.cpp -o Building.o

./ExitPoint.o: ./Entities/ExitPoint.cpp
	g++ -I src/include -c ./Entities/ExitPoint.cpp -o ExitPoint.o

./Map.o: ./Map/Map.cpp
	g++ -I src/include -c ./Map/Map.cpp -o Map.o

./Tile.o: ./Map/Tile.cpp
	g++ -I src/include -c ./Map/Tile.cpp -o Tile.o

./Skill.o: ./Skills/Skill.cpp
	g++ -I src/include -c ./Skills/Skill.cpp -o Skill.o

./Firewall.o: ./Skills/Firewall.cpp
	g++ -I src/include -c ./Skills/Firewall.cpp -o Firewall.o

./Bazooka.o: ./Skills/Bazooka.cpp
	g++ -I src/include -c ./Skills/Bazooka.cpp -o Bazooka.o

./Healthpot.o: ./Skills/Healthpot.cpp
	g++ -I src/include -c ./Skills/Healthpot.cpp -o Healthpot.o

./Shield.o: ./Skills/Shield.cpp
	g++ -I src/include -c ./Skills/Shield.cpp -o Shield.o

./Database.o: ./Skills/Database.cpp
	g++ -I src/include -c ./Skills/Database.cpp -o Database.o

./Animation.o: ./Animation/Animation.cpp
	g++ -I src/include -c ./Animation/Animation.cpp -o Animation.o

./UI.o: ./UI/UI.cpp
	g++ -I src/include -c ./UI/UI.cpp -o UI.o

./Button.o: ./UI/Button.cpp
	g++ -I src/include -c ./UI/Button.cpp -o Button.o

./Menu.o: ./UI/Menu.cpp
	g++ -I src/include -c ./UI/Menu.cpp -o Menu.o

run:
	./game.exe