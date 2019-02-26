//Programming Homework #6
//Khadeja Khalid
//11 December 2016
//Windows 10 Code::Blocks 16.01
//This program will simulate a lottery game using an input of "official" lottery numbers and a user
//input of numbers. It will then list the numbers in ascending order and pick out the numbers matched

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

//Prototype Declarations
int  getLotUserGuess(int lotUserGuess[], int numElems, int numMax);
int  compareNumbers(int lotUserGuess[], int numbers[], int numElems);
int  searchList(int list[], int numElems, int value);
bool readInputFile (int numbers[], int &numElems, int &numMax, int arraySize);
bool openInputFile(ifstream &ifs);
void selectionSort(int array[], int size);
void lotterySort(int lotUserGuess[], int numbers[], int numElems);
void displayOutput(int lotUserGuess[], int numbers[], int numMatch, int numElems);
void idFunction(int hwNum);

const int ELEMENTS = 11; //Maximum amount of lottery numbers that could be read

int main()
{
    int lotOfficial  [ELEMENTS];  //The official lottery numbers
    int lotUserGuess [ELEMENTS];  //The user's lottery guesses
    int numElems;                 //The number of elements in a lottery
    int numMax;                   //Maximum value for each lottery
    int numMatch;                 //The number of matches in a lottery
    idFunction(6);

    if(!readInputFile(lotOfficial, numElems, numMax, ELEMENTS))
	{
		cout << "Unable to open the input file\n";
		return 1;
	}

    getLotUserGuess(lotUserGuess, numElems, numMax);
    numMatch = compareNumbers(lotUserGuess, lotOfficial, numElems);
    lotterySort(lotUserGuess, lotOfficial, numElems);
    displayOutput(lotUserGuess, lotOfficial, numMatch, numElems);

    return 0;
}

//*******************************************************************************************************
//Definition of readInputFile.
//This function will take in values from an input file, and mark them the winning lottery numbers.
//The numbers parameter is the array for the winning numbers.
//The numElems parameter is the total number in the lottery.
//The numMax is the maximum number of values for each lottery.
//The arraySize maximum number of lottery numbers can could be read in total.
//*******************************************************************************************************

bool readInputFile (int numbers[], int &numElems, int &numMax, int arraySize)
{
    ifstream inputFile;

    if (!openInputFile(inputFile))
        return false;

    inputFile >> numMax;
    inputFile >> numElems;

    if (numElems > arraySize)
        numElems = arraySize;

    int index;
    for (index=0; index < numElems; ++index )
    {
        inputFile >> numbers[index];
    }
    inputFile.close();
    return true;
}

//*******************************************************************************************************
//Definition of getLotUserGuess.
//This function will prompt the user to enter a number between a specific range (1 - numMax), and if the
//number is out of range it will reject and ask for a new input within range. It will take enough guesses
//until the amount in numElems is reached.
//*******************************************************************************************************

int getLotUserGuess(int lotUserGuess[], int numElems, int numMax)
{
    cout << "Enter " << numElems << " numbers between 1 and " << numMax << endl;

    int index = 0;
    for (int index = 0; index < numElems; index++)
    {
        cout << "Enter number #" << index + 1 << ": ";
        cin >> lotUserGuess[index];

        if (lotUserGuess[index] < 1 || lotUserGuess[index] > numMax)
        {
            cout << "Number out of range, much be be >=1 and " << numMax << "!" << endl;
            --index;
        }

        else if(searchList(lotUserGuess, index, lotUserGuess[index]) != -1)
        {
            cout << "You already chose that number!" << endl;
            --index;
        }
    }
}

//*******************************************************************************************************
//Definition of compareNumbers.
//This function will compare the values from the input file (the official lottery numbers) and the user's
//input, and test to see if any of the numbers match. Every time a match is found, the match value +1.
//The function returns the matched value.
//*******************************************************************************************************

int compareNumbers(int lotUserGuess[], int numbers[], int numElems)
{
	int match = 0; //The number of matches from the two arrays

	for(int token = 0; token < numElems; token++ )
	{
		if(searchList( lotUserGuess, numElems, numbers[token]) != -1 )
        {
            match++;
        }
	}
	return match;
}

//*******************************************************************************************************
//Definition of lotterySort.
//This function will take the values from the official lottery numbers and the user's guesses and put
//them in numerical order from least to greatest in separate rows.
//*******************************************************************************************************

void lotterySort(int lotUserGuess[], int numbers[], int numElems)
{
    selectionSort(lotUserGuess, numElems);
    selectionSort(numbers, numElems);
}

//*******************************************************************************************************
//Definition of displayOutput.
//This function will take the values from lotUserGuess and the official lottery numbers and print them.
//This function will also print how many numbers matched.
//*******************************************************************************************************

void displayOutput(int lotUserGuess[], int numbers[], int numMatch, int numElems)
{
    cout << endl;

    cout << "Lotto Game Numbers: ";
    for (int entry = 0; entry < numElems; entry++)
    {
        cout << setw(4) << numbers[entry];
    }
    cout << endl << endl;

    cout << "Your Numbers: ";
    for(int note = 0; note < numElems; note++)
    {
        cout << setw(4) << lotUserGuess[note];
    }
    cout << endl << endl;

    cout << "You matched " << numMatch << " number(s)" << endl;
}

//*******************************************************************************************************
//Definition for openInputFile.
//This function will prompt the user to input a file name and if a file with the same name is found,
// it will open. The function returns the open file. The function will come back if failed.
//*******************************************************************************************************

bool openInputFile(ifstream &ifs)
{
	string filename;

	cout << "Enter the input filename: ";
	getline(cin, filename);
	ifs.open(filename.c_str());
	return ifs.is_open();
}

//*******************************************************************************************************
//Definition for searchList.
//This function will take the values from an array and test to see if an input value is already in the
//array and return position. If not, it will return the number -1.
//*******************************************************************************************************

int searchList(int list[], int numElems, int value)
{
   int index = 0;       // Used as a subscript to search array
   int position = -1;   // To record position of search value
   bool found = false;  // Flag to indicate if the value was found

   while (index < numElems && !found)
   {
      if (list[index] == value)  // If the value is found
      {
         found = true;           // Set the flag
         position = index;       // Record the value's subscript
      }
      index++;                   // Go to the next element
   }
   return position;              // Return the position, or -1
}

//*******************************************************************************************************
//Definition of selectionSort.
//This function will take the values from an array and sort them in ascending numerical order.
//*******************************************************************************************************

void selectionSort(int array[], int size)
{
   int startScan, minIndex, minValue;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minValue = array[startScan];
      for(int index = startScan + 1; index < size; index++)
      {
         if (array[index] < minValue)
         {
            minValue = array[index];
            minIndex = index;
         }
      }
      array[minIndex] = array[startScan];
      array[startScan] = minValue;
   }
}

//*******************************************************************************************************
//Definition of idFunction.
//This function will take the homework number and use it to display a label stating the assignment number
//and the name of the programmer
//*******************************************************************************************************

void idFunction(int hwNum)
{
    cout << "CIS 22A Programming Homework # " << hwNum << endl;
    cout << "Khalid, Khadeja" << endl << endl;
}

/*
CIS 22A Programming Homework # 6
Khalid, Khadeja

Enter the input filename: HW6InputFile.txt
Enter 8 numbers between 1 and 56
Enter number #1: 56
Enter number #2: 5
Enter number #3: 57
Number out of range, much be be >=1 and 56!
Enter number #3: 0
Number out of range, much be be >=1 and 56!
Enter number #3: -1
Number out of range, much be be >=1 and 56!
Enter number #3: 5
You already chose that number!
Enter number #3: 1
Enter number #4: 55
Enter number #5: 41
Enter number #6: 2
Enter number #7: 20
Enter number #8: 3

Lotto Game Numbers:    5  10  17  20  32  39  41  55

Your Numbers:    1   2   3   5  20  41  55  56

You matched 4 number(s)

Process returned 0 (0x0)   execution time : 44.024 s
Press any key to continue.
*/
