#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int a, k = 0;
  cin >> s;
  for (int i = 0; i < 3; i++)
  {
    if (i % 2 == 0)
      a = 5;
    else
      a = 7;
    for (int j = 0; j < a; j++)
    {
      cout << s[k];
      k++;
    }
    if (i != 2)
    {
      cout << ' ';
      k++;
    }
  }
  cout << '\n';
}
