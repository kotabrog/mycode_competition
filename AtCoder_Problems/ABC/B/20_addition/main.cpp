#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, up = 1;
  
  cin >> a >> b;
  while (b / up != 0)
    up *= 10;
  cout << (a * up + b) * 2 << endl;
}
