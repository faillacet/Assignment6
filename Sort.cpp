#include "Sort.h"

Sort::Sort() {
    
}

Sort::~Sort() {

}

void Sort::quickSort(double arr[], int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
    int part = partition(arr, lowIndex, highIndex);
    quickSort(arr, lowIndex, part-1);
    quickSort(arr, part+1, highIndex);
    }
}

int Sort::partition(double arr[], int lowIndex, int highIndex) {
    double pivot = arr[highIndex];
    int x = (lowIndex-1);
    for (int i = lowIndex; i <= highIndex-1; i++) {
        if (arr[i] < pivot) {
            x++;
            double temp = arr[x];
            arr[x] = arr[i];
            arr[i] = temp;
        }
    }
    double temp = arr[x+1];
    arr[x+1] = arr[highIndex];
    arr[highIndex] = temp;
    return (x + 1);
}

void Sort::mergeSort(double arr[], int l, int r) {
    if (l>=r) {
        return;
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void Sort::merge(double arr[], int l, int m, int r) {
    int n1 = (m-l+1);
    int n2 = (r-m);
    
    double *L = new double[n1]; //temp arrays
    double *R = new double[n2];
    for (int i=0;i<n1;i++) {    //copy to temps
        L[i] = arr[l+i];
    }
    for (int i=0; i<n2;i++) {
        R[i] = arr[m+1+i];
    }

    //merge the temps back into arr
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    //copy remaining elements of L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    //copy remaining elements of R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    //free up memory
    delete L;
    delete R;
}

void Sort::selectionSort(double arr[], int n) {
    int minIndex = 0;
    double tmp = 0;
    for (int i = 0; i < n-1; ++i) {
        minIndex = i;
        for (int j=i+1;j<n; ++j) {
            if (arr[j]<arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

void Sort::insertionSort(double arr[], int n) {
    for (int j = 1;j<n;++j) {
        double temp = arr[j];
        int k = j;
        while (k > 0 && arr[k-1]>=temp) {
            arr[k] = arr[k-1];
            --k;
        }
        arr[k]=temp;
    }
}

void Sort::bubbleSort(double arr[], int n) {
    for (int i = 0; i < n; ++i) {
        double temp = 0;
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j]=temp;
            }
        }
    }
}

void Sort::printArray(double arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
}
