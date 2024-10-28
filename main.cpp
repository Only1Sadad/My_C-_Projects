//Program: Struct_Binary_Files
//Programmer: Sadad Yusuf
//Date: Oct-27-2024
/**
 **Pseudocode:
 *start:
    *  Define Structures:

            Create a Time structure to hold time values (hour, minute, second).
            Create a Date structure to hold date values (day, month, year).
            Create a DateTime structure that combines Date and Time.

        Using files:
            Open a text file for reading input data.
            Open a binary file for writing data in binary format.
            Declare Object.

        Declare an object of DateTime to store the date and time information.
        Read Data from Text File:
            Loop through the text file until all values are read.
            Read date and time values from the text file.
            Store the read values into the DateTime object.
            Write Data from the DateTime object to Binary File in the same loop at the same time.
            end loop
        Close Files:
            Close both the text file and the binary file after all data has been processed.

        Read Data from Binary File:
            Open the binary file for reading its contents.
            Loop through the binary file to read all records.
            Store Contents Back into Structure.
            Read each record into the DateTime object.
            Inside the loop, display all fields of the DateTime object to the console.
        Close Binary file after reading is complete.

 *  end program:
 */

#include <iostream>
#include <fstream>
#include <iomanip> // Include iomanip for std::setw and std::setfill

using namespace std;

// Struct to hold time information
struct Time {
    short hour;
    short minute;
    short second;
};

// Struct to hold date information
struct Date {
    short day;
    short month;
    short year;
};

// Combined struct to hold both date and time
struct DateTime {
    Date date;
    Time time;
};

int main() {
    // Open the text file to read it
    ifstream read("datetime.txt");
    if (!read) {
        cerr << "Error opening datetime.txt" << endl;
        return 1;
    }

    // Open a binary file to write to it.
    ofstream file("BinaryFl1.txt", ios::binary);
    if (!file) {
        cerr << "Error opening BinaryFl1.txt" << endl;
        return 1;
    }

    DateTime datetime; // Declare a DateTime structure
    int count = 0; // Counter for the number of records

    // Read date and time from the text file
    // Then write it to the binary file
    while (count < sizeof(DateTime)) {
        // Reading date and time from the text file into the struct
        read >> datetime.date.day >> datetime.date.month >>
            datetime.date.year >> datetime.time.hour >> datetime.time.minute >> datetime.time.second;

        // Writing the struct data to the binary file
        file.write(reinterpret_cast<char*>(&datetime), sizeof(DateTime));

        count++;
    }

    // Close the input and output files
    read.close();
    file.close();

    // Open the binary file for reading
    ifstream read2("BinaryFl1.txt", ios::binary);
    if (!read2) {
        cerr << "Error opening BinaryFl1.txt" << endl;
        return 1;
    }

    cout << "Date=====+=====Time" << endl;

    // Loop and read the binary file in reverse order.
    // display the date and time
    for (int i = 5; i >= 0; i--) {
        read2.seekg(i * sizeof(DateTime), ios::beg); // Move to the ith record from the start
        read2.read(reinterpret_cast<char*>(&datetime), sizeof(DateTime)); // Read the record into the struct

        // Format and display the date and time
        cout << setfill('0'); // Set fill character to '0' to show in front of every day and month
        cout << setw(2) << datetime.date.day << "/"
             << setw(2) << datetime.date.month << "/"
             << setw(2) << datetime.date.year << " "
             << setw(2) << datetime.time.hour << ":"
             << setw(2) << datetime.time.minute << ":"
             << setw(2) << datetime.time.second << endl;
    }

    // Close the binary read file
    read2.close();

    return 0;
}
