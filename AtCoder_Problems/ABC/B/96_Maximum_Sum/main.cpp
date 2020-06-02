#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  cout << a + b + c + max(a, max(b, c)) * (int)pow(2, k) - max(a, max(b, c)) << endl;
}