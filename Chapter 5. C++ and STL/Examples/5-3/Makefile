CC = g++

FILE = 5-3
OBJS = 5-3.o

ifeq ($(ver), debug)
	CXXFLAGS += -g
else
	CXXFLAGS += -O3 
endif

$(FILE): $(FILE).cpp
	$(CC) $(CXXFLAGS) -o $@ $<
	
.PHONY: clean
clean:
	rm -fr $(FILE) $(OBJS)