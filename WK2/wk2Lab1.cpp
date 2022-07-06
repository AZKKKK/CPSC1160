#include <iostream>

using namespace std;

int* LocateLargest(double** arr, int* numOfRows, int* numOfCols);

int main()
{
    //Display instruction and declare variables
    cout << "Enter the number of rows and columns of the array: ";
    int* numOfRows = new int;
    int* numOfCols = new int;
    cin >> *numOfRows >> *numOfCols;
    
    double** arr = new double* [*numOfRows];
    for (int i = 0; i < *numOfRows; i ++)
    {
        *(arr+i) = new double[*numOfCols];
    }

    //ask for input to fill array
    cout << "Enter the the array: " << endl;
    for (int i = 0; i < *numOfRows; i ++)
    {
        for (int j = 0; j < *numOfCols; j ++)
        {
            cin >> *(*(arr+i)+j);
        }
        
    }

    //find location
    int* location = LocateLargest(arr,numOfRows, numOfCols);

    cout << "The location of the largest element is at (" << *location
    << "," << *(location+1) << ")" << endl;

    //free memory
    for (int i = 0; i < *numOfRows; i ++)
    {
        delete arr[i];
    }

    delete[] arr;
    delete[] location;
    delete numOfRows;
    delete numOfCols;

    arr = nullptr;
    location = nullptr;
    numOfRows = nullptr;
    numOfCols = nullptr;

    return 0;
}

int* LocateLargest(double** arr, int* numOfRows, int* numOfCols)
{
    //declare variables
    int* location = new int[2];
    *location = 0;
    *(location+1) = 0;

    double* largest = new double;
    *largest = *(*arr);

    //locate target
    for (int i = 0; i < *numOfRows; i ++)
    {
        for (int j = 0; j < *numOfCols; j ++)
        {
            if(*largest < *(*(arr+i)+j))
            {
                *largest = *(*(arr+i)+j);
                *location = i;
                *(location+1) = j;
            }
        }
    }

    //free allocated memory
    delete largest;
    largest = nullptr;
    
    return location;
}