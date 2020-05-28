#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  vector<bool> c(26, true);
  bool flag = true;

  cin >> s;
  for (int i = 0; i < s.size(); i++)
    c[s[i] - 'a'] = !c[s[i] - 'a'];
  for (int i = 0; i < 26; i++)
  {
    if (!c[i])
    {
      flag = false;
      break;
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}