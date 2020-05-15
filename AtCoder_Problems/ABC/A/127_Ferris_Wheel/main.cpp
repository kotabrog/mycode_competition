#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  cout << (a < 6 ? 0 : a < 13 ? b / 2 : b) << endl;
}