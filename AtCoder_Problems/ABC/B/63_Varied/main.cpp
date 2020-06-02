#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  vector<bool> a(26, false);
  bool flag = false;

  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    if (a[s[i] - 'a'])
      flag = true;
    else
      a[s[i] - 'a'] = true;
  }
  cout << (flag ? "no" : "yes") << endl;
}