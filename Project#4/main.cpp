/*
 DESOTO,Dominic

 IS130A Project #4
 Time Conversion
 Due: 2014/10/21

 WORKING
 */

#include <iostream>

using namespace std;

void timeConvert (int& hours, int& minutes, char& time);
void timeConvert (int& hours, int& minutes, int& offset);

int main()
{
    // This is a DRIVER program

    // Variable initialization
    int hours = 0, minutes = 0, offset = 0;
    char time = '\0';

    // Modify these values to test your function
    hours = 23;
    minutes = 15;
    time = 'H';

    timeConvert(hours, minutes, time);
    cout << hours << " " << minutes << " " << time << endl;

    // Modify these values to test your function
    hours = 21;
    minutes = 15;
    offset = -5;

    timeConvert(hours, minutes, offset);
    cout << hours << " " << minutes << " " << offset << endl;

    return 0;
}


void timeConvert (int& hours, int& minutes, char& time)
{
    // This is a STUB, which needs to be fleshed out

    // begin switch statement for military time, AM and PM;
    switch(time)
        {
        // first case is for converting from military time;
        case'H':
            // begin if statement for hours that do not fall within 0-23 for 24h time, and minutes that do not fall within the 0-59 minutes range;
            if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
                {
                    // take action: if hours or minutes are invalid then time must be set to X, hours to 0, and minutes to 0;
                    time = 'X', hours = 0, minutes = 0;
                }
            // begin separate if statement: if the hours input are less than or equal to 1...
            else if (hours <= 11)
                {
                    // ...then make time AM;
                    time = 'A';
                    // if time is AM and the military hours are set to zero...
                    if (time = 'A', hours == 0)
                        {
                            // ...then convert hours to 12;
                            hours = 12;
                        }
                }
            // begin separate if statement: if military hours are greater than or equal to 12...
            else if (hours >= 12)
                {
                    // ...then make time PM;
                    time = 'P';
                    // another if statement: if military hours are anything but 12...
                    if (hours != 12)
                        {
                            // ...subtract 12 from the military hours to get the correct PM value;
                            hours = hours - 12;
                        }
                }

            break;
        // case for converting from AM time;
        case'A':
            // change time being used from AM to military;
            time = 'H';
            // if statement: if hours are not within 0-12 range or minutes are not within 0-59 range...
            if (hours < 0 || hours > 12 || minutes < 0 || minutes > 59)
            {
                // ...then time must be set to X, hours to 0 and minutes to 0 in order to reflect invalid input;
                time = 'X', hours = 0, minutes = 0;
            }
            // if statement: if AM hours are equal to the value of 12...
            if (hours == 12)
            {
                // convert the hours to 0000 hours for military time;
                hours = 0;
            }

            break;
        // case for converting from PM time;
        case'P':
            // change time being used from PM to military;
            time = 'H';
            // if statement: if hours are not within 0-12 range or minutes are not within 0-59 range...
            if (hours < 0 || hours > 12 || minutes < 0 || minutes > 59)
            {
                // ...then time must be set to X, hours to 0 and minutes to 0 in order to reflect invalid input;
                time = 'X', hours = 0, minutes = 0;
            }
            // if statement: if PM hours are anything other than the value of 12...
            if (hours != 12)
            {
                // convert the hours to military time by adding 12 to the number of hours;
                hours = hours +12;
            }

            break;
        // if input for variable time is anything other than AM, PM or military time...
        default:
            // ...then set time to X, hours to 0 and minutes to 0 in order to reflect invalid input;
            time = 'X', hours = 0, minutes = 0;

            break;
        }
    // return no values because this is a void function;
    return;
}

void timeConvert (int& hours, int& minutes, int& offset)
{
    // This is a STUB, which needs to be fleshed out

    // subtract offset from input hours in order to arrive to make timezone conversion to UTC;
    hours = hours - offset;
    // after conversion to UTC has been made, set offset equal to zero;
    offset = 0;
    // create while loop to enable offset conversion sums which are greater than 23 hours to roll over;
    while (hours > 23)
    {
        // subtract 24 hours from the total number of hours for roll over to occur;
        hours = hours - 24;
    }
    // create while loop to enable offset conversion sums which are less than 0 hours to roll over;
    while (hours < 0)
    {
        // add 24 hours to the total number of hours to achieve the correct roll over value;
        hours = hours + 24;
    }
    // return no values because this is a void function;
    return;
}

/* Program execution: Not required
*/
