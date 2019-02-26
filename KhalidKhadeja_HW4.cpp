//Programming Homework #4
//Khadeja Khalid
//10 November 2016
//Windows 10 Code::Blocks 16.01
//This program will convert US Dollars to a choice of foreign currencies

#include <iostream>
#include <iomanip>
using namespace std;

const double BRAZIL_DOLLAR = 3.11;    //Conversion for Brazilian Reals per US Dollar
const double EURO_DOLLAR   = 0.92;    //Conversion for Euros per US Dollar
const double HK_DOLLAR     = 7.76;    //Conversion for Hong Kong Dollar per US Dollar
const double JAPAN_DOLLAR  = 104.28;  //Conversion for Japanese Yen per US Dollar
const double INDIAN_DOLLAR = 66.79;   //Conversion for Indian Rupees per US Dollar

const int BRAZIL_CHOICE = 1; //Brazilian Real Choice
const int EURO_CHOICE   = 2; //Euro Choice
const int HK_CHOICE     = 3; //Hong Kong Dollar Choice
const int JAPAN_CHOICE  = 4; //Japanese Yen Choice
const int INDIAN_CHOICE = 5; //Indian Rupee Choice

void idFunction(int hwNum);
int getCurrencyChoice();     //Get choice input from user
double getConvertAmount();   //Get value amount to convert
double calcConvertValue(int choice, double convertAmount);
                             //Calculate converted value
int main()
{
    //Variables
    int choice;              //Get choice from user(input)
    double convertAmount;    //Get value amount to convert(input)
    double convertValue;     //Calculate the converted value
    bool doConversion = true;//Automatically proceeds with the function
    char userInput;          //Get input if user wants to continue
    idFunction(4);

    while (doConversion)
    {
    //Call functions for input
    choice = getCurrencyChoice();
    convertAmount = getConvertAmount();
    convertValue = calcConvertValue(choice, convertAmount);

    //Display conversion value
    cout << setprecision(2) << fixed;
    cout << "\nThe converted value = " << convertValue << endl << endl;

    cout << "Do you want to convert another? (y for yes): ";
    cin >> userInput;
    cout << endl;
        if (userInput != 'y' && userInput != 'Y')
        {
            doConversion = false;
        }
      }

    return 0;
}

int getCurrencyChoice()
{
    int choice; //Get choice from user(Input)

    //Choice options to choose from
    cout << "Currency Options (Output)\n";
    cout << "1 - Brazilian Real\n";
    cout << "2 - Euro\n";
    cout << "3 - Hong Kong Dollar\n";
    cout << "4 - Japanese Yen\n";
    cout << "5 - Indian Rupee\n";
    cout << "Enter the number of the currency: ";
    cin >> choice;

    //If the entered value is not within range
    if (choice < BRAZIL_CHOICE || choice > INDIAN_CHOICE)
    {
        choice = EURO_CHOICE;
    }

    return choice;
}

double getConvertAmount()
{
    double convertAmount;

    //Get amount to convert
    cout << "Enter the US Dollars value to convert: ";
    cin >> convertAmount;

    if (convertAmount <= 0)
    {
        convertAmount = 1;
    }

    return convertAmount;
}

double calcConvertValue(int choice, double convertAmount)
{
    double convertValue;

    //Respond to user's selection
    switch(choice)
    {
        case BRAZIL_CHOICE:
            convertValue = BRAZIL_DOLLAR * convertAmount;
            break;
        case EURO_CHOICE:
            convertValue = EURO_DOLLAR   * convertAmount;
            break;
        case HK_CHOICE:
            convertValue = HK_DOLLAR     * convertAmount;
            break;
        case JAPAN_CHOICE:
            convertValue = JAPAN_DOLLAR  * convertAmount;
            break;
        case INDIAN_CHOICE:
            convertValue = INDIAN_DOLLAR * convertAmount;
            break;
    }

    return convertValue;
}

void idFunction(int hwNum)
{
    cout << "CIS 22A Programming Homework # " << hwNum << endl;
    cout << "Khalid, Khadeja" << endl << endl;
}

/*
CIS 22A Programming Homework # 4
Khalid, Khadeja

Currency Options (Output)
1 - Brazilian Real
2 - Euro
3 - Hong Kong Dollar
4 - Japanese Yen
5 - Indian Rupee
Enter the number of the currency: 2
Enter the US Dollars value to convert: 100

The converted value = 92.00

Do you want to convert another? (y for yes): y

Currency Options (Output)
1 - Brazilian Real
2 - Euro
3 - Hong Kong Dollar
4 - Japanese Yen
5 - Indian Rupee
Enter the number of the currency: 5
Enter the US Dollars value to convert: 2000.0

The converted value = 133580.00

Do you want to convert another? (y for yes): Y

Currency Options (Output)
1 - Brazilian Real
2 - Euro
3 - Hong Kong Dollar
4 - Japanese Yen
5 - Indian Rupee
Enter the number of the currency: 1
Enter the US Dollars value to convert: 10.0

The converted value = 31.10

Do you want to convert another? (y for yes): y

Currency Options (Output)
1 - Brazilian Real
2 - Euro
3 - Hong Kong Dollar
4 - Japanese Yen
5 - Indian Rupee
Enter the number of the currency: 0
Enter the US Dollars value to convert: 0

The converted value = 0.92

Do you want to convert another? (y for yes): y

Currency Options (Output)
1 - Brazilian Real
2 - Euro
3 - Hong Kong Dollar
4 - Japanese Yen
5 - Indian Rupee
Enter the number of the currency: 3
Enter the US Dollars value to convert: -1

The converted value = 7.76

Do you want to convert another? (y for yes): Y

Currency Options (Output)
1 - Brazilian Real
2 - Euro
3 - Hong Kong Dollar
4 - Japanese Yen
5 - Indian Rupee
Enter the number of the currency: 4
Enter the US Dollars value to convert: 20.0

The converted value = 2085.60

Do you want to convert another? (y for yes): n


Process returned 0 (0x0)   execution time : 46.789 s
Press any key to continue.
*/
