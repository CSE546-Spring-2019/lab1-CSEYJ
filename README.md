# lab 1

## Description
Author: CSEYJ (Yongjeong Kim).
This program takes a string to search and names of an input file and an output file, printing a number of occurrences to a screen and the output file.

## Commands to compile and run
In order to compile a file, at the file directory, type 
```
make
```

In order to run a file, at the file directory, type
```
./count <a name of the input file> <a string to search> <a name of the ouput file>
```
The size of the string should be equal to or less than 20 bytes and greater than 0 bytes.

## Files
README.md:
* A text file containing an information of these lab 1 files.

count.c:
* A c code file that prints out the size of the input file and the number of occurrences of "search string" in the file to the output file and screen.

makefile:
* This file contains codes to compile count.c file and remove remove a created count file.
