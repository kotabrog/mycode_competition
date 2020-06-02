#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;

  cin >> s >> t;
  for (int i = 0; i < s.size(); i++)
  {
    cout << s[i];
    if (s.size() == t.size() || i != s.size() - 1)
      cout << t[i];
  }
  cout << endl;
}