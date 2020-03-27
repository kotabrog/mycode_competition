#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, ans = "Yes";
  int n, half;

  cin >> s;
  n = s.length();
  half = (n - 1) / 2;
  for (int i = 0; i < half; i++)
  {
    if (s[i] != s[n - i - 1])
      ans = "No";
    if (i < half / 2)
    {
      if (s[i] != s[half - i - 1] || s[half + 1 + i] != s[n - i - 1])
        ans = "No";
    }
  }
  cout << ans << endl;
}