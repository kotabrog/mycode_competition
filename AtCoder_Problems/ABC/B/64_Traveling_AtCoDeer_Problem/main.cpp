#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, min_a = 1000, max_a = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    min_a = min(min_a, a);
    max_a = max(max_a, a);
  }
  cout << max_a - min_a << endl;
}