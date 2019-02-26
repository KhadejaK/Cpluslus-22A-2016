//Lottery Ticket Calculator
//Khadeja Khalid
//11 October 2016
//Code::Blocks 16.01
//This program will calculate how much is spent on lottery tickets
//yearly, monthly, and daily.

#include <iostream>
#include <iomanip>
using namespace std;

void idFunction();
int main ()
{
    //Variables
    double lotteryTixNum;     //Input # of tickets purchased weakly
    double tixPrice;          //Input cost of lottery tickets
    double lotteryTixYearly;  //Calculate how much spent in a year
    double lotteryTixMonthly; //Calculate how much spent in a month
    double lotteryTixDaily;   //Calculate how much spent in a day
    idFunction();

    //Input
    cout << "How many lottery tickets do you buy weekly? ";
    cin >> lotteryTixNum;
    cout << "How much does each lottery ticket cost? ";
    cin >> tixPrice;
    cout << endl;

    //Calculations
    lotteryTixYearly = lotteryTixNum * tixPrice * 52;
    lotteryTixMonthly = lotteryTixYearly / 12;
    lotteryTixDaily = lotteryTixYearly / 365;

    //Display
    cout << setprecision (2) << fixed;
    cout << "Amount spent on lottery tickets each year: $" << lotteryTixYearly << endl;
    cout << "Amount spent on lottery tickets each month: $" << lotteryTixMonthly << endl;
    cout << "Amount spend on lottery tickets per day: $" << lotteryTixDaily << endl;
    return 0;
}

void idFunction()
{
cout << "CIS 22A Programming Homework # 1B" << endl;
cout << "Khalid, Khadeja"<< endl<< endl;
}
