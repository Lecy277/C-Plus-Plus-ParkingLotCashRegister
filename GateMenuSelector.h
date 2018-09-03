#ifndef GATEMENUSELECTOR_H_INCLUDED
#define GATEMENUSELECTOR_H_INCLUDED
#include <ctime>
#include <stdlib.h>
//included header files for time and random functions in order to use my rand function to load my array in my default constructor
using namespace std;
//my main class to create variables and functions for my gate menus
class gateSelector{
    private:
        //creating a choice menu so customer can only enter one character
        char choice[1];
        char choice1[1];
        char choice2[1];
        double change;
        int change1, change5, change10, quarters;
        //int to load my available spots array with random characters up to 10 percent
        int a,b,c,d,e,f,g,h,i;
        int visitorCars, totalparkingspots, totalMaxCapacity;
        //series arrays to print out all my gate info for Gates A,B,C
        int distanceA[3][3]={{10,20,30,},
                            {20,30,40,},
                            {30,40,50,}};
        int distanceB[3][3]={{30,40,50,},
                            {20,30,40,},
                            {10,20,30,}};
        int distanceC[3][3]={{50,40,30,},
                            {40,30,20,},
                            {30,20,10,}};
        int MaxCapacity[3][3]={{40,20,50,},
                              {30,55,15,},
                              {20,33,27,}};
        double Cost[3][3]={{25.00,22.50,20.00,},
                            {22.50,20.00,17.50,},
                            {20.00,17.50,15.00,}};
        //Available spots array will be loaded in default constructor below
        int AvailableSpots[3][3]={{a,b,c,},
                                  {d,e,f,},
                                  {g,h,i,}};
        char parkingLot[3][3]= {{'A','B','C',},
                               {'D','E','F',},
                               {'G','H','I',}};
    public:
        double moneyCount=0;
        double moneyCount1=0;
        //adding all my member functions of my class
        char gateMenuSelection();
        char menuParkinglotselect();
        void gateSelectorGateA(gateSelector myGate);
        void gateSelectorGateB(gateSelector myGate);
        void gateSelectorGateC(gateSelector myGate);
        void outputtime();
        void EmergencyCars(ofstream& Outfile, gateSelector myGate);
        //default constructor to load my array with my available spots minus my randomized to 10 percent of my emergency vehicles
        //default constructor loads the array only once at the start of the program
        //so that it keeps a running total of all available spots
        gateSelector(){
        srand(time(NULL));
        for (int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j){
            AvailableSpots[i][j] = MaxCapacity[i][j] - (rand()% (MaxCapacity[i][j]/10));
            //equation in my for loop to randomize the emergency cars in my parking lots up to 10 percent
            }
        }
};
//creating my class objects and externing them so they can be used outside the h file
extern gateSelector myGate;

#endif // GATEMENUSELECTOR_H_INCLUDED
