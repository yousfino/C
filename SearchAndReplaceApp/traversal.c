#ifndef TRAVERSALFILE_C
#define TRAVERSALFILE_C
#include "report.h"
#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

//method to get current directory path and display it
int getCurrentDirPath(const char *d) {
    char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   return 0;
}

void searchDirectory(const char *d) {
    //open the main directory to be traversed
    DIR* directory = opendir(d);
    //check if directory does not have files anymore to successfully terminate the method
    if (directory == NULL) {
        return;
    }
    //declare and assign a pointer to iterate
    //through the files in the main/current directory
    struct dirent* pointer;
    pointer = readdir(directory);
    //while the current directory still has files to traverse
    while (pointer != NULL) {
        //using this to help in checking if a file is directory or not
        struct stat path_stat;
        stat(pointer->d_name, &path_stat);
        int length = strlen(pointer->d_name);
            
        //check if current entity points to a txt file by checking
        //the 4 last characters of the file name if they match ".txt"
        if(strncmp(pointer->d_name + length - 4, ".txt", 4) == 0) {
            //if match, get the file path
            char newFilePath[2000] = {0};
            strcat(newFilePath, d);
            strcat(newFilePath, "/");
            strcat(newFilePath, pointer->d_name);
            //after getting the text file path, access it and change
            //characters into uppercase
            toUpperCase(newFilePath, targetString);
        }
        //check if current entity points to a directory by checking
        //the path of the file the pointer is currently pointing to
        if (S_ISDIR(path_stat.st_mode)) {
            //if directory, make sure it is not the same current
            //directory "." or the previous directory ".."
            if ((strcmp(pointer->d_name, ".")) != 0 && strcmp(pointer->d_name, "..") != 0) {
                //create an array of characters to store the path
                //of the directory
                char newDirPath[2000] = {0};
                //get current directory path, and add "/" followed
                //by the name of the nested directory
                strcat(newDirPath, d);
                strcat(newDirPath, "/");
                strcat(newDirPath, pointer->d_name);
                //recurse using the new directory path
                searchDirectory(newDirPath);
            }
        }
        //go to next file to check
        pointer = readdir(directory);
    }
    closedir(directory);
}
#endif