IntegrationToolsWriter
================

The IntegrationToolsWriter consists of two command line programs: the Function Writer, ``fw``, and the Basis Set Writer, ``bsw``, which generate code in the [IntegrationTools](https://github.com/prisms-center/IntegrationTools) format (PFunction, PBasisSet, etc.) from symbolic expressions using [GiNaC](http://www.ginac.de/).

This code is developed by the PRedictive Integrated Structural Materials Science Center (PRISMS), at the University of Michigan, which is supported by the U.S. Department of Energy, Office of Basic Energy Sciences, Division of Materials Sciences and Engineering under Award #DE-SC0008637.


Dependencies
============

- [IntegrationTools](https://github.com/prisms-center/IntegrationTools)
- [Boost](http://www.boost.org/) is used for the program_options, filesystem, and regex libraries.
- The function and basis set writers require [GiNaC](http://www.ginac.de/)
- Included as part of this software package: [JSON spirit, v4.06](http://www.codeproject.com/Articles/20027/JSON-Spirit-A-C-JSON-Parser-Generator-Implemented)


Installation
============

1. Clone the repository

        cd /path/to/
        git clone https://github.com/prisms-center/IntegrationToolsWriter.git
        cd IntegrationToolsWriter

2. From the root directory of the repository:

        make install

    You might need to set the following environment variables:
    	
    - BIN: This specifies where ``fw`` and ``bsw`` will be installed. If not set, the default location is ``/usr/local/bin``
    	
    - BOOST: This specifies where the Boost libraries are located. If not set, the default compiler search path is used.
    	
    - GINAC: This specifies where the GiNaC header files and libraries are located. They are expected to be found at $GINAC/include and $GINAC/lib, respectively. If not set, the default compiler search path are used.



Usage
=======================

For documentation see:

```
fw --help
```

and 

```
bsw --help
```


License
=======================

This directory contains the IntegrationToolsWriter code developed 
by the PRISMS Center at the University of Michigan, Ann Arbor, USA.

(c) 2014 The Regents of the University of Michigan

PRISMS Center http://prisms.engin.umich.edu 

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.



Release Notes
=======================

Release 1.0.0 will include:

- The Function Writer, fw
    - With only ``double`` OutType
- The Basis Writer, bsw
    - With only 'double' for InType and OutType

