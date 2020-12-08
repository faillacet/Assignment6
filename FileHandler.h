#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Sort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class FileHandler {
private:
    Sort sorter;
    double **data;      //dynamically allocated array that stores data from file
    int lineCounter;    //used to see how big we need to make array
    //timing
    time_t quickInitial, quickFinal, quickDiff;
    time_t mergeInitial, mergeFinal, mergeDiff;
    time_t selectionInitial, selectionFinal, selectionDiff;
    time_t insertionInitial, insertionFinal, insertionDiff;
    time_t bubbleInitial, bubbleFinal, bubbleDiff;
public:
    FileHandler(string name);
    ~FileHandler();
    void sortAll();
    void printResults();
};

#endif