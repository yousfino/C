#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include "traversal.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
//getting target string from user input
for (int i = 1; i < argc; i++) {
        strcat(targetString, argv[i]);
    }
    //display sample output format as shown in the assignment instructions
    printf("Target string: %s\n", targetString);
    printf("Search begins in current folder: ");
    //get and display current directory path
    getCurrentDirPath(".");
    printf("\n");
    printf("** Search Report **\n\n");
    printf("Updates     File Name\n");
    printf("-------     ---------\n");
    //passing the path of the current directory, which is "."
    searchDirectory(".");

    return 0;
}