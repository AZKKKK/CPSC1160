#include <iostream>
#include <cmath>

using namespace std;

double deviation(double x[],const int size);
double deviation(int x[],const int size);
double mean(double x[],const int size);
double mean(int x[],const int size);
inline void printArray(double x[],const int size);

int main()
{
    const int size = 10;
    double* numbers = new double[size];

    cout << "Enter ten numbers: ";

    for(int i = 0; i < size; i++)
    {
        double number;
        cin >> number;
        numbers[i] = number;
    }

    cout << "The mean is: " << mean(numbers,size) << endl;
    cout << "The standard deviation is: " << deviation(numbers,size) << endl;

    delete[] numbers;
    numbers = nullptr;
    return 0;
}

double deviation(double x[],const int size)
{
    double arrayMean = mean(x,size);
    double squareSum = 0;

    for(int i = 0; i < size; i++)
        squareSum += pow(x[i] - arrayMean, 2);
    
    return sqrt(squareSum / (size - 1));
}

double deviation(int x[],const int size)
{
    double arrayMean = mean(x,size);
    double squareSum = 0;

    for(int i = 0; i < size; i++)
        squareSum += pow(x[i] - arrayMean, 2);
    
    return sqrt(squareSum / (size - 1));

}

double mean(double x[],const int size)
{
    double sum = 0;

    for(int i = 0; i < size; i++)
        sum += x[i];

    return sum / size;
       
}

double mean(int x[],const int size)
{
    double sum = 0;

    for(int i = 0; i < size; i++)
        sum += x[i];

    return sum / size;
       
}

inline void printArray(double x[],const int size)
{
    for(int i = 0; i < size; i ++)
        cout << x[i] << " ";
    
    cout << "" << endl;
}
