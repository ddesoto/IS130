/*
 Group #:
 DESOTO, Dominic
 REED, Anthony

 IS130A Project #6
 Vehicle Log with Arrays
 Due: 2014/10/30

 WORKING
*/

//include preprocessor libraries necessary for code;
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // declare integers to be used for first exit, last exit, passenger index and commercial index;
    int firstExit, lastExit, pindex = 0, cindex = 0;
    // declare doubles for passenger count, commercial count, vehicle total, passenger exit sum, commercial exit sum, passenger average, commercial average, and initializers for the passenger and commercial variables;
    double passCnt = 0, commCnt = 0, vehTtl = 0, passExitSum = 0, commExitSum = 0, passAvg = 0, commAvg = 0, pass[100] = {0}, comm [100] = {0};
    // declare char for vehicle type;
    char vehType;
    // display spiel for NYS Thruway Vehicle Log;
    cout << "NYS Thruway I-90 Vehicle Log" << endl;
    cout << "Enter the vehicle type, followed by exits." << endl;
    cout << "Vehicle type entry of X terminates input." << endl;

    // set up do-while loop for program to repeat;
    do
    {
        // ask user for vehicle type;
        cout << endl << "Vehicle type => ";
        cin >> vehType;
        // if the vehicle type is equal to variable X, break the code;
        if (vehType == 'X')
        {
            cout << endl << "Data input terminated." << endl;
            break;
        }
        // otherwise, if vehicle type is passenger or commercial, prompt user for first and last exit numbers;
        else if (vehType == 'P' || vehType == 'C')
        {
            cout << "First exit number => ";
            cin >> firstExit;

            cout << "Last exit number => ";
            cin >> lastExit;

            // if the vehicle type is passenger, take the absolute value of the first exit subtracted by last exit, and enter it into passenger array with location indexed;
            if (vehType == 'P')
            {
                pass[pindex] = abs(firstExit - lastExit);
                // increment index for each equation performed;
                pindex++;
                // increment the amount of passengers vehicles;
                passCnt++;
                // add absolute values of first exits subtracted by last exits to get the sum of the passenger exits;
                passExitSum += abs(firstExit - lastExit);
            }

            // do the same as previous if-statement, but for commercial vehicles instead;
            if (vehType == 'C')
            {
                comm[cindex] = abs(firstExit - lastExit);
                cindex++;
                commCnt++;
                commExitSum += abs(firstExit - lastExit);
            }
        }
    // while loop continues so long as the vehicle type does not equal X;
    } while (vehType != 'X');
    // add the passenger and commercial vehicle counts together to obtain vehicle total;
    vehTtl = passCnt + commCnt;
    // divide the passenger exit sum by the passenger count to obtain an average;
    passAvg = passExitSum / passCnt;
    // perform the same operation for commercial vehicles;
    commAvg = commExitSum / commCnt;

    // display the passenger vehicle listing with the passenger array and i indexing the locations of each value;
    cout << endl << endl << "Personal vehicle exit listing: ";
    for (int i = 0; i < pindex; i++)
    {
        cout << pass[i];
        // stop the comma separation of listings one value before the overall value of the index;
        if (i != pindex - 1)
        {
            cout << ", ";
        }
    }
    // do the same for the commercial array;
    cout << endl << "Commercial vehicle exit listing: ";
    for (int i = 0; i < cindex; i++)
    {
        cout << comm[i];
        if (i != cindex - 1)
        {
            cout << ", ";
        }
    }
    // display total vehicles, passenger vehicle count, passenger average, commercial vehicle count and commercial average for the day;
    cout << endl << endl << "There were a total of " << vehTtl << " vehicles today:" << endl;
    cout << passCnt << " passenger, average travel = " << passAvg << " exits" << endl;
    cout << commCnt << " commercial, average travel = " << commAvg << " exits" << endl;

    //END.
    return 0;
}

/* PROGRAM OUTPUT:

NYS Thruway I-90 Vehicle Log
Enter the vehicle type, followed by exits.
Vehicle type entry of X terminates input.

Vehicle type => P
First exit number => 39
Last exit number => 46

Vehicle type => P
First exit number => 30
Last exit number => 40

Vehicle type => C
First exit number => 100
Last exit number => 45

Vehicle type => C
First exit number => 100
Last exit number => 45

Vehicle type => C
First exit number => 45
Last exit number => 100

Vehicle type => X

Data input terminated.


Personal vehicle exit listing: 7, 10
Commercial vehicle exit listing: 55, 55, 55

There were a total of 5 vehicles today:
2 passenger, average travel = 8.5 exits
3 commercial, average travel = 55 exits

*/
