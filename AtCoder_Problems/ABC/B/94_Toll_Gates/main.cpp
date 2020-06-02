#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, x, a, count_0_cost = 0;

  cin >> n >> m >> x;
  for (int i = 0; i < m; i++)
  {
    cin >> a;
    if (a < x)
      count_0_cost++;
  }
  cout << (count_0_cost <= m / 2 ? count_0_cost : m - count_0_cost) << endl;
}