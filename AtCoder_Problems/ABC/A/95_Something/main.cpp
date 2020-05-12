#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int s_count = 0;
  cin >> s;
  for (int i = 0; i < 3; i++)
  {
    if (s[i] == 'o')
      s_count++;
  }
  cout << 700 + s_count * 100 << endl;
}