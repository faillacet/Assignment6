#include "Sort.h"
#include "FileHandler.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string input;
    if (argc > 1) {
		cout << "Opening: " << argv[1] << endl;
		input = argv[1];
	}
	else {
		cout << "Enter File Name: " <<endl;		// used in case of no file name recieved from terminal
		cin >> input;
	}

    FileHandler test(input);
	test.sortAll();
	test.printResults();


    return 0;
}