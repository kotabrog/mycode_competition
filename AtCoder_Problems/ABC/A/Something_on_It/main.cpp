#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int n = 0;

  cin >> s;
  for (int i = 0; i < 3; i++)
  {
    if (s[i] == 'o')
      n++;
  }
  cout << 700 + 100 * n << endl;
}