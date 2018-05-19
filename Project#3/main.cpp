/*
 DESOTO, Dominic

 IS130A Project #3
 Airline Booking System
 Due: 2014/10/07

 WORKING
 */


// START:Airline Booking;

// include the preprocessor library for input/output screen;
#include <iostream>
// include the preprocessor library for formatting;
#include <iomanip>
// include the preprocessor library for math equations;
#include <cmath>

// define the scope of functions;
using namespace std;

// define void function getData, declare double with address for ticket class, double with address for number of miles traveled, and double with address for number of transfers;
void getData (char &ticketClass, double &nmbrMiles, int &nmbrTransfers);
// define double function calcFare, declare character ticket class, double with address for base fare, double number of miles, integer for number of transfers, double with address for first adjusted fare, double with address for second adjusted fare, and double for total cost;
double calcFare (char ticketClass, double &baseFare, double nmbrMiles, int nmbrTransfers, double &adjustedFare1, double &surchargeFare, double totalCost);
// define void function printData, declare double for base fare, integer for number of transfers, double for first adjust fare, double for second adjusted fare, and double for total cost;
void printData (char ticketClass, double baseFare, int nmbrTransfers, double adjustedFare1, double surchargeFare, double totalCost);


// main function header;
int main()
{
// declare characters for running the program again and ticket class;
char programRun, ticketClass;
// declare integers for the number of transfers;
int nmbrTransfers;
// declare doubles and set each variable to zero for number of miles, the base fare, the first adjusted fare, the second adjusted fare, and the total cost;
double nmbrMiles = 0, baseFare = 0, adjustedFare1 = 0, surchargeFare = 0, totalCost = 0;

    // display: Welcome to the JetBlue Airline booking system!  Skip several lines to enable
    cout << "Welcome to the JetBlue Airline booking system!"<< endl << endl << endl;

    // begin do while () loop to enable program to repeat as necessary;
    do
    {
        // place call-by-reference for getData in main function;
        getData (ticketClass, nmbrMiles, nmbrTransfers);
        // place call-by-reference for calcFare in main function, totalCost will equal calcFare;
        totalCost = calcFare (ticketClass, baseFare, nmbrMiles, nmbrTransfers, adjustedFare1, surchargeFare, totalCost);
        // place call-by-reference for printData in main function;
        printData (ticketClass, baseFare, nmbrTransfers, adjustedFare1, surchargeFare, totalCost);

        // display query: Run the program again;
        cout << "Run the program again? ";
        // allow user to input answer;
        cin >> programRun;
        // enable additional space before following text;
        cout << endl << endl;

    // create parameters for do while () loop, specifying that program should repeat itself so long as N is not input by user;
    } while (programRun != 'N' && programRun != 'n');

    // return zero for main function;
    return 0;
}

// begin void function getData, parameters: character ticket class with address, double for number of miles with address, integer for number of transfers with address;
void getData (char &ticketClass, double &nmbrMiles, int &nmbrTransfers)
{
    // output: please enter the ticket class;
    cout << "Please enter the ticket class => ";
    // user's input;
    cin >> ticketClass;
    // output: please enter the ticket class;
    cout << "Please enter the number of miles => ";
    // user's input;
    cin >> nmbrMiles;
    // output: please enter the number of transfers;
    cout << "Please enter the number of transfers => ";
    // user's input;
    cin >> nmbrTransfers;

    // return nothing, because it is a void function;
    return;
}

// begin calcFare function, parameters: character for ticket class, double for base fare with address included, double for number of miles, integer for number of transfers, double for first adjusted fare with address, double for second adjusted fare with address, and a double for total cost;
double calcFare (char ticketClass, double &baseFare, double nmbrMiles, int nmbrTransfers, double &adjustedFare1, double &surchargeFare, double totalCost)
{
// declare double for multiplier, equal to zero;
double multiplier = 0;

    // begin switch statement, with ticket class for the case;
    switch(ticketClass)
        {
        // name first case 'F';
        case'F':
            // set statement for case, multiplier for case F equals 2.5;
            multiplier = 2.50;
            // end case statement;
            break;
        // designate second case as 'E';
        case'E':
            // set statement for case, multiplier of case E equals 1;
            multiplier = 1.0;
            // end case statement;
            break;
        // designate second case as 'O';
        case'O':
            // set statement for case, multiplier of case O equals 5;
            multiplier = 5.0;
            // end case statement;
            break;
        // designate second case as 'X';
        case'X':
            // set statement for case, multiplier of case X equals 3;
            multiplier = 3.0;
            // end case statement;
            break;
        }

    // set up equation to find base fare: base fare equals the number of miles multiplied;
    baseFare = nmbrMiles * 0.10;
    // equation to find first adjusted fare: first adjusted fare is equal to the base fare minus fifty times the number of transfers;
    adjustedFare1 = baseFare - 50 * nmbrTransfers;
    // equation to find second adjusted fare: second adjusted fare is equal to first adjusted fare times the multiplier;
    surchargeFare = adjustedFare1 * multiplier;
    // equation to find the total cost: total cost is equal to the second adjusted fare times 1.10 to take tax into account;
    totalCost = surchargeFare * 1.10;

    // return total cost for calcFare function;
    return totalCost;
}

// begin void function printData, with the following parameters: character for ticket class, double for base fare, integer for number of transfers, double for first adjusted fare, double for second adjusted fare, and double for total cost;
void printData (char ticketClass, double baseFare, int nmbrTransfers, double adjustedFare1, double surchargeFare, double totalCost)
{
    // enable space between previous and following text;
    cout << endl;
    // output: the base fare is $____, make variable baseFare display with set precision to have a decimal value of two;
    cout << "The base fare is $" << fixed << setprecision(2) << baseFare << endl;
    // output: with ____ transfers, the base fare is $_____, make first adjusted fare display with decimal values to the hundredths place;
    cout << "With " << nmbrTransfers << " transfers, the base fare is $" << fixed << setprecision(2) << adjustedFare1 << endl;
    // output: with ___-CLASS surcharge, the cost is $_____, make second adjusted fare display with decimal values to the hundredths place;
    cout << "With " << ticketClass << "-CLASS surcharge, the cost is $" << fixed << setprecision(2) << surchargeFare << endl;
    // enable space between preceding and following text;
    cout << endl;
    // output: with 10% tax, the total cost is $_______, make total cost display with decimal values to the hundredths place and allow a couple lines of space to separate from outputs in main function;
    cout << "With 10% tax, the total cost is $" << fixed << setprecision(2) << totalCost << endl << endl;

    // return nothing, as it is a void function;
    return;
}
//END.


/* Program output:
Welcome to the JetBlue Airline booking system!


Please enter the ticket class => F
Please enter the number of miles => 7810
Please enter the number of transfers => 2

The base fare is $781.00
With 2 transfers, the base fare is $681.00
With F-CLASS surcharge, the cost is $1702.50

With 10% tax, the total cost is $1872.75

Run the program again? Y

Please enter the ticket class =>
*/
