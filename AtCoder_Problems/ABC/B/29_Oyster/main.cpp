#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans = 0;
  string s;

  for (int i = 0; i < 12; i++)
  {
    cin >> s;
    if (s.find('r') != string::npos)
      ans++;
  }
  cout << ans << endl;
}
