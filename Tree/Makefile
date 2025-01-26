# project-folder/
#	├── clean   <-- This is an actual file (maybe created by mistake)
#	├── main.cpp
#	├── Makefile
#	└── tree.cpp
#
# Since there's a real file named clean, make might think "Oh, clean is already up to date", and it won't run the rm command. Instead, it will just assume the clean target is done because the file already exists.
#
# If you add .PHONY to your Makefile: 
#	Now when you run make clean, it will ignore the file named clean and always execute the rm command to delete files.
#

include ./../vars.make

INCLUDE = -I ./../include/
  # -c only compile, -Wall all warning show

OBJS = tree.o
OBJS += main.o 

all: sandy_tree

sandy_tree: $(OBJS)
	$(CC) $(OBJS) -o $@
	cp sandy_tree ~/programs/

tree.o: tree.cpp
	$(CC) $(CFLAGS) $(INCLUDE) tree.cpp

main.o: main.cpp tree.cpp
	$(CC) $(CFLAGS) $(INCLUDE) main.cpp

clean:
	rm $(OBJS) sandy_tree
	