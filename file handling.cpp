#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "data.txt";  // File name
    string dataToWrite, dataRead;

    // Step 1: Create and open the file in output mode
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    // Step 2: Write information to the file
    cout << "Enter the information to write to the file: ";
    getline(cin, dataToWrite);
    outFile << dataToWrite << endl;

    // Close the file after writing
    outFile.close();
    cout << "Data written to file successfully.\n";

    // Step 3: Open the file in input mode to read the data
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    // Step 4: Read information from the file
    cout << "Reading data from file:\n";
    while (getline(inFile, dataRead)) {
        cout << dataRead << endl;
    }

    // Close the file after reading
    inFile.close();

    return 0;
}
