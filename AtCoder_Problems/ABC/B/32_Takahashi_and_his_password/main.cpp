#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int k, ans = 0;
  unordered_set<string> u;

  cin >> s >> k;
  if (s.size() >= k)
  {
    for (int i = 0; i < s.size() - k + 1; i++)
    {
      string tmp = "";
      for (int j = 0; j < k; j++)
        tmp += s[i + j];
      if (!u.count(tmp))
      {
        u.insert(tmp);
        ans++;
      }
    }
  }
  cout << ans << endl;
}
