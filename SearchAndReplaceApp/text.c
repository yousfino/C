#ifndef TEXTFILE_C
#define TEXTFILE_C
#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

//declare globar char array to store
char targetString[2000];

void toUpperCase(char fName[], char string[]) {
    //opening current file the pointer is pointing add to read from
    FILE *targetFile = fopen(fName, "r");
    //creating a temp file to write the contents of the current file
    //to it with the updated target string (ti uppercase)
    FILE *temp = fopen("temp.txt", "w");

    int index = 0;
    int counter = 0;
    //creating a char array to store the updated target string
    char strToChange[2000];
    //checking that the scanner is not reaching the end of the file
    while (fscanf(targetFile, "%s", strToChange) != EOF) {
        //checking if the target string matches with a string inside the file
        if(strcasecmp(strToChange, targetString) == 0) {
            counter++;
                //if matches, convert into uppercase and store in the temp file
                while (strToChange[index]) {
                    fputc(toupper(strToChange[index]), temp);
                    index++;
                }
                fputs(" ", temp);
        //if a string does not match with the target string, just add it to the
        //temp file without updating it
        } else {
            fputs(strToChange, temp);
            fputs(" ", temp);
        }
        index = 0;
    }
    //calling the printReport method to execute the update result
    printReport(counter, fName);
    counter = 0;
    fclose(targetFile);
    fclose(temp);
    //save the created&updated temp file as the current text file
    //and delete the current text file
    rename("temp.txt", fName);
    remove("temp.txt");
}
#endif