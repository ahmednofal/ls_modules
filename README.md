# ls_modules
This is a solution to the programming project 2 - chapter 3 in the operating systems concepts text book 9th edition

The repo contain C source code files for kernel modules that list the tasks running in the order they have been created or in a DFS
order

The code hugely utilizes macros built in the linux kernel library

The code is compiled using the linux kernel Makefile in the linux kernel build folder, its path will differ from one machine to
another, but in this Makefile paths to the Makefile use the BASH variable MAKE and PWD for compatibility with other setups
