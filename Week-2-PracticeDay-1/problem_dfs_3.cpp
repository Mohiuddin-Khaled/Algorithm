#include <bits/stdc++.h>
using namespace std;

string Reverse(string str) 
{ 
    // base case
    if(str.size() == 0)
        return str;

    return Reverse(str.substr(1)) + str[0];
}

int main()
{
    string str;
    cin >> str;
    cout << Reverse(str) << endl;
}