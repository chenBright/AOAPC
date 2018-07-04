CC = g++

FILE = 5-5
OBJS = 5-5.o

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