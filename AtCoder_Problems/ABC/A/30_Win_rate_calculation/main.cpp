#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (b * c < a * d ? "AOKI" : a * d < b * c ? "TAKAHASHI" : "DRAW") << endl;
}
