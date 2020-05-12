#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  vector<bool> a(3, false);
  string ans = "Yes";
  cin >> s;
  for (int i = 0; i < 3; i++)
    a[s[i] - 'a'] = true;
  for (int i = 0; i < 3; i++)
  {
    if (!a[i])
      ans = "No";
  }
  cout << ans << endl;
}