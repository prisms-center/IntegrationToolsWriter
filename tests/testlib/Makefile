# make pextern.dylib

HOME = ../..
INCLUDE = . 
PExtern = ./PExtern.cc

INSTALL = /usr/local/bin

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 -fPIC


libpextern.so: PExtern.o PLibrary.o
	@#$(CXX) -o libpextern.dylib $(PExtern) PLibrary.o -dynamiclib $(CPPFLAGS)
	$(CXX) -shared -o libpextern.so PExtern.o PLibrary.o 

PExtern.o: $(PExtern)
	$(CXX) -c $(PExtern) $(CPPFLAGS)

PLibrary.o: 
	cd ../commandline && $(MAKE)
	g++ -c PLibrary.cc $(CPPFLAGS)

FORCE:

clean: 
	rm -f *.o *.so *.hh
