/*
 Title: Math quiz.
 Description: menu oriented quiz application.
 Programmer:Sadad Yusuf.
 Date:08/03/24.
 
 (pseudocode)
 1. Initialize Program/ and declare functions prototypes.
    - Seed random number generator on top of main function.
    - Display banner with project details.

 2. Main Loop.
    - Display menu and get user choice.
    - If the choice is 11, exit the program with a message.
    - Validate and get the number of quiz questions.
    - Run quiz based on the user's choice and number of questions.
    - Ask if the user wants to run the program again. If not, exit with a message.

 3. functions.
    - Banner: Displays the banner with project details.
    - PrintMenu, Displays the menu options.
    - validateChoice Validates the user’s menu choice (1-11).
    - validateNumOfQuestions, Validates the number of questions for the quiz.
    - RandomNumGenerator,Generates a random number between 1 and 99.
    - quiz, Generates and evaluates quiz questions based on user choice.
    - Uses, switch to determine question type addition, subtraction and others
    - Validates user input and provides feedback.
    - Tracks correct and partially correct answers.
    - saveReport, Saves the quiz results to a text file.

 4. End of Program.
    - Program ends when the user selects "End program" or chooses not to run the quiz again.

 */
#include <iostream>
#include <iomanip>
#include <cstdlib> // rand()
#include <ctime>   // time
#include <fstream> // file stream

using namespace std;

// Function prototypes
// Displays the banner with project details
void Banner();
// Displays the menu options
void showMenu();
// Validates the users menu choices from (1-11)
int validateChoice();
// Validates the number of questions for the quiz (1-10)
int validateNumOfQuestions();
// Generates a random number between 1 and 99
int RandomNumGenerator();
// Generates and checks quiz questions based on user choice and number of questions
void quiz(int choice, int num_OfQuestions);
// Saves the quiz results to a .txtfile
void saveReport(int correct, int partial, int total);

int main()
{
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
   
    //display the banner
    Banner();
   
    // Main loop for running the quiz program
    while (true)
    {
        // Show the menu and get user choice
        showMenu();
        int choice = validateChoice();
        if (choice == 11)
        {
            cout << "Program ended" << endl;
            break;
        }
        
        // Get the number of quiz questions from the user
        int num_OfQuestions = validateNumOfQuestions();
        quiz(choice, num_OfQuestions);
       
        //restart again prompt the user if they want to start again
        char restart;
            cout << "Do you want to run the program again? (Y/N): ";
            cin >> restart;
        // Exit if the user does not want to continue taking the quiz

            if (restart != 'y' || 'y')
            {
                cout << "Exiting program. Goodbye!\n";
                break;
            }
        
    }
    
    return 0;
}
// projet title
void Banner()
{
    cout << setw(30) << "Project Name: Math Tutor\n"
         << setw(27) << "Creator: Sadad Yusuf\n"
         << setw(23) << "Date: 08/03/2024\n"
         << endl;
}
//menu display
void showMenu()
{
    cout << "Select From Menu below\n"
         << "________________________\n\n"
         << "1]  Addition only\n"
         << "2]  Subtraction only\n"
         << "3]  Multiplication only\n"
         << "4]  Integer Division only\n"
         << "5]  Real Division only\n"
         << "6]  Modulo only\n"
         << "7]  Addition and subtractions\n"
         << "8]  Addition, subtraction and multiplication\n"
         << "9]  Addition, subtraction, multiplication, and int division\n"
         << "10] All operators\n"
         << "11] End program\n";
}
//getting the menu selection from user/validating it
int validateChoice()
{
    int choice;
    while (true)
    {
        cout << "\nPlease select from the menu (1-11) only: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 11)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Not a valid input. Please select (1-11): ";
        }
        else
        {
            break; // valid input
        }
    }
    return choice;
}
//geting the amount of Q's taken and validating them
int validateNumOfQuestions()
{
    int numOfquestions;
    while (true)
    {
        cout << "\nSelect how many questions you want from (1-10): ";
        cin >> numOfquestions;

        if (cin.fail() || numOfquestions < 1 || numOfquestions > 10)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Select only 1-10 number of questions: ";
        }
        else
        {
            break;
        }
    }
    return numOfquestions;
}
//random number is created.
int RandomNumGenerator()
{
    return rand() % 99 + 1;
}
// makes quiz questions and evaluates user responses
void quiz(int choice, int num_OfQuestions)
{
    int correctAns = 0;
    int partialCorrectAnswers = 0;
    
    for (int i = 1; i <= num_OfQuestions; ++i)
    {
        int problem1 = RandomNumGenerator();
        int problem2 = RandomNumGenerator();
        double user_Answer=0;
        double correctAns = 0;
        
        switch (choice)
               {
                   case 1: // Addition only
                       cout << "Question " << i << ": " << problem1 << " + " << problem2 << " = ";
                       correctAns = problem1 + problem2;
                       break;
                       
                   case 2: // Subtraction only
                       cout << "Question " << i << ": " << problem1 << " - " << problem2 << " = ";
                       correctAns = problem1 - problem2;
                       break;
                       
                   case 3: // Multiplication only
                       cout << "Question " << i << ": " << problem1 << " * " << problem2 << " = ";
                       correctAns = problem1 * problem2;
                       break;
                       
                   case 4: // Integer Division only
                       cout << "Question " << i << ": " << problem1 << " / " << problem2 << " = ";
                       correctAns = problem1 / problem2;
                       break;
                       
                   case 5: // Real Division only
                       cout << fixed << setprecision(2);
                       cout << "Question " << i << ": " << problem1 << " / " << problem2 << " = ";
                       correctAns = static_cast<double>(problem1) / problem2;
                       break;
                       
                   case 6: // Modulo only
                       cout << "Question " << i << ": " << problem1 << " % " << problem2 << " = ";
                       correctAns = problem1 % problem2;
                       break;
                       
                   case 7: // Addition and subtractions
                       if (rand() % 2 == 0)
                       {
                           cout << "Question " << i << ": " << problem1 << " + " << problem2 << " = ";
                           correctAns = problem1 + problem2;
                       }
                       else
                       {
                           cout << "Question " << i << ": " << problem1 << " - " << problem2 << " = ";
                           correctAns = problem1 - problem2;
                       }
                       break;
                       
                   case 8: // Addition, subtraction and multiplication
                       switch (rand() % 3)
                       {
                           case 0:
                               cout << "Question " << i << ": " << problem1 << " + " << problem2 << " = ";
                               correctAns = problem1 + problem2;
                               break;
                           case 1:
                               cout << "Question " << i << ": " << problem1 << " - " << problem2 << " = ";
                               correctAns = problem1 - problem2;
                               break;
                           case 2:
                               cout << "Question " << i << ": " << problem1 << " * " << problem2 << " = ";
                               correctAns = problem1 * problem2;
                               break;
                       }
                       break;
                       
                   case 9: // Addition, subtraction, multiplication, and int division
                       switch (rand() % 4)
                       {
                           case 0:
                               cout << "Question " << i << ": " << problem1 << " + " << problem2 << " = ";
                               correctAns = problem1 + problem2;
                               break;
                           case 1:
                               cout << "Question " << i << ": " << problem1 << " - " << problem2 << " = ";
                               correctAns = problem1 - problem2;
                               break;
                           case 2:
                               cout << "Question " << i << ": " << problem1 << " * " << problem2 << " = ";
                               correctAns = problem1 * problem2;
                               break;
                           case 3:
                               cout << "Question " << i << ": " << problem1 << " / " << problem2 << " = ";
                               correctAns= problem1 / problem2;
                               break;
                       }
                       break;
                       
                   //// All operators
                   case 10:
                       switch (rand() % 5)
                       {
                           case 0:
                               cout << "Question " << i << ": " << problem1 << " + " << problem2 << " = ";
                               correctAns = problem1 + problem2;
                               break;
                           case 1:
                               cout << "Question " << i << ": " << problem1 << " - " << problem2 << " = ";
                               correctAns = problem1 - problem2;
                               break;
                           case 2:
                               cout << "Question " << i << ": " << problem1 << " * " << problem2 << " = ";
                               correctAns = problem1 * problem2;
                               break;
                           case 3:
                               cout << "Question " << i << ": " << problem1 << " / " << problem2 << " = ";
                               correctAns = problem1 / problem2;
                               break;
                           case 4:
                               cout << "Question " << i << ": " << problem1 << " % " << problem2 << " = ";
                               correctAns = problem1 % problem2;
                               break;
                       }
                       break;
                       
            default:
                cout << "Invalid choice" << endl;
                return;
        }
        // Get user's answer and validate input
        cin >> user_Answer;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Invalid input. Please enter a valid number: ";
            cin >> user_Answer;
        }
        
        // Check if the answer is the correct answer
        if (user_Answer == correctAns)
        {
            cout <<" Correct answer "<< endl;
            correctAns++;
        }
        else
        {
            cout << "Wrong answer, Try again: ";
            cin >> user_Answer;
            if (user_Answer == correctAns)
            {
                cout << "Correct answer partial-credit" << endl;
                partialCorrectAnswers++;
            }
            else
            {
                cout << "Wrong answer. The correct answer is: " << correctAns << endl;
            }
        }
    }
   
    // Saves the quiz results to a text file
    saveReport(correctAns, partialCorrectAnswers, num_OfQuestions);
}

void saveReport(int correct, int partial, int total)
{
    ofstream report("Report.txt");
    if (report.is_open())
    {
        report << "Quiz Report\n";
        report << "Total Questions: " << total << "\n";
        report << "The correct Answers: " << correct << "\n";
        report << "Partial Correct Answers: " << partial << "\n";
        report << "Score: " << (correct + 0.5 * partial) / total * 100 << "%\n";
        report.close();
    }
    else
    {
        cout << "Unable to open file to save report\n";
    }
}

