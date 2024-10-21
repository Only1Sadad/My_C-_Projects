/**
 Programmer: Sadad Yusuf.
 Date: 09-23-24:
 Description: Functions and Arrays
    *Pseudocode
        -Create a function initArray that initializes a given array using this parameters (double array[],int size,initValue)
        -Create a function that prints an array of doubles to any output stream. One parameter of this function should be how many elements per output line (nPerLine) and one parameter should be how many decimal places (nDecimal).

    *In the main function of your program
        -create an array of 35 doubles.
        -Ask the user for  the default value to initialize the array.
        -Initialize the array.
        -then print the array to cout, 7 per line, to 2 decimal places.
        -Then, print the array to a file (yourname.txt), 5 per line, with 3 decimal places.

 *Avoid  any global variables, or any "while (true)" conditions.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Function to initialize the array with a given value
void initArray(double array[], int size, double initValue) {
    for (int i = 0; i < size; i++) {
        array[i] = initValue;
    }
}

// Function to print the array to console
void printArray(double array[], int size, int nPerLine, int nDecimal) {
    cout << fixed << setprecision(nDecimal);
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
        if ((i + 1) % nPerLine == 0) {
            cout << endl; // New line after nPerLine elements
        }
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // Declare the array and input variable
    double array[35];
    double valueInit;

    // Ask the user for a decimal number and validate input
    cout << "Enter any decimal point number of your choice (e.g., 1.50): ";
    cin >> valueInit;
    while (!(cin >> valueInit)|| valueInit<0) {
        cout << "Invalid input. Please enter a valid decimal number: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    // Initialize and print the array to console
    initArray(array, 35, valueInit);
    printArray(array, 35, 7, 2);

    // Open the output file
    ofstream output("SadadYusuf.txt");
    
    // Check if the file opened successfully
    if (!output) {
        cout << "Error opening file" << endl;
        return 1;
    }
    
    // Write the array to the file
    output << fixed << setprecision(3);
    for (int i = 0; i < 35; i++) {
        output << array[i] << " ";
        if ((i + 1) % 5 == 0) {
            output << endl; // New line after nPerLine elements
        }
    }
    output << endl; // Ensure the file ends with a newline
    output.close(); // Close the file
    
    // Inform the user that data has been written to the file
    cout << "Data has been written to SadadYusuf.txt." << endl;

    return 0;
}
