#ifndef SORT_H
#define SORT_H

#include <iostream>
using namespace std;

class Sort {
private:
    
public:
    Sort();
    ~Sort();
    //sorting algorithms
    void quickSort(double arr[], int lowIndex, int highIndex);
    void mergeSort(double arr[], int l, int r);
    void selectionSort(double arr[], int n);
    void insertionSort(double arr[], int n);
    void bubbleSort(double arr[], int n);

    void printArray(double arr[], int n);

    //quick sort helper function
    int partition(double arr[], int lowIndex, int highIndex);
    //merge sort helper function
    void merge(double arr[], int l, int m, int r);


    void runAll();
};

#endif