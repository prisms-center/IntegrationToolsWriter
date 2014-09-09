# make command line interface program: bsw

HOME = ../..
WRITER = $(HOME)/include/IntegrationToolsWriter
PSYM = $(HOME)/include/IntegrationToolsWriter/psymfunction
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


bsw: bsw.cpp ../version.o PBasisSetWriter.o ../fw/PFunctionWriter.o 
	$(CXX) PBasisSetWriter.o ../fw/PFunctionWriter.o ../version.o -o bsw bsw.cpp $(CPPFLAGS) $(LFLAGS_G)

install: bsw
	install bsw $(INSTALL)


uninstall:
	rm $(INSTALL)/bsw


../version.o:
	cd .. && $(MAKE) version.o


../fw/PFunctionWriter.o: 
	cd ../fw && $(MAKE) PFunctionWriter.o

PBasisSetWriter.o: PBasisSetWriter.cc $(PSYM)/PRealSymBasisFunction.hh $(PSYM)/PRealSymBasisSet.hh $(PSYM)/PRealSymRecursBasisSet.hh $(WRITER)/writer/* ../version.cc 
	$(CXX) -c PBasisSetWriter.cc $(CPPFLAGS)


clean: 
	rm -f *.o bsw



