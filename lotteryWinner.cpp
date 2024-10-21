/*
 Title: Lottery Winners.
 Description: Performing a Linner Search to fin winning lottery Numbers.
 Programmer:Sadad Yusuf.
 Date:08/13/24.
 
 pseudocode.
 Begin the program.
 Define an array of winning numbers.
 Get user input.
 While the input is invalid:
 Prompt the user to provide a valid input.
 Check if the input is in the array of winning numbers.
 If the input is found in the array:
 Display a winning message.
 Otherwise:
 Display a losing message.
 End the program.
 */
//

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes.
void banner();
bool linearSearch(const int winningNumbers[], int,int);
int main()
{
    const int size=10;  // Size of the array.
    int winningNumbers[size]={13579, 26791, 26792, 33445, 55555,
                                62483, 77777, 79422, 85647, 93121};
    int luckyNumber;    // stores the user's input.

    // Shows program banner.
    banner();
    
    // Input validation loop.
    while(true)
    {
        // Ask the user to enter a 5 digit number.
        cout<<"\nCheck if you are this weeks winner, Enter your numbers( ex..12345). ";
        cin>>luckyNumber;
      
        // Validate input for 5 digit number.
        if(cin.fail() || luckyNumber<10000 || luckyNumber>99999 || cin.peek()=='-')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a 5-digit number." << endl;
        }
        else
        {
            break; // If input is valide loop is broken.
        }
    }
    // Check if the entered number is a winning number
    bool winner=linearSearch(winningNumbers,size,luckyNumber);
    
    // Show the result if number choice is the winner.
    if(winner)
    {
        cout<<setw(50)<<"***congrats you have the winning ticket!***\n\n";
    }
    else
    {
        cout<<"Sorry you didnt choose the winning ticket this week"<<endl;
    }
    return 0;
}

// Function to show program banner.
void banner()
{
    cout<<"Programmer: Sadad Yusuf\n"
        <<"Date: 08/12/24\n"
        <<setw(40)<<"Title: Lotter Winners\n"
        <<setw(40)<<"------------------------"<<endl;

}

// Function to perform a linear search on the array of winning numbers
bool linearSearch(const int winningNumbers[],int size ,int luckyNumber )
{
    //initialize bool variable flag.
    bool winner = false;
    
    // Loop through each number in the array.
    for (int index=0; index<size; index++)
    {
        // If the user choice of number matches a number in the array, return true.
        if(luckyNumber == winningNumbers[index])
        {
            winner=true;
            break; // Exit loop.
        }
    }
    
    // return if the users number is the winner.
    return winner;
}



