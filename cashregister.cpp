#include <iostream>
#include <iomanip>
#include <fstream>
#include "cashregister.h"
#include "GateMenuSelector.h"
//including both my h files

using namespace std;
cashRegister myCashRegister;
cashRegister myCashRegisterInFile[6];
//class objects
ifstream Infile;
//infile variable

//function to add up total credit available
double cashRegister::TotalcreditFound(double &y)
{  double j =5025;
    return y + j;
}
//function to loop cash menu
char cashRegister::MenuEnterCash(){
            myGate.moneyCount1=0;
            cout//function to choose between cash or parking lot on first try it will only give cash option till you have given enough money to allot the parking space
                <<"\nEnter valid operation below:\n"
                <<"1. Insert Cash\n"
                <<"2. Allot a parking place\n"
                <<"0. EXIT\n"
                <<"Enter Option <1-2>: ";
            cin >>myCashRegister.choice2;
            while (myCashRegister.choice2[0] < '0' || myCashRegister.choice2[0]  >= '2')
            {  //while loop for invalid options
                cout << "Please enter a valid menu choice: ";
                cin  >> myCashRegister.choice2;
            }
            if (myCashRegister.choice2[0] == '0')
            {//exit program option
            exit(1);
            }
            else if(myCashRegister.choice2[0] == '1')
            {
            while (myGate.moneyCount1 < myGate.moneyCount)
                {
                cout//cout to choose money denominations
                    <<"\nPlease Insert Cash\n"
                    <<"\n-------------------------------------------------------------------------------\n\n"
                    <<"===============================================================================\n"
                    << setw (54)
                    <<"Currency Denominations to choose\n"
                    <<"===============================================================================\n"
                    << setw (29)
                    <<" CODE : CURRENCY\n"
                    << setw (29)
                    <<" 1 : 1 DOLLAR\n"
                    << setw (30)
                    <<" 2 : 5 DOLLARS\n"
                    << setw (31)
                    <<" 3 : 10 DOLLARS\n"
                    << setw (31)
                    <<" 4 : 20 DOLLARS\n"
                    << setw (30)
                    <<" 5 : 1 QUARTER\n"
                    <<"-------------------------------------------------------------------------------\n"
                    <<"Enter Code to add credit : ";
                cin >> myCashRegister.credit;
                while(myCashRegister.credit<1 || myCashRegister.credit>5)
                {  //while loop for invalid options
                    cout<<"Invalid input try again ";
                    cin >> myCashRegister.credit;
                }
                cout <<"Total credit Available: $";
                //if else statements to choose dollar amounts and count money input
                if (myCashRegister.credit == 1)
                {
                myGate.moneyCount1+=1;
                myCashRegister.totalCost+=1;
                myCashRegisterInFile[1].totaldollars++;
                cout <<myGate.moneyCount1
                     <<endl;
                }
                else if (myCashRegister.credit == 2)
                {
                myGate.moneyCount1+=5;
                myCashRegister.totalCost+=5;
                myCashRegisterInFile[2].totaldollars++;
                cout <<myGate.moneyCount1
                     <<endl;

                }
                else if (myCashRegister.credit == 3)
                {
                myGate.moneyCount1+=10;
                myCashRegister.totalCost+=10;
                myCashRegisterInFile[3].totaldollars++;
                cout <<myGate.moneyCount1
                     <<endl;
                }
                else if (myCashRegister.credit == 4)
                {
                myGate.moneyCount1+=20;
                myCashRegister.totalCost+=20;
                myCashRegisterInFile[4].totaldollars++;
                cout <<myGate.moneyCount1
                     <<endl;
                }
                else if (myCashRegister.credit == 5)
                {
                myGate.moneyCount1+=00.25;
                myCashRegister.totalCost+=00.25;
                myCashRegisterInFile[5].totaldollars++;
                cout <<myGate.moneyCount1
                     <<endl;
                }//if not enough money input if statement outputs to put in more funds
                if (myGate.moneyCount1 < myGate.moneyCount){
                cout<< "Not enough money!! Please input $"
                    << myGate.moneyCount-myGate.moneyCount1
                    << " more dollars to get your spot!"
                    << endl;
                }
             }
           }

}

//void function to load array from In file
void cashRegister::Getinfile(cashRegister myCashRegisterInFile[])
{   //open in file
    Infile.open("parking_account.txt");
    if(!Infile)
    {   //error if in file fails to open
        cout << "Error reading the file!!"<<endl;
    }
    int i=1;
    Infile >> myCashRegister.dummy;
    while (!Infile.eof())
    {   //loop in file to end of file
        Infile >> myCashRegister.bills1 >> myCashRegister.totaldollars1;
        myCashRegisterInFile[i].bills = myCashRegister.bills1;
        myCashRegisterInFile[i].totaldollars = myCashRegister.totaldollars1;
        i = i+1;
    }
    Infile.close();
}
//void function for my cash register to loop through my infile array/
void cashRegister::ParkMachineAccounts(cashRegister myCashRegisterInFile[]){
  //cash register to cout and keep track total bills and total cash collected
    cout<<"-------------------------------------------------------------------------------\n\n"
    <<"===============================================================================\n"
    << setw (46)
    <<"Parking Machine Accounts\n"
    <<"===============================================================================\n"
    <<"Sr. No. : BILL NAME             : BILL COUNT : COST<in $> \n"
    <<"-------------------------------------------------------------------------------\n";
    //for loop to loop through my infile array and print out/
    for (int i=1;i<=5;i++)
        {
            cout
                << setw(7)
                << i
                << " : "
                << myCashRegisterInFile[i].bills
                << " Dollar"
                << setw(8)
                << "\t"
                << ":   "
                << myCashRegisterInFile[i].totaldollars<< " : "
                << setw(5);
                //series of if statements to multiply the dollar count by the $ denomination and couting results
                if (myCashRegisterInFile[i].totaldollars==myCashRegisterInFile[1].totaldollars)
                {
                    myCashRegister.cashOnHand1=myCashRegisterInFile[i].totaldollars;
                    cout << myCashRegister.cashOnHand1;
                }
                else if (myCashRegisterInFile[i].totaldollars==myCashRegisterInFile[2].totaldollars)
                {
                    myCashRegister.cashOnHand5=myCashRegisterInFile[i].totaldollars*5;
                    cout << myCashRegister.cashOnHand5;
                }
                else if (myCashRegisterInFile[i].totaldollars==myCashRegisterInFile[3].totaldollars)
                {
                    myCashRegister.cashOnHand10=myCashRegisterInFile[i].totaldollars * 10;
                    cout << myCashRegister.cashOnHand10;
                }
                else if (myCashRegisterInFile[i].totaldollars==myCashRegisterInFile[4].totaldollars)
                {
                    myCashRegister.cashOnHand20=myCashRegisterInFile[i].totaldollars*20;
                    cout << myCashRegister.cashOnHand20;
                }
                else if (myCashRegisterInFile[i].totaldollars==myCashRegisterInFile[5].totaldollars)
                {
                    myCashRegister.cashOnHandQaurter=myCashRegisterInFile[i].totaldollars/4;
                    cout << myCashRegister.cashOnHandQaurter;
                }
                cout << endl;
        }   //cout the total bill types found and add in any more bills collected from customers
            cout<<"-------------------------------------------------------------------------------"
                <<"\nTotal bill Types Found :   "
                << "5"
                <<"\nTotal credit available :   "
                <<myCashRegister.TotalcreditFound(myCashRegister.totalCost)
                <<endl;
}
//void function for my cash register to loop through my infile array/






