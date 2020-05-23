#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  bool flag=true;

  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'o' || s[i] == 'k' || s[i] == 'u')
      continue;
    else if (s[i] == 'c')
    {
      i++;
      if (s.size() <= i || s[i] != 'h')
      {
        flag = false;
        break;
      }
    }
    else
    {
      flag = false;
      break;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
}
