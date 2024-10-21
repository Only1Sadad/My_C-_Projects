//pseudocode
/* Display Code Banner:
 -"Positive Intiger Factorial"
 -"Positive_Factorial.cpp"
 -"Sadad Yusuf"
 -"07/11/2024"
 
 Declare and Initialize Variables:
     - Declare int nuM, and usigned long long factorial variable=1
 Get a user to Enter a positive number
 Display the value back to the user on the input console
  After that validate the data that the user inputed is either a positive or not.
  If the user inters a non number then we cin.ignore that input. repronting them to inter a valid input.
   After a positive value is inputed by the user we perform a factorial on that value.
   I counter initialize int uP =previous int value nuM;
    then display that on the input console as the (#!=)
    then I run my second while loop validating values greater than 1 for counter variable (uP).
     the goal is to dicremeant from top down to 1.
     final result should appear 5!=5*4*3*2*1=120.
End Program.
*/
//  Created by Sadad Yusuf on 7/11/24.

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    //code banner
    cout<<setw(1)<<"Positive Intiger Factorial\n"
    <<setw(1)<<"Positive_Factorial.cpp\n"
    <<setw(1)<<"Sadad Yusuf\n"
    <<setw(1)<<"07/11/2024\n"<<endl;
    
    int nuM;
    unsigned long long factorial = 1; //data type used to accout for a larger inputs.
    
    // asking user to inter a positive number.
    cout << "Enter a positive number?. ";
    cin>>nuM;
 
    //validating for edge cases.
    while(nuM<=0)
    {

      cin.ignore(100, '\n');    //ignores characters up to 100.
    
      cout<<"Please enter a valid number: ";
      cin>>nuM;
    }
    // Last performing a factorial operation using while loop. Goal is to display 5!=5*4*3*2*1=120
    int uP=nuM;
        cout<<nuM<<"! =";    // we the 5! = here
    while(uP>1)
    {
        factorial*=uP;
        cout<<uP<<" * ";    // each iterated value is multiplied
        uP--;
    }
    factorial*=1;
    cout<<"1 = "<<factorial<<endl;  // final display should be like 5!=5*4*3*2*1=120.
    
       return 0;
   }

