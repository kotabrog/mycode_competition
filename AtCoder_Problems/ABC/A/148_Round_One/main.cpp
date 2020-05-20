#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  cout << ((a == 1 || b == 1) && (a == 2 || b == 2) ? 3 : \
          (a == 3 || b == 3) && (a == 2 || b == 2) ? 1 : 2) << endl;
}