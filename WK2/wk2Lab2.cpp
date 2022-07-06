#include <iostream>

using namespace std;

void showBoundingRectangle(int* N, double* xCoords, double* yCoords);
double* center(double* Coords, int* const N);
double* length(double* Coords, int* const N);

int main()
{
    //declare variables
    int* N = new int;
    cout << "How many points will be entered ?" << endl;
    cin >> *N;
    double* xCoords = new double[*N];
    double* yCoords = new double[*N];

    //Ask for input
    for (int i = 0; i < *N; i++)
    {
        cout << "Enter x cordinates " << i << ": " << endl;
        cin >> *(xCoords+i);
        cout << "Enter y cordinates " << i << ": " << endl;
        cin >> *(yCoords+i);
    }

    //Output data
    showBoundingRectangle(N,xCoords,yCoords);

    //deallocate memory
    delete[] xCoords; 
    xCoords = nullptr;
    delete[] yCoords;
    yCoords = nullptr;
    delete N;
    N = nullptr;

    return 0;
}



void showBoundingRectangle(int* N, double* xCoords, double* yCoords)
{   
    //declare variables and output data
    double* centerX = new double; 
    centerX = center(xCoords,N);
    double* centerY = new double; 
    centerY = center(yCoords,N);
    cout << "Center x and y: " << *centerX 
    << "," << *centerY << endl;

    
    double* height = new double;
    height = length(yCoords, N);
    double* width = new double; 
    width = length(xCoords, N);
    cout << "Width: " << *width << endl
    << "Height: " << *height << endl;


    // deallocate memory
    delete centerX;
    centerX = nullptr;
    delete centerY;
    centerY = nullptr;
    delete height;
    height = nullptr;
    delete width;
    width = nullptr;

}

double* center(double* coords, int* const N)
{
    //declare variables
    double* center = new double;
    double* largest = new double; 
    *largest = *(coords);
    double* smallest =new double;
    *smallest = *(coords);

    //find largest and smallest
    for (int i = 0; i < *N; i ++)
    {
        if (*largest < *(coords + i))
            *largest = *(coords + i);
        else if (*smallest > *(coords + i))
            *smallest = *(coords + i);
    }

    //find center coordinate
    *center = (*largest + *smallest)/2;

    //deallocate memory
    delete largest;
    largest = nullptr;
    delete smallest;
    smallest = nullptr;

    return center;
}

double* length(double* coords, int* const N)
{
    //declare variables
    double* length = new double;
    double* largest = new double; 
    *largest = *(coords);
    double* smallest = new double;
    *smallest = *(coords);

    //find largest and smallest
    for (int i = 0; i < *N; i ++)
    {
        if (*largest < *(coords + i))
            *largest = *(coords + i);
        else if (*smallest > *(coords + i))
            *smallest = *(coords + i);
    }

    //find length
    *length = *largest - *smallest;

    //deallocate memory
    delete largest;
    largest = nullptr;
    delete smallest;
    smallest = nullptr;

    return  length;

}
