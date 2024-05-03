# name: Darion and Ethan
# lab: AS04
# purpose: Makefile that moves .o and executable files

.PHONY: recursive clean install 

recursive:
	cd src && make 
	cd src && mv *.o ../obj
	cd src && mv orun ../bin

clean:
	cd bin && rm orun
	cd obj && rm *.o

install:
	cd src && doxygen dconfig
