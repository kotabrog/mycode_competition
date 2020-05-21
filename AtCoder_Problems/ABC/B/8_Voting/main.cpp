#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, top_count = 0;
  string s, ans;
  map<string, int> a;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    if (a.count(s))
      a[s]++;
    else
      a[s] = 1;
  }
  for (auto p : a)
  {
    if (top_count < p.second)
    {
      top_count = p.second;
      ans = p.first;
    }
  }
  cout << ans << endl;
}
