# project-folder/
#	├── clean   <-- This is an actual file (maybe created by mistake)
#	├── main.cpp
#	├── Makefile
#	└── utils.cpp
#
# Since there's a real file named clean, make might think "Oh, clean is already up to date", and it won't run the rm command. Instead, it will just assume the clean target is done because the file already exists.
#
# If you add .PHONY to your Makefile: 
#	Now when you run make clean, it will ignore the file named clean and always execute the rm command to delete files.
#

include ./../vars.make

INCLUDE = -I ./../include/
  # -c only compile, -Wall all warning show

OBJS = main.o 
OBJS += graph.o

all: sandy_graph

sandy_graph: $(OBJS)
	$(CC) $(OBJS) -o $@
	cp sandy_graph ~/programs/

main.o: main.cpp graph.cpp
	$(CC) $(CFLAGS) $(INCLUDE) *.cpp
	
#graph:
#	cd ./Graph && make

clean:
	rm $(OBJS) sandy_graph
	