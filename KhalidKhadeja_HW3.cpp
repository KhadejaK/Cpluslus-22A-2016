//Homework #3
//Khadeja Khalid
//27 October 2016
//Windows 10 Code::Blocks 16.01
//This program will calculate and display the tax liability
//and tax owed (or tax refund) of a person

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PERCENT1 = .15;    //If the taxable income is 0 < income <= 36900
const double PERCENT2 = .28;    //If the taxable income is 36900 < income <= 186350
const double PERCENT3 = .35;    //If the taxable income is 186350 < income
const double BRACKET1 = 36900;  //Limit for first taxable income liability
const double BRACKET2 = 186350; //Limit for second taxable income liability

void idFunction(int hwNum);
int main()
{
    //Variables
    double taxIncome;          //The total taxable income earned by user (input)
    double taxWithheld;        //The tax withheld (or paid) by user (input)
    double taxLiability;       //The liability of the lax owed
    double taxOwed;            //The total tax owed after subtracting from liability
    double taxRefund;          //If the tax owed is less than 0
    idFunction(3);

    //Ask the income and withheld from user
    cout << "Enter taxable income: ";
    cin >> taxIncome;
    cout << "Enter tax withheld: ";
    cin >> taxWithheld;
    cout << endl;

    //Calculate Tax Liability
    if(taxIncome <= 0)
    {
        taxLiability = 0;
    }
    else
    {
        if(taxIncome <= BRACKET1)
        {
            taxLiability = PERCENT1 * taxIncome;
        }
        else
        {
             if(taxIncome <= BRACKET2)
             {
                taxLiability = PERCENT1 * BRACKET1 +
                            PERCENT2 * (taxIncome - BRACKET1);
             }
            else
            {
                taxLiability = PERCENT1 * BRACKET1 +
                            PERCENT2 * (BRACKET2 - BRACKET1) +
                            PERCENT3 * (taxIncome - BRACKET2);
            }
        }
    }

    //Calculate Tax Owed or Tax Refund
    taxOwed = taxLiability - taxWithheld;

    //Display the tax values
    cout << setprecision(2) << fixed << showpoint;
    cout << left << setw(15) << "Tax Income: "
        << right << setw(16) << taxIncome << endl;
    cout << left << setw(15) << "Tax Withheld: "
        << right << setw(16) << taxWithheld << endl;
    cout << left << setw(15) << "Tax Liability: "
        << right << setw(16) << taxLiability << endl;

    //Determine whether the tax is owed or refunded
    if(taxOwed >= 0)
    {
        cout << left << setw(15) << "Tax Owed: "
            << right << setw(16) << taxOwed << endl;
    }
    else
    {
        //Making the tax refund into a positive value
        taxRefund = taxOwed * -1;
        cout << left << setw(15) << "Tax Refund: "
            << right << setw(16) << taxRefund << endl;
    }

    return 0;
}

void idFunction(int hwNum)
{
    cout << "CIS 22A Programming Homework # " << hwNum << endl;
    cout << "Khalid, Khadeja" << endl << endl;
}

/*

TEST RUN #1
*******************************************************
CIS 22A Programming Homework # 3
Khalid, Khadeja

Enter taxable income: 55555.0
Enter tax withheld: 10000.0

Tax Income:            55555.00
Tax Withheld:          10000.00
Tax Liability:         10758.40
Tax Owed:                758.40

Process returned 0 (0x0)   execution time : 21.052 s
Press any key to continue.


TEST RUN #2
*******************************************************
CIS 22A Programming Homework # 3
Khalid, Khadeja

Enter taxable income: 33333.0
Enter tax withheld: 6543.0

Tax Income:            33333.00
Tax Withheld:           6543.00
Tax Liability:          4999.95
Tax Refund:             1543.05

Process returned 0 (0x0)   execution time : 12.779 s
Press any key to continue.


TEST RUN #3
*******************************************************
CIS 22A Programming Homework # 3
Khalid, Khadeja

Enter taxable income: 321321.0
Enter tax withheld: 98765.0

Tax Income:           321321.00
Tax Withheld:          98765.00
Tax Liability:         94620.85
Tax Refund:             4144.15

Process returned 0 (0x0)   execution time : 16.446 s
Press any key to continue.

*/
