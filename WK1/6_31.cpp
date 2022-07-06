#include <iostream>
#include <cstdlib>

using namespace std;

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);
int getDigit(int number);

int main()
{
    cout << "Enter a credit card number as a long integer: ";
    long long number;
    cin >> number;

    if(isValid(number))
        cout << number << " is valid." << endl;
    else   
        cout << number << " is invalid." << endl;

    return 0;

    
}

bool isValid(long long number)
{
    return (getSize(number) >= 13) && (getSize(number) <= 16) && 
        (prefixMatched(number, 4) || prefixMatched(number, 5) ||
        prefixMatched(number, 6) || prefixMatched(number, 37)) && 
        (sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0;
}

int sumOfDoubleEvenPlace(long long number)
{
    int result = 0;

    number = number / 10;
    while(number != 0)
    {
        result += getDigit((int)((number % 10) * 2));
        number = number / 100;
    }

    return result;
}

int getDigit(int number)
{
    return number % 10 + (number / 10);
}

int sumOfOddPlace(long long number)
{
    int result = 0;

    while(number != 0)
    {
        result += (int)(number % 10);
        number = number / 100;
    }

    return result;
}

bool prefixMatched(long long number, int d)
{
    return getPrefix(number, getSize(d)) == d;
}

int getSize(long long d)
{
    int numberOfDigits = 0;

    while (d != 0)
    {
        numberOfDigits ++;
        d = d / 10;
    }

    return numberOfDigits;
}

long long getPrefix(long long number, int k)
{
    long long result = number;

    for(int i = 0; i < getSize(number) - k; i ++)
        result /= 10;

    return result;
}