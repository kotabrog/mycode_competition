#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans = 0;
  string s;
  map<string, int> x;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    if (x.count(s))
      x[s]++;
    else
      x[s] = 1;
  }
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    if (x.count(s))
      x[s]--;
    else
      x[s] = -1;
  }
  for (auto p: x)
  {
    ans = max(ans, p.second);
  }
  cout << ans << endl;
}