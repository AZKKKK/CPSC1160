#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int COUNT = 10;
    double sum = 0.0;
    double squareSum = 0.0;

    for (int i = 0; i < COUNT; i++)
    {
        cout << "Enter a number: ";
        double number = 0.0;
        cin >> number;

        sum += number;

        squareSum += pow(number, 2);
    }

    double mean = sum / COUNT;

    double deviation = 
    pow((squareSum - sum * mean) / (COUNT - 1), 0.5);

    cout << "The mean is " << mean << endl;
    cout << "The standard deviation is " << deviation << endl;

    return 0;
}