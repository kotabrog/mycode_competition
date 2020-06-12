#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, m, a;

  cin >> n >> k >> m;
  m *= n;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a;
    m -= a;
  }
  cout << (m > k ? -1 : max(0, m)) << endl;
}