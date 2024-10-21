/* Pseudocode:
 Start the program and Declare a float variable named number.
  Prompt the user for input, then Display the message "Enter a number of your choice."
   Read the user input and Store the input value in the variable number.
     Validate the inputs
    Check if the input is a valid number.
   If the input is not a valid number, display the message
 "You have entered a non-number, please enter a number only."
 Then check if the number is a whole number or a decimal,
  If the input is a valid number: If number is equal to its integer cast,
   display the message "You have entered a whole number."
    Otherwise, display the message "You have entered a decimal number."
 
 End the program.
*/
 #include <iostream>
#include <iomanip>
using namespace std;
int main (){
    float number;
    
    cout<<setw(50)<<"IsWholeNumber\n\n"
        <<setw(60)<<"Description:Is it a whole number assignment. \n"
        <<setw(38)<<"Programmer:Sadad Yusuf \n"
        <<setw(29)<<"Date:07/07/24 \n"<<endl;
   
    cout<<"Enter a number of your choice. ";
    cin>> number;
    //check if the number is a none digt or number.
    if (!(number<0||number>0)){
        cout<<"You have intered a none number\n"
            <<"Please go back and inter a number only \n";
     }else {
            // Check if the number is a whole number or a decimal
            if (number == static_cast<int>(number)) {
                cout << "You have entered a whole number.\n";
            } else {
                cout << "You have entered a decimal number.\n"
                    <<"Please inter a whole number only.\n\n";
            }
        }
        return 0;
   }

