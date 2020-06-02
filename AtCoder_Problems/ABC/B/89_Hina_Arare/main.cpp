#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, flag_count = 0;
  char c;
  string s = "PWGY";
  vector<bool> flag(4, false);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> c;
    for (int j = 0; j < 4; j++)
    {
      if (c == s[j])
        flag[j] = true;
    }
  }
  for (int i = 0; i < 4; i++)
  {
    if (flag[i])
      flag_count++;
  }
  cout << (flag_count == 3 ? "Three" : "Four") << endl;
}