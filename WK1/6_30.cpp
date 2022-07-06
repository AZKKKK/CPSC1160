#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double random();
int getDice();


int main()
{ 
    srand((unsigned)time(NULL));

    int dice = getDice();

    if (dice == 7 || dice == 11)
    {
        cout << "You win" << endl;
        exit(1);
    }
    else if (dice == 2 || dice == 3 || dice == 12)
    {
        cout << "You lose" << endl;
        exit(2);
    }

    int point = dice;
    cout << "Point is " << point << endl;

    do
    {
        dice = getDice();
    } while (dice != 7 && dice != point);

    if (dice == 7)
        cout << "You lose" << endl;
    else
        cout << "You win" << endl;

    
    return 0;
}

int getDice() 
{
    int i1 = 1 + (random() * 6.0);
    int i2 = 1 + (random() * 6.0);

    cout << "You rolled " << i1 << " + " << i2 << " = " << (i1 + i2) << endl;
    return i1 + i2;
}

double random() 
{
    return (rand() % 10)/10.0;
}

