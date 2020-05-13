#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  for (int i = 0; i < 3; i++)
  {
    if (s[i] == '1')
      cout << '9';
    else if (s[i] == '9')
      cout << '1';
    else
      cout << s[i];
  }
  cout << endl;
}