#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a = 0;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < 3; i++)
  {
    if (s[i] == t[i])
      a++;
  }
  cout << a << endl;
}