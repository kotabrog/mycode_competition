#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, d, x, a;

  cin >> n >> d >> x;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    x += (d - 1) / a + 1;
  }
  cout << x << endl;
}