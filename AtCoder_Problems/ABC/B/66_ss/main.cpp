#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  bool flag;
  int ans = 0;

  cin >> s;
  for (int i = 1; i < s.size(); i++)
  {
    if ((s.size() - i) % 2 == 1)
      continue;
    flag = true;
    for (int j = 0; j < (s.size() - i) / 2; j++)
    {
      if (s[j] != s[(s.size() - i) / 2 + j])
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      ans = s.size() - i;
      break;
    }
  }
  cout << ans << endl;
}