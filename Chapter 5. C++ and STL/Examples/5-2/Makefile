CC = g++

FILE = 5-2
OBJS = 5-2.o

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