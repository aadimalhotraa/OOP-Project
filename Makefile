CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = main.cpp \
      Character.cpp \
      Fire.cpp FireFox.cpp LavaLion.cpp \
      Water.cpp SeaSerpent.cpp Shark.cpp \
      Light.cpp ThunderBat.cpp LuminousAngel.cpp \
      Dark.cpp Demon.cpp DarkKnight.cpp \
      Grass.cpp RockTurtle.cpp PredatoryButterfly.cpp

OBJ = $(SRC:%.cpp=build/%.o)

game: $(OBJ)
	$(CXX) $(CXXFLAGS) -o game $(OBJ)

# Rule: put .o files in build/ folder
build/%.o: %.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the build/ folder if it doesn’t exist
build:
	mkdir -p build

clean:
	rm -rf build game.exe game