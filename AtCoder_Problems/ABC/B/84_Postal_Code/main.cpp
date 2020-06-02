#include <bits/stdc++.h>
using namespace std;

int main()
{
  bool flag = true;
  int a, b;
  string s;

  cin >> a >> b >> s;
  for (int i = 0; i < a + b + 1; i++)
  {
    if (i == a)
    {
      if (s[i] != '-')
      {
        flag = false;
        break;
      }
    }
    else
    {
      if (s[i] == '-')
      {
        flag = false;
        break;
      }
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}