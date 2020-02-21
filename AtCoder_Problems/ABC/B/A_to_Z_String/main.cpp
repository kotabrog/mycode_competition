#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int n;
  int ai;

  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'A')
    {
      ai = i;
      break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (s[n - i - 1] == 'Z')
    {
      cout << n - i - ai << endl;
      break;
    }
  }
}