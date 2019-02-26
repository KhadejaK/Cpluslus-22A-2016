//Programming Homework #5
//Khadeja Khalid
//29 November 2016
//Windows 10 Code::Blocks 16.01
//This program will write to an output file a table of wind chill
//temperatures with the low and high input temperatures

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

//Constants
const int LOW_WIND_SPEED  =   5;
const int HIGH_WIND_SPEED =  40;
const int HIGH_TEMP_MAX   =  50;
const int LOW_TEMP_MAX    =  45;
const int LOW_TEMP_MIN    = -50;

//Function prototype declarations
void   idFunction(int hwNum);
int    tempInput (int& lowTemp, int& highTemp);
bool   openOutputFile(ofstream &ofs);
double windChillCalc (double airTemp, double windSpeed);
void   windChillFunction (int lowTemp, int highTemp,
                          const int LOW_WIND_SPEED,
                          const int HIGH_WIND_SPEED);

int main()
{
    //Variables
    int lowTemp;        //Lowest air temperature (input)
    int highTemp;       //Highest air temperature(input)
    idFunction(5);

    //Call function to get user input
    tempInput(lowTemp, highTemp);

    //Call function to write to output file
    windChillFunction(lowTemp, highTemp,
                      LOW_WIND_SPEED, HIGH_WIND_SPEED);

    return 0;
}
//***********************************************************************
//This function gets the lowest air temperature and the highest air     *
//temperature from the user. If it is not within range, the program     *
//will reject value and ask for a correct input.                        *
//***********************************************************************
int tempInput (int& lowTemp, int& highTemp)
{
    cout << "Enter lowest air temperature in degrees F: ";
    cin >> lowTemp;
    while (!(lowTemp >= LOW_TEMP_MIN && lowTemp <= LOW_TEMP_MAX))
    {
        cout << "You must input a number >= " << LOW_TEMP_MIN
            << " and <= " << LOW_TEMP_MAX << endl;
        cout << "Enter lowest air temperature in degrees F: ";
        cin >> lowTemp;
    }
    cout << endl;

    cout << "Enter highest air temperature in degrees F: ";
    cin >> highTemp;
    while (!(highTemp >= (lowTemp + LOW_WIND_SPEED)
                && highTemp <= HIGH_TEMP_MAX))
    {
        cout << "You must input a number >= " << lowTemp + LOW_WIND_SPEED
            << " and <= " << HIGH_TEMP_MAX << endl;
        cout << "Enter highest air temperature in degrees F: ";
        cin >> highTemp;
    }
    cout << endl;

    return lowTemp, highTemp;
}
//***********************************************************************
//This function will open the output file from the user's input, and    *
//display a table calculating the chill in the wind from the air        *
//temperature and the wind speed.                                       *
//***********************************************************************
void windChillFunction(int lowTemp, int highTemp,
                       const int LOW_WIND_SPEED,
                       const int HIGH_WIND_SPEED)
{
    ofstream outputFile;

    bool status = openOutputFile(outputFile);
    if (!status)
    {
        cout << "Error. Cannot open file." << endl;
        return ;
    }

    outputFile << "Wind Chill Temperatures (Degrees F)\n";
    outputFile << setw(50) << "Wind Speed (MPH)\n";

    outputFile << "Air Temp";

    int windSpeed; //Display Wind Speed, the speed of the wind
    for(windSpeed = LOW_WIND_SPEED; windSpeed <= HIGH_WIND_SPEED;
            windSpeed += LOW_WIND_SPEED)
    {
        outputFile << setw(8) << windSpeed;
    }
    outputFile << endl;

    int airTemp; //Display Air Temp, the air temperature
    for(airTemp = lowTemp; airTemp <= highTemp; airTemp++)
    {
        outputFile << right << setw (6) << airTemp << "  ";
        for (windSpeed = LOW_WIND_SPEED; windSpeed <= HIGH_WIND_SPEED;
                    windSpeed += LOW_WIND_SPEED)
        {
            outputFile << setprecision(1) << fixed;
            double windChill; //The value of the wind chill
            windChill = windChillCalc (airTemp, windSpeed);
            outputFile << right << setw(8) << windChill;
        }
        outputFile << endl;
    }
    outputFile.close();
}
//***********************************************************************
//Get the name of the output file from user                             *
//***********************************************************************
bool openOutputFile(ofstream &ofs)
{
   string filename;

   cout << "\nEnter the output filename: ";
   cin.ignore(80, '\n');
   getline(cin, filename);
   ofs.open(filename.c_str());
   return ofs.is_open();
}

//***********************************************************************
//This function calculates the Wind Chill using the air temperature     *
//and wind speed                                                        *
//***********************************************************************
double windChillCalc (double airTemp, double windSpeed)
{
    double windChill;
    windChill = 35.74 + (0.6215*airTemp) - (35.75 * (pow(windSpeed, 0.16)))
                + (0.4275 * airTemp * (pow(windSpeed, 0.16)));
    return windChill;
}

void idFunction(int hwNum)
{
    cout << "CIS 22A Programming Homework # " << hwNum << endl;
    cout << "Khalid, Khadeja" << endl << endl;
}

/*
*************************************************************************
CIS 22A Programming Homework # 5
Khalid, Khadeja

Enter lowest air temperature in degrees F: -51
You must input a number >= -50 and <= 45
Enter lowest air temperature in degrees F: 46
You must input a number >= -50 and <= 45
Enter lowest air temperature in degrees F: -50

Enter highest air temperature in degrees F: -50
You must input a number >= -45 and <= 50
Enter highest air temperature in degrees F: 51
You must input a number >= -45 and <= 50
Enter highest air temperature in degrees F: -45


Enter the output filename: WindChillTable2.txt

Process returned 0 (0x0)   execution time : 30.427 s
Press any key to continue.
*************************************************************************
*/
