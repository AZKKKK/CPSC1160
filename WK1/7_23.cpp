#include <iostream>

using namespace std;

int main()
{
    const int numOfLocker = 100;
    bool* lockers = new bool[numOfLocker];

    for (int i = 0; i < numOfLocker; i ++)
    {
        lockers[i] = false;
    }

    for (int i = 1; i < numOfLocker; i ++)
    {
        for (int j = i - 1; j < numOfLocker; j += i)
            lockers[j] = !lockers[j];
    }

    for (int i = 0; i < numOfLocker; i++)
    {
        if (lockers[i])
            cout << "Locker " << i + 1 << " is open" << endl;
    }

    delete[] lockers;
    lockers = nullptr;
    return 0;
}