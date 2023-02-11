# Description

This is a search and replace application. The goal is to find a user-specified text string within a group 
of disk files, modify those strings and update the original disk files, and then provide a report that 
indicates what has been done.

## Details

The application takes a single command argument. This argument will be 
interpreted as a text string. For example, if the program was called replace.exe, you 
might enter replace.exe apple

Then, each of the files in the current directory will be accessed and checked.

Header files used are:

<stdio.h> 

<dirent.h> 

<unistd.h> 

<sys/types.h> 

<string.h> 

<ctype.h> 

<stdlib.h> 
