#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int main()
{
  unordered_set<string> s_set;
  int n, ans = 0;
  string s;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    if (!s_set.count(s))
    {
      s_set.insert(s);
      ans++;
    }
  }
  cout << ans << endl;
}