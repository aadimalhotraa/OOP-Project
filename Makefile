# ---- config ----
CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -O2
LDFLAGS  ?=

TARGET   := oopmon
BUILDDIR := build

# List ALL your .cpp files here
SRC := \
  main.cpp \
  Character.cpp Attribute.cpp Ability.cpp \
  Fire.cpp FireFox.cpp LavaLion.cpp FireMoves.cpp \
  Water.cpp Shark.cpp SeaSerpent.cpp WaterMoves.cpp \
  Grass.cpp RockTurtle.cpp PredatoryButterfly.cpp GrassMoves.cpp \
  Dark.cpp Demon.cpp DarkKnight.cpp DarkMoves.cpp \
  Light.cpp ThunderBat.cpp LuminousAngel.cpp LightMoves.cpp

# ---- derived vars (don’t edit) ----
OBJ  := $(SRC:%=$(BUILDDIR)/%.o)
DEPS := $(OBJ:.o=.d)

# ---- default target ----
.PHONY: all
all: $(TARGET)

# ---- link step ----
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $@

# ---- compile step with dep gen ----
$(BUILDDIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# ---- convenience targets ----
.PHONY: run clean debug release
run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Rebuild with debug symbols and no optimizations
debug: CXXFLAGS += -O0 -g
debug: clean all

# Rebuild optimized
release: CXXFLAGS += -O3
release: clean all

# ---- include generated deps ----
-include $(DEPS)