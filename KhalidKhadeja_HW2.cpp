//Program Homework 1B
//Khadeja Khalid
//18 October 2016
//Windows 10 Code::Blocks 16.01
//This program will calculate the distance between "home" and store

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <tgmath.h>
using namespace std;

const double RADIAN = 57.2957795; //Conversion for radians
const int EARTH_RADIUS = 6371;    //Radius of the Earth
const double KM_PER_MI = 5.0/8.0; //5 kilometers for every 8 miles

void idFunction();
int main()
{
    //Variable declarations
    string storeAddress;          //Input for the store's address
    double lat1,                  //Radian calculation for latitude 1
           lat1x,                 //Input latitude 1
           long1,                 //Radian calculation for longitude 1
           long1x,                //Input longitude 1
           lat2,                  //Radian calculation for latitude 2
           lat2x,                 //Input latitude 2
           long2,                 //Radian calculation for longitude 2
           long2x,                //Input longitude 2
           deltaLatitude,         //Difference between latitude 1 and latitude 2
           deltaLongitude,        //Difference between longitude 1 and longitude 2
           part1,                 //Haversine formula part 1
           part2,                 //Haversine formula part 2
           kmDistance,            //Distance in kilometers
           milesDistance;         //Distance in miles
    idFunction();

    //Get input from user
    cout << "Enter store address: ";
    getline (cin, storeAddress);
    cout << "Enter latitude and longitude of the store (sep. by a space): ";
    cin >> lat1x >> long1x;
    cout << "Enter latitude and longitude of home (sep. by a space): ";
    cin >> lat2x >> long2x;

    //Convert Latitude and Longitude values to radians
    lat1  = lat1x  / RADIAN;
    long1 = long1x / RADIAN;
    lat2  = lat2x  / RADIAN;
    long2 = long2x / RADIAN;

    //Calculate required calculations
    deltaLatitude  = lat2  - lat1;
    deltaLongitude = long2 - long1;
    part1 = pow(sin(deltaLatitude/2), 2.0) + cos(lat1) * cos(lat2) * pow(sin(deltaLongitude/2), 2.0);
    part2 = (2 * atan2(sqrt(part1), sqrt(1-part1)));
    kmDistance    = EARTH_RADIUS * part2;
    milesDistance = kmDistance * KM_PER_MI;

    //Display calculations
    cout << "=======================================" << endl;
    cout << "Store address:" << endl;
    cout << storeAddress << endl;
    cout << left << setw(27) << "Earth's Radius (in km):"
        << right << setw(12) << EARTH_RADIUS << endl;
    cout << setprecision(4) << fixed << showpoint;
    cout << left << setw(27) << "Latitude difference:"
        << right << setw(12) << deltaLatitude << endl;
    cout << left << setw(27) << "Longitude difference:"
        << right << setw(12) << deltaLongitude << endl;
    cout << left << setw(27) << "Part 1 of calculation:"
        << right << setw(12) << part1 << endl;
    cout << left << setw(27) << "Part 2 of calculation:"
        << right << setw(12) << part2 << endl;
    cout << left << setw(27) << "Distance to the store (km):"
        << right << setw(12) << kmDistance << endl;
    cout << left << setw(27) << "Distance in miles:"
        << right << setw(12) << milesDistance << endl;
    cout << "=======================================" << endl;
    return 0;
}

void idFunction()
{
cout << "CIS 22A Programming Homework #2" << endl;
cout << "Khalid, Khadeja"<< endl << endl;
}

/*
CIS 22A Programming Homework #2
Khalid, Khadeja

Enter store address: 450 Serra Mall, Stanford
Enter latitude and longitude of the store (sep. by a space): 37.4300 122.1700
Enter latitude and longitude of home (sep. by a space): 37.3192 122.0453
=======================================
Store address:
450 Serra Mall, Stanford
Earth's Radius (in km):            6371
Latitude difference:            -0.0019
Longitude difference:           -0.0022
Part 1 of calculation:           0.0000
Part 2 of calculation:           0.0026
Distance to the store (km):     16.5291
Distance in miles:              10.3307
=======================================

Process returned 0 (0x0)   execution time : 43.103 s
Press any key to continue.
*/
