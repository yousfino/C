#ifndef REPORTFILE_C
#define REPORTFILE_C
#include "report.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//print the report with number of changes made per each file
//along with the corresponding file name next to the number
void printReport(int numOfUpdates, char fileName[]) {
    printf("%d          %s\n", numOfUpdates, fileName);
}
#endif