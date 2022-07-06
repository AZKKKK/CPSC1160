# include <iostream>

using namespace std;

bool isValidPassword(string s);

int main()
{
    cout << "Enter a string for password: ";
    string s;
    cin >> s;

    if(isValidPassword(s))
        cout << "Valid Password" << endl;
    else
        cout << "Invalid Password" << endl;

    return 0;
}

bool isValidPassword(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(!isalpha(char(s[i])) && 
        !isdigit(char(s[i])))
        return false;
    }

    if(s.length() < 8) return false;


    int count = 0;
    for(int i = 0; i < s.length(); i++)
        if(isdigit(char(s[i]))) count++;


    if (count < 2) return false;

    return true;
}