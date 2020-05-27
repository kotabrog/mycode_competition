#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, n = 1;
  cin >> x;
  while (x != n * n * n * n)
    n++;
  cout << n << endl;
}
