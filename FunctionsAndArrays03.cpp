/**
 Programmer: Sadad Yusuf
 Class: CSC-237-03
 Date: 09-22-2024
 
 Goal: program planning
    *function design
    *code documentation
    *array creation and manipulation
    *console output manipulation
 Pseudocode:
 * Include libraries: iostream, cstdlib, ctime, iomanip

 * Define functionSquared(double array, int size)
    - Initialize array to store squared values
    - Loop through original array and square each value
    - Print squared values with 10 values per line

 * Define functionFirstIndex(int array, int size)
    - Track unique values in a list
    - Loop through array to find and print the first occurrence of each value

 * Define functionAfterIndex(int array, int size)
    - Loop through array to find the next occurrence of each value after the first

 * Define functionForNumberOfOccurrences(int array, int size)
    - Loop through array and count how many times each value occurs
    - Print occurrences for each value

 * Define functionMinimumValue1(double array, int size)
    - Loop through double array to find minimum value
    - Print and return minimum

 * Define functionMaximumValue1(double array, int size)
    - Loop through double array to find maximum value
    - Print and return maximum

 * Define functionMinimumValue2(int array, int size)
    - Loop through integer array to find minimum value
    - Print and return minimum

 * Define functionMaximumValue2(int array, int size)
    - Loop through integer array to find maximum value
    - Print and return maximum

 * Define randomIntFunction()
     - Return random integer between 0 and 2000

 * In main:
     - Set size constants and seed random number generator

     - Create double array:
       - Fill with random values (random integer / 100.0)
       - Print double array with 5 values per line
       - Call functionMaximumValue1, functionMinimumValue1, functionSquared
     
     - Create integer array:
       - Fill with random values (between 20 and 30)
       - Print integer array with 10 values per line
       - Call functionFirstIndex, functionAfterIndex, functionForNumberOfOccurrences, functionMinimumValue2, functionMaximumValue2

 **/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Function to square each element in an array of doubles
void functionSquared(double test[], int size) {
    double squaredNum[size]; // Array to hold squared values

    cout << "\n--- Squared Values ---\n" << endl;

    // Loop through the array and calculate squared values
    for (int i = 0; i < size; i++) {
        squaredNum[i] = test[i] * test[i]; // Square each element
    }

    cout << fixed << setprecision(2); // Set decimal precision for output

    // Print squared values, 10 values per line
    for (int i = 0; i < size; i++) {
        cout << squaredNum[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl; // Move to a new line after every 10 values
        }
    }
}

// Function to find the index of the first occurrence of each value in an integer array
void functionFirstIndex(const int test[], int size) {
    int trackingList[size]; // Array to keep track of unique values
    int count = 0; // Counter for the number of unique values

    cout << "\n--- First Occurrences ---\n" << endl;

    // Loop through the array to find first occurrences
    for (int i = 0; i < size; i++) {
        bool found = false; // Flag to check if the value has already been seen

        // Check if the value already exists in the tracking list
        for (int j = 0; j < count; j++) {
            if (test[i] == trackingList[j]) {
                found = true; // Value is already in the tracking list
                break;
            }
        }

        // If the value is not in the list, print its first occurrence
        if (!found) {
            cout << "The first occurrence of " << test[i] << " is at index " << i << endl;
            trackingList[count] = test[i]; // Add the value to the tracking list
            count++; // Increment the count of unique values
        }
    }
}

// Function to find the next occurrence of each value starting from a specific index
int functionAfterIndex(const int test[], int size) {
    cout << "--- Next Occurrences ---\n" << endl;

    // Loop through the array to find next occurrences
    for (int i = 0; i < size; i++) {
        bool alreadySeen = false; // Flag to check if the value has been seen before

        // Check if the current value has been seen earlier in the array
        for (int j = 0; j < i; j++) {
            if (test[j] == test[i]) {
                alreadySeen = true; // Value has already been encountered
                break;
            }
        }

        // If the value has not been seen before, search for its next occurrence
        if (!alreadySeen) {
            for (int counter = i + 1; counter < size; counter++) {
                if (test[counter] == test[i]) {
                    cout << "Next occurrence of " << test[i] << " is at index " << counter << endl;
                    break;
                }
            }
        }
    }
    cout << endl; // Extra newline for formatting
    return -1; // Return -1 (no specific use in this context)
}

// Function to count the occurrences of each value in an integer array
int functionForNumberOfOccurrences(int test[], int size) {
    cout << "\n--- Number of Occurrences ---\n" << endl;
    
    int count = 0; // Variable to track occurrences
    // Loop through the array to count occurrences for each value
    for (int i = 0; i < size; i++) {
        // Compare current value with all other values in the array
        for (int j = 0; j < size; j++) {
            if (test[i] == test[j]) {
                count++; // Increment count if a match is found
            }
        }
        // Output the number of occurrences for the current value
        cout << "Number of occurrences for " << test[i] << " is " << count << endl;
        count = 0; // Reset count for the next value
    }
    return count;
}

// Function to find the minimum value in an array of doubles
double functionMinimumValue1(double test[], int size) {
    double min = test[0]; // Assume the first element is the minimum

    // Loop through the array to find the actual minimum value
    for (int i = 1; i < size; i++) {
        if (test[i] < min) {
            min = test[i]; // Update the minimum value if a smaller value is found
        }
    }
    cout << fixed << setprecision(2) << "\nThe minimum value in the array is: " << min << "\n" << endl;
    
    return min; // Return the minimum value
}

// Function to find the maximum value in an array of doubles
double functionMaximumValue1(double test[], int size) {
    double max = test[0]; // Assume the first element is the maximum

    // Loop through the array to find the actual maximum value
    for (int i = 1; i < size; i++) {
        if (test[i] > max) {
            max = test[i]; // Update the maximum value if a larger value is found
        }
    }
    cout << fixed << setprecision(2) << "\nThe maximum value in the array is: " << max << "\n" << endl;

    return max; // Return the maximum value
}

// Function to find the minimum value in an array of integers
int functionMinimumValue2(int test[], int size) {
    int min = test[0]; // Assume the first element is the minimum

    // Loop through the array to find the actual minimum value
    for (int i = 1; i < size; i++) {
        if (test[i] < min) {
            min = test[i]; // Update the minimum value if a smaller value is found
        }
    }
    cout << "The minimum value in the array is: " << min << "\n" << endl;

    return min; // Return the minimum value
}

// Function to find the maximum value in an array of integers
int functionMaximumValue2(int test[], int size) {
    int max = test[0]; // Assume the first element is the maximum

    // Loop through the array to find the actual maximum value
    for (int i = 1; i < size; i++) {
        if (test[i] > max) {
            max = test[i]; // Update the maximum value if a larger value is found
        }
    }
    cout << "The maximum value in the array is: " << max << "\n" << endl;
    
    return max; // Return the maximum value
}

// Function to generate a random integer between 0 and 2000
int randomIntFunction() {
    return rand() % 2001; // Random number in the range [0, 2000]
}

int main() {
    const int SIZE = 30; // Size of the double array
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    double array[SIZE]; // Array to store random double values

    // Fill the array with random double values
    for (int i = 0; i < SIZE; i++) {
        int randomNum = randomIntFunction(); // Generate a random integer
        array[i] = randomNum / 100.0; // Convert the integer to a double by dividing by 100
    }
    
    cout << fixed << setprecision(2) << endl;
    cout << "--- Random Double Array ---\n" << endl;
    
    // Print the double array with 5 values per line
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
        if ((i + 1) % 5 == 0) {
            cout << "\n"; // New line after every 5 values
        }
    }

    // Call functions to find max/min values and squared values in the double array
    functionMaximumValue1(array, SIZE);
    functionMinimumValue1(array, SIZE);
    functionSquared(array, SIZE);
    
    // Define range and size for the integer array
    const int minn = 20, maxx = 30, SIZEE = 20;
    int arr[SIZEE]; // Integer array to store random values

    // Fill the integer array with random values between 20 and 30
    for (int i = 0; i < SIZEE; i++) {
        arr[i] = (rand() % (maxx - minn + 1)) + minn; // Generate a random integer in the range [20, 30]
    }
    
    cout << "\n--- Random Integer Array ---\n" << endl;
    
    // Print the integer array with 10 values per line
    for (int i = 0; i < SIZEE; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << "\n"; // New line after every 10 values
        }
    }

    // Call functions to analyze occurrences and min/max values in the integer array
    functionFirstIndex(arr, SIZEE);
    functionAfterIndex(arr, SIZEE);
    functionForNumberOfOccurrences(arr, SIZEE);
    functionMinimumValue2(arr, SIZEE);
    functionMaximumValue2(arr, SIZEE);
}
