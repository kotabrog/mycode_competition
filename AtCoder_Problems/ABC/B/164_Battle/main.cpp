#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, d;

  cin >> a >> b >> c >> d;
  a = (a - 1) / d + 1;
  c = (c - 1) / b + 1;
  cout << (c <= a ? "Yes" : "No") << endl;
}