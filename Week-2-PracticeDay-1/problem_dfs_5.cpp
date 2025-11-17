#include <bits/stdc++.h>
using namespace std;

char getCapital(string str)
{
    if (str.empty())
        return '\0';

    char first = str[0];

    if (first >= 'A' && first <= 'Z')
        return first;
    return getCapital(str.substr(1));
}

int main()
{
    string str;
    cin >> str;
    str = getCapital(str);
    cout << str[0] << endl;
    return 0;
}