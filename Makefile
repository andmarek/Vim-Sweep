CXX = g++
ECHO = echo
CXXFLAGS = -Wall -Werror -ggdb3 -funroll-loops -DTERM=$(TERM)
LDFLAGS = -lncurses
RM = rm -f

BIN = minesweep
OBJS = board.o minesweep.o

all: $(BIN)

%.o: %.cpp
	@$(ECHO) Compiling $<
	@$(CXX) $(CXXFLAGS) -MMD -MF $*.d -c $<

.PHONY: = all clean

clean:
		@$(ECHO) Removing backup files.
		@$(RM) *.o $(BIN) *.d core vgcore.* gmon.out

