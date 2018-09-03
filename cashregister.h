#ifndef PARKINGCONTROLMAIN_H_INCLUDED
#define PARKINGCONTROLMAIN_H_INCLUDED


using namespace std;
//class to add up my cash for my parking program
class cashRegister{
     private:
         //encapsulation of some of my data
        string bills, bills1;
        char choice2[0];
        char dummy;
        int credit, totaldollars1;
    public:
        //some data was needed to be public for my functions to all work together
        int emergencyCars=0;
        double totalCost=0;
        int totaldollars;
        int cashOnHand1, cashOnHand5, cashOnHand10, cashOnHand20, cashOnHandQaurter;
        //adding all my member functions of my class
        double TotalcreditFound(double &y);
        void Getinfile(cashRegister myCashRegisterInFile[]);
        void ParkMachineAccounts(cashRegister myCashRegisterInFile[]);
        void ParkMachineAccounts2(cashRegister myCashRegisterInFile[]);
        char MenuEnterCash();

};
//creating my class objects and externing them so they can be used outside the h file
extern cashRegister myCashRegister;
extern cashRegister myCashRegisterInFile[6];

#endif // PARKINGCONTROLMAIN_H_INCLUDED
