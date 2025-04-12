# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude

# Directories
OBJDIR = obj
SRCDIR = src
INCDIR = include

# Files
SRC = main.cpp src/algorithms.cpp src/movie.cpp src/util.cpp src/movieDatabase.cpp src/dataParser.cpp
OBJ = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

# Output executable
EXEC = MovieRecommender

# Rules
all: $(OBJDIR) $(EXEC)

# Ensure the obj directory structure exists
$(OBJDIR)/src:
	mkdir -p $(OBJDIR)/src

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Compile .cpp files to .o files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)/src
	@echo "Compiling $< to $@"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJDIR) $(EXEC)
