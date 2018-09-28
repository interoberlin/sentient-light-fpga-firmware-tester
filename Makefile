
PROJNAME = control


CPP = g++
LD = g++

CPPFLAGS += -g
CPPFLAGS += -Wall
CPPFLAGS += -Iinclude/

ELF = $(PROJNAME).elf

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)


all: $(ELF)

$(ELF): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

run: $(ELF)
	./$(ELF)

clean:
	rm -f $(OBJS) $(ELF)

