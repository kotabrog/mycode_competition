#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  bool C_flag = false, flag = true;

  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    if (i == 0)
    {
      if (s[i] != 'A')
        flag = false;
    }
    else if (s[i] == 'C')
    {
      if (!C_flag && 1 < i && i < s.size() - 1)
        C_flag = true;
      else
        flag = false;
    }
    else if (s[i] < 'a' || 'z' < s[i])
      flag = false;
    if (!flag)
      break;
  }
  cout << (flag && C_flag ? "AC" : "WA") << endl;
}