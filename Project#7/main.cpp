/*
 DESOTO, Dominic

 IS130A Project #7
 Vehicle Log with Multidimensional Arrays
 Due: 2014/11/11

 WORKING
 */

#include <iostream>
#include <cmath>


using namespace std;

// set up constant integers for code, with 4 columns and rows supporting up to 100 vehicles;
const int rows = 100, cols = 5;

int main() // Log the arrival time of the plane;
{
    // declare integers to be used for first exit, last exit, index, and vehicleData array;
    int vType = 0, firstExit = 0, lastExit = 0, index = 0, vehicleData[rows][cols]={0};

    // display spiel for NYS Thruway Vehicle Log;
    cout << "NYS Thruway I-90 Vehicle Log" << endl;
    cout << "Enter the vehicle type, followed by exits." << endl;
    cout << "Vehicle type entry of 0 terminates input." << endl;

    // set up do-while loop for program to repeat;
    do
    {
        // ask user for vehicle type;
        cout << endl << "Vehicle type => ";
        cin >> vType;
        // if the vehicle type is equal to variable 0, break the code;
        if (vType == 0)
        {
            cout << endl << "Data input terminated." << endl << endl;
            break;
        }
        // otherwise, if vehicle type is passenger or commercial, prompt user for first and last exit numbers;
        else if (vType == 1 || vType == 2)
        {
            cout << "First exit number => ";
            cin >> firstExit;

            cout << "Last exit number => ";
            cin >> lastExit;


            // store input data in the vehicleData array;
            vehicleData[index][0] = index + 1;
            vehicleData[index][1] = vType;
            vehicleData[index][2] = firstExit;
            vehicleData[index][3] = lastExit;
            vehicleData[index][4] = abs(firstExit-lastExit);

            // be sure to increment the index, or else the output will be wrong/blank;
            index++;
        }

    // while-loop continues so long as the vehicle type does not equal 0;
    } while (vType != 0);

        cout << endl;

        // set up heading and column titles for the array;
        cout << "Vehicle Log" << endl << endl;
        cout << "#" << "\t" << "Type" << "\t" << "First" << "\t" << "Last" << "\t" << "Exits" << endl;

        // set up two for-loops, the first for rows and the second for columns;
        for (int i = 0; i < index; i++)
        {

            for (int j = 0; j < cols ; j++)
            {
                // output information stored in the array;
                cout << vehicleData[i][j] << "\t";

            }

            cout << endl;
        }

    //END.
    return 0;
}

/* PROGRAM OUTPUT:

NYS Thruway I-90 Vehicle Log
Enter the vehicle type, followed by exits.
Vehicle type entry of 0 terminates input.

Vehicle type => 1
First exit number => 39
Last exit number => 46

Vehicle type => 1
First exit number => 30
Last exit number => 40

Vehicle type => 2
First exit number => 100
Last exit number => 45

Vehicle type => 2
First exit number => 100
Last exit number => 45

Vehicle type => 2
First exit number => 45
Last exit number => 100

Vehicle type => 0

Data input terminated.


Vehicle Log

#       Type    First   Last    Exits
1       1       39      46      7
2       1       30      40      10
3       2       100     45      55
4       2       100     45      55
5       2       45      100     55


*/
