#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(min(a + b, a + c), b + c) << endl;
}