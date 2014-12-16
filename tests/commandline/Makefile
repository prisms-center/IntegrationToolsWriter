# make PFunction src

HOME = ../..
PLIB = $(HOME)/tests/testlib
FW = $(HOME)/src/fw/fw
BSW = $(HOME)/src/bsw/bsw

test : $(PLIB)/MyFunc.hh $(PLIB)/MyPieceWiseFunc.hh $(PLIB)/Monomial.hh $(PLIB)/Chebyshev.hh $(PLIB)/libpextern.so

$(PLIB)/MyFunc.hh: 
	$(FW) -n "MyFunc" -v "x" "y" -d "x variable" "y variable"  --sym "x^3 + x^2*y + x*y^2 + y^3" --grad --hess -l $(PLIB)

$(PLIB)/MyPieceWiseFunc.hh: 
	$(FW) -n "MyPieceWiseFunc" -v "x" "y" -d "x variable" "y variable"  --piecewise '[ {"func":"x","cond":["x<0"]},{ "func": "pow(x,2) + pow(y,2)", "cond":["pow(x,2) + pow(y,2)<0.5*0.5","x>=0"] }, { "func": "sqrt(pow(x,2) + pow(y,2)) - 0.25", "cond":["pow(x,2) + pow(y,2)>=0.5*0.5","x>=0"] } ]' --grad --hess -l $(PLIB)

$(PLIB)/Monomial.hh:
	$(BSW) -n "Monomial" -d "Monomials up to 30" -v "x" --index "i" -e "x^i" -m 30 --grad --hess -l $(PLIB)

$(PLIB)/Chebyshev.hh:
	$(BSW) -n "Chebyshev" -d "Chebyshev Polynomials up to term 30"  -v "x" -e "2*x*phi1 - phi0" --init "1.0" "x" --sym "phi0" "phi1" -m 30 --grad --hess -l $(PLIB)

$(PLIB)/libpextern.so:
	lw -d $(PLIB) -v "std::vector<double>" "double*" -l $(PLIB) -c 

FORCE:

clean: 
	rm -f $(PLIB)/MyFunc.hh $(PLIB)/MyPieceWiseFunc.hh $(PLIB)/Monomial.hh $(PLIB)/Chebyshev.hh $(PLIB)/libpextern.so
