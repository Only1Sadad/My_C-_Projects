/*
 Title: Savings_Accout_Calculator.
 Description: Calculates By Monthly.
 Programmer:Sadad Yusuf.
 Date:07/27/24.
 
 //(Pseudocode)
 First Initialize Variables.
 second Input Annual Interest Rate and Starting Balance.
 Then Calculate Monthly Interest Rate.
 Ask Input for Number of Months.
 create a .txt file to display Transactions
 Validate the file.
 Perform other tests For Each Month Using for loop.
 Input and validate deposit.
 Then Add deposit to currentBalance.
 Input and validate withdrawal.
 Subtract withdrawal from currentBalance.
 Calculate interest.
 Add interest to currentBalance.
 Write the Transactions to the .txt file created.
 Display monthly summary for final balance,total deposite, withrawal, and interest rate.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void projectTitle();
int main()
{
    projectTitle();
    double annual_intRate, starting_Ballance, current_Balance, monthly_intRate, deposite, withdrawal;
    int number_Ofmonths;
   // asking the user for the annual interest rate
    cout<< "What is the Annual interest rate (enter..10 stands for 10%):" ;
    cin>>annual_intRate;
   
    // calculating monthly interest rate
    monthly_intRate = annual_intRate/100.0/12.0;
    
    // asking the user for the starting balance
    cout<< "What is your starting balance:$ "<<fixed<<setprecision(2);
    cin>>starting_Ballance;
    current_Balance = starting_Ballance;
    
    //number of months
    cout<< "What is the number of months that have passed so far: ";
    cin>>number_Ofmonths;
    
    //creating a file and writing to it/testing if opened as well.
    ofstream Account_Transactions("Sadad_Yusuf_AccountTransaction.txt");
    if (!(Account_Transactions.is_open()))
        {
        cout<<"error file did not open"<<endl;
        return 1;
        }
    //Writing Title to file.
    Account_Transactions<<setw(50)<<"Savings_Accout_Calculator\n\n"
    <<setw(51)<<"Description: Calculates By Monthly. \n"
    <<setw(38)<<"Programmer:Sadad Yusuf \n"
    <<setw(29)<<"Date:07/27/24 \n"<<endl;
  
    // A loop should then iterate once for every month,
    for (int month = 1; month<=number_Ofmonths; month++)
    {
        cout<< "\nWhat is the amount deposited into your Account in month "<<month<<":$ ";
        cin>>deposite;
        while( (!(deposite<0||deposite>0)) || deposite < 0)
        {
            cin.clear(); // resets error flag from wrong inputs, and continues to read inputs.
            cin.ignore(); // helpfull with invalid characters and ignores them.
            cout<<"please enter a valid non negative value for deposite:$ ";
            cin>>deposite;
        }
        current_Balance+=deposite;
        
        //getting the withdrawn amount
        cout<<"what is the amount withdrawn from your account:$ ";
        cin>>withdrawal;
        
        while(cin.fail() || withdrawal < 0)    //cin.fail is helpfull with combating a non intiger value
        {
            cin.clear();
            cin.ignore();
            cout<<"please enter a non negative value for withdrawa:$ ";
            cin>>withdrawal;
        }
       // Updating balance
        current_Balance-=withdrawal;
        monthly_intRate*=current_Balance;
        current_Balance+=monthly_intRate;
        
        //writing Transactions to a file.
        Account_Transactions<<"Month: "<<month
                            <<", Deposite:$ "<<deposite
                            <<", Withdrawal:$ "<<withdrawal
                            <<", Final Balance:$ "<<fixed<<
                            setprecision(2)<<current_Balance
                            <<", Interest Rate:$ "<<fixed<<
                            setprecision(2)<<monthly_intRate
                            <<endl;
     
        cout<<"\n\n\t\tYour final balance after month "<<month<<":$ "<<current_Balance<<endl;
        cout<<"\t\tTotal deposite value:$ "<<deposite<<endl;
        cout<<"\t\tTotal withdrawal value:$ "<<withdrawal<<endl;
        cout<<"\t\tTotal interest rate: "<<monthly_intRate<<endl;
    }
    return 0;
}
// function for title.
void projectTitle()
{
    cout<<setw(50)<<"Savings_Accout_Calculator\n\n"
    <<setw(51)<<"Description: Calculates By Monthly. \n"
    <<setw(38)<<"Programmer:Sadad Yusuf \n"
    <<setw(29)<<"Date:07/27/24 \n"<<endl;
}
