#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, n, a;

  cin >> h >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    h -= a;
  }
  cout << (h <= 0 ? "Yes" : "No") << endl;
}