#include <iostream>
#include <iomanip>
#include <fstream>
#include "GateMenuSelector.h"
#include "cashregister.h"
//including both my h files
using namespace std;

gateSelector myGate;
//class object

//void function to loop through my array and find out the number of emergency cars based on the initial randomization of available spots
void gateSelector::EmergencyCars(ofstream& Outfile, gateSelector myGate){
    for (int j=0;j<3; j++){
        for (int i=0;i<3;i++){
             myCashRegister.emergencyCars+=MaxCapacity[j][i]- AvailableSpots[j][i];
         }
    }//print to out file
    Outfile<<myCashRegister.emergencyCars-myGate.visitorCars;
}

//char function for my do while loop to choose which gate to enter and print out to file
char gateSelector::gateMenuSelection(){
    //pull info from my infile to fill my arrays
    myCashRegister.Getinfile(myCashRegisterInFile);
    //start my first call for the initial print out of the cash machine
    myCashRegister.ParkMachineAccounts(myCashRegisterInFile);
    cout
        << endl
        <<"Which Gate do you wish to Enter"
        <<"\n1. Gate A "
        <<"\n2. Gate B "
        <<"\n3. Gate C "
        <<"\n4. Print the Report to a File"
        <<"\n0. EXIT\n"
        <<"\nEnter Gate option <1-3>: ";
        cin >> myGate.choice;
   do {
       //main do while loop for my menu functions which are called in main

        while (myGate.choice[0] < '0' || myGate.choice[0]  > '4')
        {//while loop to keep entering choices if they are not 1 through 4 each option chooses gate, exit or print to file
            cout << "Please enter a valid menu choice: ";
            cin >> myGate.choice;
        }
        if (myGate.choice[0] =='1')
        {
            myGate.gateSelectorGateA(myGate);
            menuParkinglotselect();

        }
        else if (myGate.choice[0] =='2')
        {
            myGate.gateSelectorGateB(myGate);
            menuParkinglotselect();
        }
        else if (myGate.choice[0] =='3')
        {
            myGate.gateSelectorGateC(myGate);
            menuParkinglotselect();
        }
        else if (myGate.choice[0] == '4')
        {
            ofstream Outfile;
            //open and create out file
            Outfile.open("parking_information.txt");
            if(!Outfile)
            {   //error if in file fails to open
            cout << "Error sending to the file!!"<<endl;
            }//print to file all my data for cars, money collected for the day and total dollar count
            Outfile
            <<"Total Visited Cars:"
            <<myGate.visitorCars
            <<endl
            <<"Total Emergency Cars:";
            myGate.EmergencyCars(Outfile,myGate);
            Outfile
            <<"\nTotal Cash at the End of Day: $"
            <<myCashRegister.TotalcreditFound(myCashRegister.totalCost)
            << endl;
            myGate.moneyCount1=myCashRegister.TotalcreditFound(myCashRegister.totalCost)-5025;
            Outfile
            <<"Total Amount Earned by the gateSelector Machine: $"
            << myGate.moneyCount1;
            Outfile.close();
            cout <<"Printing to file successful! Exit now!\n";
            exit(1);
        }
        else if (myGate.choice[0] == '0')
        {
            exit(1);
        }//exit if 0 pressed
    }while (myGate.choice[0]!='0');
    // end do while loop
    return 0;
}
//another character menu that is my second do while loop to go through the options for cost and distance of gate
char gateSelector::menuParkinglotselect(){

    cout
        << "Select a criteria to allot a Lot:\n"
        << "1. Based on Cost- Cheapest Lot\n"
        << "2. Based on Distance- Closest to Gate\n"
        << "0. Exit\n"
        << "Enter Option <1-2>: ";
            //start of do while loop to go through menu choices
        cin >> myGate.choice1;
        while (myGate.choice1[0] < '0' || myGate.choice1[0]  > '2')
        {
             cout << "Please enter a valid menu choice: ";
             cin >> myGate.choice1;
        }
        if (myGate.choice1[0] == '0')
        {
            exit(1);
        }//if 0 exit
        else if (myGate.choice1[0] =='1')
        {   //allots space based on cost
            cout
                <<"You have been allotted ";
            //series of if statements to choose the cheapest available spot if it is not full if full move to next cheapest etc
            if(myGate.AvailableSpots[2][2]!=0)
                {
                    myGate.AvailableSpots[2][2]=myGate.AvailableSpots[2][2]-1;
                    cout
                        <<myGate.parkingLot[2][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][2];
                }
                else if(myGate.AvailableSpots[2][1]!=0)
                {
                    myGate.AvailableSpots[2][1]=myGate.AvailableSpots[2][1]-1;
                    cout
                        <<myGate.parkingLot[2][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][1];
                }
                else if(myGate.AvailableSpots[1][2]!=0)
                {
                    myGate.AvailableSpots[1][2]=myGate.AvailableSpots[1][2]-1;
                    cout
                        <<myGate.parkingLot[1][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][2];
                }
                else if(myGate.AvailableSpots[0][2]!=0)
                {
                    myGate.AvailableSpots[0][2]=myGate.AvailableSpots[0][2]-1;
                    cout
                        <<myGate.parkingLot[0][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][2];
                }
                else if(myGate.AvailableSpots[1][1]!=0)
                {
                    myGate.AvailableSpots[1][1]=myGate.AvailableSpots[1][1]-1;
                    cout
                        <<myGate.parkingLot[1][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][1];
                }
                else if(myGate.AvailableSpots[2][0]!=0)
                {
                    myGate.AvailableSpots[2][0]=myGate.AvailableSpots[2][0]-1;
                    cout
                        <<myGate.parkingLot[2][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][0];
                }
                else if(myGate.AvailableSpots[0][1]!=0)
                {
                    myGate.AvailableSpots[0][1]=myGate.AvailableSpots[0][1]-1;
                    cout
                        <<myGate.parkingLot[0][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][1];
                }
                else if(myGate.AvailableSpots[1][0]!=0)
                {
                    myGate.AvailableSpots[1][0]=myGate.AvailableSpots[1][0]-1;
                    cout
                        <<myGate.parkingLot[1][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][0];
                }
                else if(myGate.AvailableSpots[0][0]!=0)
                {
                    myGate.AvailableSpots[0][0]=myGate.AvailableSpots[0][0]-1;
                    cout
                        <<myGate.parkingLot[0][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][0];
                }
                 if(myGate.AvailableSpots[0][0]==0)
                {//cout if all spots are full
                    cout << "All Lots are full - Sorry!!\n";
                }
            myCashRegister.MenuEnterCash();
            //function to loop cash menu
          }

        else if (myGate.choice1[0] =='2')
        {
            cout //series of if statements to choose the spot available closest to the gate A,B,C  if the spot is not full
                // if the spot is full move to next closest spot etc
                <<"You have been allotted ";
                if(myGate.choice[0] =='1')
                {//closest spot for gate A
                    if(myGate.AvailableSpots[0][0]!=0)
                    {
                    myGate.AvailableSpots[0][0]=myGate.AvailableSpots[0][0]-1;
                    cout
                        <<myGate.parkingLot[0][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][0];

                    }
                    else if(myGate.AvailableSpots[0][1]!=0)
                    {
                    myGate.AvailableSpots[0][1]=myGate.AvailableSpots[0][1]-1;
                    cout
                        <<myGate.parkingLot[0][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][1];
                    }
                    else if(myGate.AvailableSpots[1][0]!=0)
                    {
                    myGate.AvailableSpots[1][0]=myGate.AvailableSpots[1][0]-1;
                    cout
                        <<myGate.parkingLot[1][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][0];
                    }
                    else if(myGate.AvailableSpots[0][2]!=0)
                    {
                    myGate.AvailableSpots[0][2]=myGate.AvailableSpots[0][2]-1;
                    cout
                        <<myGate.parkingLot[0][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][2];
                    }
                    else if(myGate.AvailableSpots[1][1]!=0)
                    {
                    myGate.AvailableSpots[1][1]=myGate.AvailableSpots[1][1]-1;
                    cout
                        <<myGate.parkingLot[1][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][1];
                    }
                    else if(myGate.AvailableSpots[2][0]!=0)
                    {
                    myGate.AvailableSpots[2][0]=myGate.AvailableSpots[2][0]-1;
                    cout
                        <<myGate.parkingLot[2][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][0];
                    }
                    else if(myGate.AvailableSpots[1][2]!=0)
                    {
                    myGate.AvailableSpots[1][2]=myGate.AvailableSpots[1][2]-1;
                    cout
                        <<myGate.parkingLot[1][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][2];
                    }
                    else if(myGate.AvailableSpots[2][1]!=0)
                    {
                    myGate.AvailableSpots[2][1]=myGate.AvailableSpots[2][1]-1;
                    cout
                        <<myGate.parkingLot[2][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][1];
                    }
                    else if(myGate.AvailableSpots[2][2]!=0)
                    {
                    myGate.AvailableSpots[2][2]=myGate.AvailableSpots[2][2]-1;
                    cout
                        <<myGate.parkingLot[2][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][2];
                    }
                    else if(myGate.AvailableSpots[2][2]==0)
                    {//cout if all spots are full
                    cout << "All Lots are full - Sorry!!\n";
                    }
                }
                else if(myGate.choice[0] =='2')
                {//closest spot for gate B
                   if(myGate.AvailableSpots[2][0]!=0)
                    {
                    myGate.AvailableSpots[2][0]=myGate.AvailableSpots[2][0]-1;
                    cout
                        <<myGate.parkingLot[2][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][0];
                    }
                   else if(myGate.AvailableSpots[2][1]!=0)
                    {
                    myGate.AvailableSpots[2][1]=myGate.AvailableSpots[2][1]-1;
                    cout
                        <<myGate.parkingLot[2][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][1];
                    }

                    else if(myGate.AvailableSpots[1][0]!=0)
                    {
                    myGate.AvailableSpots[1][0]=myGate.AvailableSpots[1][0]-1;
                    cout
                        <<myGate.parkingLot[1][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][0];
                    }
                    else if(myGate.AvailableSpots[2][2]!=0)
                    {
                    myGate.AvailableSpots[2][2]=myGate.AvailableSpots[2][2]-1;
                    cout
                        <<myGate.parkingLot[2][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][2];
                    }
                     else if(myGate.AvailableSpots[1][1]!=0)
                    {
                    myGate.AvailableSpots[1][1]=myGate.AvailableSpots[1][1]-1;
                    cout
                        <<myGate.parkingLot[1][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][1];
                    }
                    else if(myGate.AvailableSpots[0][0]!=0)
                    {
                    myGate.AvailableSpots[0][0]=myGate.AvailableSpots[0][0]-1;
                    cout
                        <<myGate.parkingLot[0][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][0];
                    }
                    else if(myGate.AvailableSpots[1][2]!=0)
                    {
                    myGate.AvailableSpots[1][2]=myGate.AvailableSpots[1][2]-1;
                    cout
                        <<myGate.parkingLot[1][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][2];
                    }
                    else if(myGate.AvailableSpots[0][1]!=0)
                    {
                    myGate.AvailableSpots[0][1]=myGate.AvailableSpots[0][1]-1;
                    cout
                        <<myGate.parkingLot[0][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][1];
                    }
                    else if(myGate.AvailableSpots[0][2]!=0)
                    {
                    myGate.AvailableSpots[0][2]=myGate.AvailableSpots[0][2]-1;
                    cout
                        <<myGate.parkingLot[0][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][2];
                    }
                    else if(myGate.AvailableSpots[0][2]==0)
                    {//cout if all spots for gate B are full
                    cout << "All Lots are full - Sorry!!\n";
                    }
                }
                else if(myGate.choice[0] =='3')
                {//closest spot for gate C
                   if(myGate.AvailableSpots[2][2]!=0)
                    {
                    myGate.AvailableSpots[2][2]=myGate.AvailableSpots[2][2]-1;
                    cout
                        <<myGate.parkingLot[2][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][2];
                    }
                    else if(myGate.AvailableSpots[2][1]!=0)
                    {
                    myGate.AvailableSpots[2][1]=myGate.AvailableSpots[2][1]-1;
                    cout
                        <<myGate.parkingLot[2][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][1];
                    }
                    else if(myGate.AvailableSpots[1][2]!=0)
                    {
                    myGate.AvailableSpots[1][2]=myGate.AvailableSpots[1][2]-1;
                    cout
                        <<myGate.parkingLot[1][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][2];
                    }
                    else if(myGate.AvailableSpots[1][1]!=0)
                    {
                    myGate.AvailableSpots[1][1]=myGate.AvailableSpots[1][1]-1;
                    cout
                        <<myGate.parkingLot[1][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][1];
                    }
                    else if(myGate.AvailableSpots[0][2]!=0)
                    {
                    myGate.AvailableSpots[0][2]=myGate.AvailableSpots[0][2]-1;
                    cout
                        <<myGate.parkingLot[0][2]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][2]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][2];
                    }

                    else if(myGate.AvailableSpots[2][0]!=0)
                    {
                    myGate.AvailableSpots[2][0]=myGate.AvailableSpots[2][0]-1;
                    cout
                        <<myGate.parkingLot[2][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[2][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[2][0];
                    }
                    else if(myGate.AvailableSpots[1][0]!=0)
                    {
                    myGate.AvailableSpots[1][0]=myGate.AvailableSpots[1][0]-1;
                    cout
                        <<myGate.parkingLot[1][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[1][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[1][0];
                    }
                    else if(myGate.AvailableSpots[0][1]!=0)
                    {
                    myGate.AvailableSpots[0][1]=myGate.AvailableSpots[0][1]-1;
                    cout
                        <<myGate.parkingLot[0][1]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][1]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][1];
                    }

                    else if(myGate.AvailableSpots[0][0]!=0)
                    {
                    myGate.AvailableSpots[0][0]=myGate.AvailableSpots[0][0]-1;
                    cout
                        <<myGate.parkingLot[0][0]
                        <<endl
                        <<"Cost of the selected Lot $"
                        <<myGate.Cost[0][0]
                        <<endl;
                        myGate.moneyCount=myGate.Cost[0][0];
                    }
                   else if(myGate.AvailableSpots[0][0]==0)
                    {//Print out message if all spots are full
                    cout << "All Lots are full - Sorry!!\n";
                    }
                }
               myCashRegister.MenuEnterCash();
               //function to loop cash menu
            }  //cash register to cout and keep track total bills and total cash collected
                myCashRegister.ParkMachineAccounts(myCashRegisterInFile);
                cout
                    <<"\nEnter valid operation below:\n"
                    <<"1. Insert Cash\n"
                    <<"2. Allot a Parking Space\n"
                    <<"0. EXIT\n"
                    <<"Enter Option <1-2>: ";
                cin >>myGate.choice2;
            while (myGate.choice2[0] < '0' || myGate.choice2[0]  > '2')
            {  //if customer inputs invalid menu choice
                cout << "Please enter a valid menu choice: ";
                cin >> myGate.choice2;
            }
            while (myGate.choice2[0]=='1')
            {
                cout << "You have already paid select 2 to allot your space!!\n"
                <<"\nEnter valid operation below:\n"
                <<"1. Insert Cash\n"
                <<"2. Allot a Parking Space\n"
                <<"0. EXIT\n"
                <<"Enter Option <1-2>: ";
                cin >>myGate.choice2;
            }
            while (myGate.choice2[0] < '0' || myGate.choice2[0]  > '2')
            { //if customer inputs invalid menu choice
                cout << "Please enter a valid menu choice: ";
                cin >> myGate.choice2;
            }
            if (myGate.choice2[0] == '0')
            {
                exit(1);
            }//press 0 to exit
            else if (myGate.choice2[0] == '2'){
                //if choice 2 then allot gate and give out change
                cout << "Thanks You. Gate is now open. Your change is: $"
                     << myGate.moneyCount1-myGate.moneyCount
                     << endl;
                        //equation to add up my total cost and give out change
                        myCashRegister.totalCost=myCashRegister.totalCost+myGate.moneyCount-myGate.moneyCount1;
                        change=myGate.moneyCount1-myGate.moneyCount;
                        quarters=(change*100);
                        if (quarters>100&&quarters<200)
                        {
                            quarters=quarters-100;
                        }
                        else if (quarters>200&&quarters<300)
                        {
                            quarters=quarters-200;
                        }
                        else if (quarters>300&&quarters<400)
                        {
                            quarters=quarters-300;
                        }
                        else if (quarters>400&&quarters<500)
                        {
                            quarters=quarters-400;
                        }
                         if (quarters>500&&quarters<1000)
                        {
                            quarters=quarters-500;
                            if (quarters>100&&quarters<200)
                            {
                            quarters=quarters-100;
                            }
                            else if (quarters>200&&quarters<300)
                            {
                            quarters=quarters-200;
                            }
                            else if (quarters>300&&quarters<400)
                            {
                            quarters=quarters-300;
                            }
                            else if (quarters>400&&quarters<500)
                            {
                            quarters=quarters-400;
                            }
                        }
                        if (quarters>1000&&quarters<1500)
                        {   quarters=quarters-1000;
                            if (quarters>100&&quarters<200)
                            {
                            quarters=quarters-100;
                            }
                            else if (quarters>200&&quarters<300)
                            {
                            quarters=quarters-200;
                            }
                            else if (quarters>300&&quarters<400)
                            {
                            quarters=quarters-300;
                            }
                            else if (quarters>400&&quarters<500)
                            {
                            quarters=quarters-400;
                            }
                        }
                        if (quarters>1500)
                        {
                            quarters=quarters-1500;
                            if (quarters>100&&quarters<200)
                            {
                            quarters=quarters-100;
                            }
                            else if (quarters>200&&quarters<300)
                            {
                            quarters=quarters-200;
                            }
                            else if (quarters>300&&quarters<400)
                            {
                            quarters=quarters-300;
                            }
                            else if (quarters>400&&quarters<500)
                            {
                            quarters=quarters-400;
                            }
                        }
                        //a series of if statements to reduce the total dollars in my cash register due to change that would be given out
                        if (quarters ==25)
                        {  //Subtracts Quarters
                            myCashRegisterInFile[5].totaldollars--;
                        }
                        else if (quarters==50)
                        {   //Subtracts Quarters
                            myCashRegisterInFile[5].totaldollars--;
                            myCashRegisterInFile[5].totaldollars--;
                        }
                        else if (quarters ==75)
                        {   //Subtracts Quarters
                            myCashRegisterInFile[5].totaldollars--;
                            myCashRegisterInFile[5].totaldollars--;
                            myCashRegisterInFile[5].totaldollars--;
                        }
                        if(change>=15){
                            change10=change/10;
                            change5=(change-10)/5;
                            change1=change-15;

                            if (change10 ==1)
                            {   //Subtracts $10's
                                myCashRegisterInFile[3].totaldollars--;
                            }
                            if (change5 ==1)
                            {   //Subtracts $5's
                            myCashRegisterInFile[2].totaldollars--;
                            }
                            if (change1 ==1)
                            {//Subtracts $1's
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==2)
                            {//Subtracts $1's x2
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==3)
                            {//Subtracts $1's x3
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==4)
                            {//Subtracts $1's x4
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                        }
                        if(change>=10){
                            change10=change/10;
                            change5=(change-10)/5;
                            change1=change-10;

                            if (change10 ==1)
                            {   //Subtracts $10's
                            myCashRegisterInFile[3].totaldollars--;
                            }
                            if (change5 ==1)
                            {   //Subtracts $5's
                            myCashRegisterInFile[2].totaldollars--;
                            }
                            if (change1 ==1)
                            {//Subtracts $1's
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==2)
                            {//Subtracts $1's x2
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                           else if (change1 ==3)
                            {//Subtracts $1's x3
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==4)
                            {//Subtracts $1's x4
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                        }
                        if(change>=5)
                        {   change1=change-5;
                            change5=(change/5);
                            if (change5 ==1)
                            {//Subtracts $5's
                            myCashRegisterInFile[2].totaldollars--;
                            }
                            if (change1 ==1)
                            {//Subtracts $1's
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==2)
                            {//Subtracts $1's x2
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                           else if (change1 ==3)
                            {//Subtracts $1's x3
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==4)
                            {//Subtracts $1's x4
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                        }
                        if(change<5)
                        {   change1=change;
                            if (change1 ==1)
                            {//Subtracts $1's
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==2)
                            {//Subtracts $1's x2
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                           else if (change1 ==3)
                            {//Subtracts $1's x3
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                            else if (change1 ==4)
                            {//Subtracts $1's x4
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            myCashRegisterInFile[1].totaldollars--;
                            }
                        }
                //allots the gates based on which original gate the person came in from
                if (myGate.choice[0] =='1')
                {   //allots and prints out gate A
                    myGate.gateSelectorGateA(myGate);
                    cout <<"Gate Allotted Successfully.\n";
                    myGate.visitorCars++;//increments cars visited
                    //restarts the loop to start the menu all over again
                    myCashRegister.ParkMachineAccounts(myCashRegisterInFile);
                    cout
                        << endl
                        <<"Which Gate do you wish to Enter"
                        <<"\n1. Gate A "
                        <<"\n2. Gate B "
                        <<"\n3. Gate C "
                        <<"\n4. Print the Report to a File"
                        <<"\n0. EXIT\n"
                        <<"\nEnter Gate option <1-3>: ";
                        cin >> myGate.choice;
                }
                else if (myGate.choice[0] =='2')
                {   //allots and prints out gate A
                    myGate.gateSelectorGateB(myGate);
                    cout <<"Gate Allotted Successfully.\n";
                    myGate.visitorCars++;//increments cars visited
                    //restarts the loop to start the menu all over again
                    myCashRegister.ParkMachineAccounts(myCashRegisterInFile);
                    cout
                        << endl
                        <<"Which Gate do you wish to Enter"
                        <<"\n1. Gate A "
                        <<"\n2. Gate B "
                        <<"\n3. Gate C "
                        <<"\n4. Print the Report to a File"
                        <<"\n0. EXIT\n"
                        <<"\nEnter Gate option <1-3>: ";
                        cin >> myGate.choice;
                }
                else if (myGate.choice[0] =='3')
                {   //allots and prints out gate C
                    myGate.gateSelectorGateC(myGate);
                    cout <<"Gate Allotted Successfully.\n";
                    myGate.visitorCars++;//increments cars visited
                    //restarts the loop to start the menu all over again
                    myCashRegister.ParkMachineAccounts(myCashRegisterInFile);
                    cout
                        <<endl
                        <<"Which Gate do you wish to Enter"
                        <<"\n1. Gate A "
                        <<"\n2. Gate B "
                        <<"\n3. Gate C "
                        <<"\n4. Print the Report to a File"
                        <<"\n0. EXIT\n"
                        <<"\nEnter Gate option <1-3>: ";
                        cin >> myGate.choice;
                }
            }

     return 0;
}
//void function to print from my infile array out gate A
void gateSelector::gateSelectorGateA(gateSelector myGate ){
    cout<<"===============================================================================\n\n"
    << setw (54)
    <<"GATE A: Lot Information\n"
    <<"===============================================================================\n"
    << endl
    <<"LOT ID : MAX CAPACITY :      AVAILABLE SPOTS : COST<$DD.CC> : DISTANCE \n"
    <<"-------------------------------------------------------------------------------\n"
    << endl;
    //for loop to loop through my array and add up total available spots
     for (int j=0;j<3; j++)
        for (int i=0;i<3;i++)
        //equation to add up my total Available parking spots
        myGate.totalparkingspots += myGate.AvailableSpots[j][i];
         //nested for loop to print all info in Gate A order according to distance closest to gate
         //if statement to print out Gate A table at regular prices if Available spots is above 50
        if(myGate.totalparkingspots>50){
            for (int j=0;j<3; j++){
                for (int i=0;i<3;i++)
                {
                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i] << " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]<< " :"
                    << setw(8)
                    << myGate.distanceA[j][i]
                    << endl;
                myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }
        //if statement to print out Gate A table at $5.75 more if Available spots is above 25 but less then 50
        else if(myGate.totalparkingspots>25 && myGate.totalparkingspots<50){
            for (int j=0;j<3; j++){
                for (int i=0;i<3;i++)
                {

                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i] << " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]+5.75<< " :"
                    << setw(8)
                    << myGate.distanceA[j][i]
                    << endl;
                myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }
        //if statement to print out Gate A table at $7.25 more if Available spots is less then 25
        else if(myGate.totalparkingspots<25){
            for (int j=0;j<3; j++){
                for (int i=0;i<3;i++)
                {

                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i] << " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]+7.25<< " :"
                    << setw(8)
                    << myGate.distanceA[j][i]
                    << endl;
                myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }
            cout
                <<endl
                << setw(9)
                <<"Total :"
                << setw(13)
                <<myGate.totalMaxCapacity<< " :"
                //prints out total max capacity
                << setw(21)
                <<myGate.totalparkingspots<< " :\n";
                //prints out total parking spots left after emergency vehicles and visitors
        //function to output current date and time
        outputtime();

 }
//void function to print from my infile array out gate B
void gateSelector::gateSelectorGateB(gateSelector myGate){
    cout<<"===============================================================================\n\n"
    << setw (54)
    <<"GATE B: Lot Information\n"
    <<"===============================================================================\n"
    <<endl
    <<" LOT ID : MAX CAPACITY :      AVAILABLE SPOTS : COST<$DD.CC> : DISTANCE \n"
    <<"-------------------------------------------------------------------------------\n"
    <<endl;
    //for loop to loop through my array and add up total available spots
     for (int j=0;j<3; j++)
        for (int i=0;i<3;i++)
        //equation to add up my total Available parking spots
        myGate.totalparkingspots += myGate.AvailableSpots[j][i];
         //nested for loop to print all info in Gate B order according to distance closest to gate
         //if statement to print out Gate B table at regular prices if Available spots is above 50
        if(myGate.totalparkingspots>50)
        {
            for (int j=2;j>=0; j--){
                for (int i=0;i<3;i++)
                {
                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i]<< " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]<< " :"
                    << setw(8)
                    << myGate.distanceB[j][i]
                    << endl;
                    myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }
       //if statement to print out Gate B table at $5.75 more if Available spots is above 25 but less then 50
        else if(myGate.totalparkingspots>25 && myGate.totalparkingspots<50)
        {
            for (int j=2;j>=0; j--){
                for (int i=0;i<3;i++)
                {
                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i]<< " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]+5.75<< " :"
                    << setw(8)
                    << myGate.distanceB[j][i]
                    << endl;
                    myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }
        //if statement to print out Gate B table at $7.25 more if Available spots is less then 25
        else if(myGate.totalparkingspots<25)
        {
            for (int j=2;j>=0; j--){
                for (int i=0;i<3;i++)
                {
                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i]<< " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]+ 7.25<< " :"
                    << setw(8)
                    << myGate.distanceB[j][i]
                    << endl;
                    myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }
            cout
                <<endl
                << setw(9)
                <<"Total :"
                << setw(13)
                <<myGate.totalMaxCapacity<< " :"
                << setw(21)
                <<myGate.totalparkingspots<< " :\n";
                //prints out total parking spots left after emergency vehicles and visitors
        //function to output current date and time
        outputtime();
 }
//void function to print from my infile array out gate C
void gateSelector::gateSelectorGateC(gateSelector myGate){
    cout<<"===============================================================================\n\n"
    << setw (54)
    <<"GATE C: Lot Information\n"
    <<"===============================================================================\n"
    <<endl
    <<" LOT ID : MAX CAPACITY :      AVAILABLE SPOTS : COST<$DD.CC> : DISTANCE \n"
    <<"-------------------------------------------------------------------------------\n"
    <<endl;
    //for loop to loop through my array and add up total available spots
     for (int j=0;j<3; j++)
        for (int i=0;i<3;i++)
        //equation to add up my total Available parking spots
        myGate.totalparkingspots += myGate.AvailableSpots[j][i];
        //nested for loop to print all info in Gate C order according to distance closest to gate
        //if statement to print out Gate C table at regular prices if Available spots is above 50
        if(myGate.totalparkingspots>50)
        {
            for (int j=2;j>=0; j--){
                for (int i=2;i>=0;i--)
                {
                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i]<< " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]<< " :"
                    << setw(8)
                    << myGate.distanceC[j][i]
                    << endl;
                    myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }
        //if statement to print out Gate C table at $5.75 more if Available spots is above 25 but less then 50
        else if(myGate.totalparkingspots>25 && myGate.totalparkingspots<50)
        {
            for (int j=2;j>=0; j--){
                for (int i=2;i>=0;i--)
                {
                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i]<< " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]+5.75<< " :"
                    << setw(8)
                    << myGate.distanceC[j][i]
                    << endl;
                    myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }
        //if statement to print out Gate C table at $7.25 more if Available spots is less then 25
        else if(myGate.totalparkingspots<25)
        {
            for (int j=2;j>=0; j--){
                for (int i=2;i>=0;i--)
                {
                cout
                    << setw(7)
                    << myGate.parkingLot[j][i]<< " :"
                    << setw(13)
                    << myGate.MaxCapacity[j][i]<< " :"
                    << setw(21)
                    << myGate.AvailableSpots[j][i]<< " :"
                    << setw(8)
                    << "$"
                    << setprecision(2)
                    << fixed
                    << myGate.Cost[j][i]+7.25<< " :"
                    << setw(8)
                    << myGate.distanceC[j][i]
                    << endl;
                    myGate.totalMaxCapacity += myGate.MaxCapacity[j][i];
                }
            }
        }

            cout
                <<endl
                << setw(9)
                <<"Total :"
                << setw(13)
                <<myGate.totalMaxCapacity<< " :"
                << setw(21)
                <<myGate.totalparkingspots<< " :\n";
                //prints out total parking spots left after emergency vehicles and visitors
        //function to output current date and time
        outputtime();
}
void gateSelector:: outputtime(){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout
    << endl
    << setw(50)
    << "Present Time: "
    << asctime(now)
    << endl;
}


