#include <iostream>
#include <cmath>

using namespace std;

float F(int n)
{
    float num = (float) n;
    // base case
    if(n == 1)
    {
        return 1/(num*(num+2));
    }

    float function = 1/(num*(num+2));

    //recursion
    return function + F(num-1);
}

int main()
{
    cout << "Enter an integer to calculate" << endl;
    int n;
    cin >> n;
    cout << round(F(n)*10000)/10000;
}
