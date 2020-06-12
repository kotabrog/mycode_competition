#include <bits/stdc++.h>
using namespace std;

int main()
{
  int X, a;

  cin >> X;
  a = X / 500;
  cout << a * 1000 + ((X - (500 * a)) / 5) * 5 << endl;
}