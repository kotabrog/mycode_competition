#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, x, y;
  vector<pair<int, int>> a(50), b(50), c(50);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    a[i] = make_pair(x, y);
  }
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    b[i] = make_pair(x, y);
  }
  for (int i = 0; i < n; i++)
  {
    c[i] = make_pair(0, abs(a[i].first - b[0].first) + abs(a[i].second - b[0].second));
    for (int j = 1; j < m; j++)
    {
      if (c[i].second > abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second))
        c[i] = make_pair(j, abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second));
    }
  }
  for (int i = 0; i < n; i++)
    cout << c[i].first + 1 << endl;
}