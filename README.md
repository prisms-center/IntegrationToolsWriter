IntegrationToolsWriter
================

The IntegrationToolsWriter consists of two command line programs: 'fw', the function writer, and 'bsw', the basis set writer which generate code in the IntegrationTools format (PFunction, PBasisSet, etc.) from symbolic expressions using GiNaC.

IntegrationTools: https://github.com/prisms-center/IntegrationTools

Boost is used for program_options, filesystem, and regex: http://www.boost.org/

The function and basis set writers require GiNaC: http://www.ginac.de/


Usage
=======================

Integration Tools specifies an interface for easily passing functions to a computer program. It is written in C++, but also provides a C interface so that functions can be used across coding languages.  It includes a Python package 'pfunction' that uses the C interface to allow access to your functions in Python. 

The intended usage is something like this:

1) You write a program that you wish to pass functions into without knowing their form ahead of time.

2) You write the code for the functions themselves, either by hand or using a code generation tool (such as IntegrationToolsWriter) to generate code from symbolic mathematical expressions.

3) You compile the functions into a library and link it with your code.

4) Run it!


Installation
=======================

See 'INSTALL.txt' file.


Release Notes
=======================

Release 0.1.0 will include:
- The code writers: fw, bsw
    - with input and output as 'double' only

