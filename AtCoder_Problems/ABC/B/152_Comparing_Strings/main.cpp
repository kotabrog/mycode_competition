#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, d;

  cin >> a >> b;
  c = min(a, b);
  d = max(a, b);
  for (int i = 0; i < d; i++)
    cout << c;
  cout << endl;
}