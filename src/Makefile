# make command line interface programs: fs, bsw


VERS = "develop"
ID="id"
URL="url"
#ID=$$(git rev-parse HEAD)
#URL=$$(git config --get remote.origin.url)


CXX      = g++
#CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 


all: 
	cd fw && $(MAKE)
	cd bsw && $(MAKE)

install: version.o
	cd fw && $(MAKE) install
	cd bsw && $(MAKE) install
	

uninstall:
	cd fw && $(MAKE) uninstall
	cd bsw && $(MAKE) uninstall


version.cc: 
	@sed "s/VERSION_ID/$(VERS)/" version.template.cc > version.tmp.0
	@sed "s/COMMIT_ID/$(ID)/" version.tmp.0 > version.tmp.1; rm version.tmp.0
	@sed "s|REPO_URL|$(URL)|" version.tmp.1 > version.cc; rm version.tmp.1

version.o: version.cc 
	$(CXX) -c version.cc $(CPPFLAGS)


clean: 
	rm -f version.cc version.o
	cd fw && $(MAKE) clean
	cd bsw && $(MAKE) clean

