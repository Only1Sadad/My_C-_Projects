/* This program calculates student grades based on the assignments and weights
* provided in a syllabus file, and stores the result in a new file for each student.
* Programmer: Sadad Yusuf
* Date: 09/01/2024
 
 * Pseudocode:
  Declare variables:

    Create strings to hold the file name, student name, and assignment titles.
    Create integer variables to store weights, number of students, and assignment grades.
    Create double variables to store the total grade.
    Ask for syllabus file name:

 Prompt the user for the syllabus file name.
    Validate if the file exists. If it doesn't, keep asking until a valid file name is provided.
    Read syllabus data:

 Use a loop to read each assignment's title and its weight from the file.
    Store the data in corresponding vectors (title in assignments and weight in weights).
    Ask for the number of students:

 Prompt the user to enter the number of students.
    Validate the input to ensure it's a valid number (no decimals, negative numbers, etc.).
    Process student files:

 For each student, open their respective file (based on student number).
    Read the student's name and their grades from the file.
    Calculate their total grade by applying the assignment weights to their grades.
    Write the student's grade and other information to a new file.
 
 End the program:
 After processing all student files, close any open file streams and terminate the program.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void banner(); // Function to display the program banner
bool validateInput(int); // Function to validate the input for the number of students
void answerKey(ifstream &, string, string&, vector<int> &); // Function to load grades from a student file
void giveGrade(ofstream &, string, double&, vector<string>, vector<double>, vector<int>, vector<double>&); // Function to calculate and write grades to the output file

int main() {
    banner(); // Display the program banner

    string fileName, studentName, title; // Variables to hold file and student names, and assignment titles
    int weight, students; // Variables for assignment weights and the number of students
    double totalGrade; // Variable to store the student's total grade
    vector<string> assignments; // Vector to store assignment titles
    vector<double> weights; // Vector to store assignment weights
    vector<int> grades; // Vector to store student grades for each assignment
    ifstream inputFile; // Input file stream to read the syllabus and student files
    ofstream outputFile; // Output file stream to write the student's grade results

    // Ask the user for the syllabus file name and validate if it exists
    cout << "What is the name of your syllabus file? ";
    cin >> fileName;
    inputFile.open(fileName); // Open the syllabus file

    while (inputFile.fail()) { // If the file doesn't open, prompt the user to enter a valid file
        cout << "Error opening file, please enter a valid file name: ";
        cin >> fileName;
        inputFile.open(fileName);
    }

    cout << "Syllabus file opened, reading syllabus data...\n\n";

    // Read assignment titles and weights from the syllabus file
    while (inputFile >> title >> weight) {
        inputFile.ignore(1, '%'); // Ignore the percentage sign after each weight
        assignments.push_back(title); // Add the assignment title to the vector
        weights.push_back(weight); // Add the weight to the vector
    }
    inputFile.close(); // Close the syllabus file after reading

    cout << "There are " << assignments.size() << " items in this course.\n";
    cout << "Data from syllabus file read, closing file.\n\n";

    // Prompt the user to enter the number of students and validate the input
    cout << "How many students do you have? ";
    cin >> students;
    while (!validateInput(students)) {
        cin >> students; // Re-prompt if validation fails
    }

    // Vector to store points for each assignment, based on the number of assignments
    vector<double> points(assignments.size());

    // Process each student's file
    for (int x = 1; x <= students; x++) {
        // Open the student's file and read their name and grades
        answerKey(inputFile, ("Student#" + to_string(x) + ".txt"), studentName, grades);
        totalGrade = 0; // Reset totalGrade for each student

        // Calculate the student's total grade and write it to the output file
        giveGrade(outputFile, studentName, totalGrade, assignments, weights, grades, points);
    }

    return 0; // Program ends
}

void banner() {
    // Function to display the program banner at the beginning
    cout << "This program will take in the file name of a syllabus and the number of student files to access "
        "and use that information to calculate student grades and write them to a new file\n"
        "Programmer: Sadad Yusuf\n"
        "Last Modified: 8/22/2024\n\n";
}

bool validateInput(int entry) {
    // Function to validate the input number of students
    if (cin.fail()) { // Check for non-numeric input
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        cout << "This is not a number, please enter a number: ";
        return false;
    } else if (entry < 0) { // Check for negative numbers
        cout << "This is a negative number, please enter a valid number of students: ";
        return false;
    } else if (cin.peek() == '.') { // Check for decimal input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "This is a decimal, please enter a whole number of students: ";
        return false;
    } else {
        return true; // Valid input
    }
}

void answerKey(ifstream &inFile, string fileName, string &name, vector<int> &grades) {
    // Function to read the student name and grades from a file
    inFile.open(fileName); // Open the student file

    if (inFile.fail()) { // If the file doesn't open, terminate the program
        cout << "Error opening file.\n\n";
        exit(0);
    } else {
        grades.clear(); // Clear the grades vector to avoid accumulation from previous students
        getline(inFile, name); // Read the student name from the first line
        int grade; // Variable to store each grade
        while (inFile >> grade) {
            grades.push_back(grade); // Add each grade to the grades vector
        }
        inFile.close(); // Close the student file
    }
}

void giveGrade(ofstream& outFile, string name, double& totalGrade, vector<string> assignments, vector<double> weights, vector<int> grades, vector<double>& points) {
    // Function to calculate the student's grade and write the results to a file
    outFile.open(name + " Grades.txt"); // Create and open the output file based on the student name

    if (outFile.fail()) { // If the file doesn't open, terminate the program
        cout << "Error creating/opening file.\n\n";
        exit(0);
    } else {
        cout << "Calculating " << name << "'s grade...\n\n";

        // Calculate the total grade for the student
        for (int i = 0; i < assignments.size(); i++) {
            points[i] = grades[i] * (weights[i] / 100); // Calculate points for each assignment
            totalGrade += points[i]; // Add points to the total grade
        }

        // Write the student's name, assignments, and grades to the output file
        outFile << name << "'s grades\n\n";
        outFile << left << setw(30) << "Item" << right << setw(15) << "Weight" << setw(10) << "Grade" << setw(20) << "Points Earned" << endl;
        for (int i = 0; i < assignments.size(); i++) {
            outFile << left << setw(30) << assignments[i]
                    << right << setw(10) << weights[i] << "%"
                    << setw(10) << grades[i]
                    << setw(20) << points[i]
                    << endl;
        }
        outFile << endl;
        outFile << "The student's course grade is " << totalGrade << "%\n";

        // Check if the student passed or failed
        if (totalGrade >= 70) {
            outFile << name << " PASSED this course.\n\n";
        } else {
            outFile << name << " FAILED this course.\n\n";
        }
        outFile.close(); // Close the output file after writing
        cout << "Student file processed.\n\n";
    }
}

