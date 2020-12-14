#include "FileHandler.h"

FileHandler::FileHandler(string name) {
    //user prompted stuff
    char input;
    cout << "Would you like to generate numbers? (Y/N)" << endl;
    cin >> input;
    if (input == 'Y' || input == 'y') {
        cout << "How many numbers would you like? (max 1 million)" << endl;
        int num;
        cin >> num;
        if (num > 0 && num <= 1000000) {
            generateRandNums(num, name);
        }
        else {
            generateRandNums(10000, name); //default is 10000
        }
    }

    lineCounter = 0;
    ifstream myFile(name);
    string x;
    if (myFile.is_open()) {
        while (getline(myFile, x)) {
            lineCounter++;
        }
        myFile.close();
    }
    else {
        cout << "Error opening file." << endl;
        return;
    }

    data = new double*[5];
    for (int i = 0; i < 5; ++i) {
        data[i] = new double[lineCounter];
    }

    myFile.open(name);
    if (myFile.is_open()) {    //enter the info into the array
        int count = 0;
        while (getline(myFile, x)) {
            data[0][count++] = stod(x);
        }
    }
    myFile.close();

    for (int i = 1; i < 5; ++i) {   //coppies orgional array to duplicates
        for (int j = 0; j < lineCounter; ++j) {
            data[i][j] = data[0][j];
        }
    }
}

FileHandler::~FileHandler() {
    //deallocated the array :)
    for (int i = 0; i < 5; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void FileHandler::sortAll() {
    quickInitial = time(nullptr);
    sorter.quickSort(data[0], 0, lineCounter-1);
    quickFinal = time(nullptr);
    quickDiff = quickFinal - quickInitial;

    mergeInitial = time(nullptr);
    sorter.mergeSort(data[1], 0, lineCounter-1);
    mergeFinal = time(nullptr);
    mergeDiff = mergeFinal - mergeInitial;

    selectionInitial = time(nullptr);
    sorter.selectionSort(data[2], lineCounter);
    selectionFinal = time(nullptr);
    selectionDiff = selectionFinal - selectionInitial;

    insertionInitial = time(nullptr);
    sorter.insertionSort(data[3], lineCounter);
    insertionFinal = time(nullptr);
    insertionDiff = insertionFinal - insertionInitial;

    bubbleInitial = time(nullptr);
    sorter.bubbleSort(data[4], lineCounter);
    bubbleFinal = time(nullptr);
    bubbleDiff = bubbleFinal - bubbleInitial;
}

void FileHandler::printResults() {
    cout << "---Quick Sort---" << endl;
    cout << "Initial Time: " << ctime(&quickInitial);
    cout << "Final Time: " << ctime(&quickFinal);
    cout << "Run Time: " << ctime(&quickDiff) << endl;

    cout << "---Merge Sort---" << endl;
    cout << "Initial Time: " << ctime(&mergeInitial);
    cout << "Final Time: " << ctime(&mergeFinal);
    cout << "Run Time: " << ctime(&mergeDiff) << endl;

    cout << "---Selection Sort---" << endl;
    cout << "Initial Time: " << ctime(&selectionInitial);
    cout << "Final Time: " << ctime(&selectionFinal);
    cout << "Run Time: " << ctime(&selectionDiff) << endl;

    cout << "---Insertion Sort---" << endl;
    cout << "Initial Time: " << ctime(&insertionInitial);
    cout << "Final Time: " << ctime(&insertionFinal);
    cout << "Run Time: " << ctime(&insertionDiff) << endl;

    cout << "---Bubble Sort---" << endl;
    cout << "Initial Time: " << ctime(&bubbleInitial);
    cout << "Final Time: " << ctime(&bubbleFinal);
    cout << "Run Time: " << ctime(&bubbleDiff) << endl;
}

void FileHandler::generateRandNums(int count, string fileName) {
    double lowerBound = 0;
    double upperBound = 10000;
    uniform_real_distribution<double> unif(lowerBound, upperBound); //this stuff from stacked overflow :)
    default_random_engine re;

    ofstream myFile(fileName);
    if (myFile.is_open()) {
        for (int i = 0; i < count; ++i) {
            double num = unif(re);
            myFile << num << endl;
        }
        myFile.close();
    }
    return;   
}