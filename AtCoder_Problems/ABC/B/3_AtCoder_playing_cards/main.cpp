#include <bits/stdc++.h>
using namespace std;

bool ft_check(char c)
{
  bool flag = false;
  string u = "atcoder";
  for (int i = 0; i < 7; i++)
  {
    if (c == u[i])
    {
      flag = true;
      break;
    }
  }
  return (flag);
}

int main()
{
  string s, t;
  bool flag = true;

  cin >> s >> t;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '@' && t[i] != '@')
    {
      if (!ft_check(t[i]))
        flag = false;
    }
    else if (t[i] == '@' && s[i] != '@')
    {
      if (!ft_check(s[i]))
        flag = false;
    }
    else if (t[i] != s[i])
      flag = false;
    if (!flag)
      break;
  }
  if (flag)
    cout << "You can win" << endl;
  else
    cout << "You will lose" << endl;
}
