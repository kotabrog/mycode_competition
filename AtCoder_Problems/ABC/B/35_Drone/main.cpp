#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, ans;
  string s, u = "LRUD?";
  vector<int> s_count(5, 0);

  cin >> s >> t;
  for (int i = 0; i < s.size(); i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (u[j] == s[i])
      {
        s_count[j]++;
        break;
      }
    }
  }
  ans = abs(s_count[0] - s_count[1]) + abs(s_count[2] - s_count[3]);
  if (t == 1)
    ans += s_count[4];
  else
  {
    if (ans < s_count[4])
      ans = (s_count[4] - ans) % 2;
    else
      ans -= s_count[4];
  }
  cout << ans << endl;
}
