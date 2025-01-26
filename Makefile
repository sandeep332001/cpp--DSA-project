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


#project-folder/
#├── Graph/
#│   ├── main.cpp
#│   ├── graph.cpp
#│   ├── Makefile
#├── include/
#│   ├── include.h
#│   ├── module2.h
#├── lib/
#│   ├── 
#└── Makefile
#└── vars.make
#


.PHONY : all graph tree

all : graph tree

graph:
	cd Graph/ && make

tree:
	cd Tree/ && make

clean:
	rm sandy_graph sandy_tree
	cd Graph/ && make clean
	cd Tree/ && make clean

