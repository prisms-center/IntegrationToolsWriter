# make command line interface program: fw

HOME = ../..
#TOOLS = /usr/local/include/IntegrationTools
WRITER = $(HOME)/include/IntegrationToolsWriter
INCLUDE = . $(HOME)/include $(WRITER)


ifeq "$(BIN)" ""
	INSTALL = /usr/local/bin
else
	INSTALL = $(BIN)
endif


ifeq "$(BOOST)" ""
	LFLAGS = -lboost_program_options -lboost_filesystem -lboost_system -lboost_regex
else
	BOOSTLIB = libboost_filesystem.so libboost_program_options.so libboost_regex.so libboost_system.so
	LFLAGS += $(foreach i, $(BOOSTLIB), $(BOOST)/lib/$(i))
	INCLUDE += $(BOOST)/include
endif


LFLAGS_G = $(LFLAGS)
ifeq "$(GINAC)" ""
	LFLAGS_G += -lcln -lginac
else
	INCLUDE += $(GINAC)/include
	LFLAGS_G += $(GINAC)/lib/libginac.so $(GINAC)/lib/libcln.so
endif


CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 


fw: fw.cpp ../version.o PFunctionWriter.o 
	$(CXX) PFunctionWriter.o ../version.o -o fw fw.cpp $(CPPFLAGS) $(LFLAGS_G)


install: fw
	install fw $(INSTALL)


uninstall:
	rm $(INSTALL)/fw


../version.o:
	cd .. && $(MAKE) version.o


PFunctionWriter.o: PFunctionWriter.cc $(WRITER)/writer/PFunctionWriter.hh ../version.cc
	$(CXX) -c PFunctionWriter.cc $(CPPFLAGS)


clean: 
	rm -f *.o fw

