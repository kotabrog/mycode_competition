#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;
  bool flag;

  cin >> s >> t;
  for (int i = 0; i < s.size(); i++)
  {
    flag = true;
    for (int j = i; j < s.size(); j++)
    {
      if (s[j - i] != t[j])
      {
        flag = false;
        break;
      }
    }
    if (!flag)
      continue;
    for (int j = 0; j < i; j++)
    {
      if (s[s.size() - i + j] != t[j])
      {
        flag = false;
        break;
      }
    }
    if (flag)
      break;
  }
  cout << (flag ? "Yes" : "No") << endl;
}