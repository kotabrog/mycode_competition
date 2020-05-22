#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  cout << min(abs(a - b), 10 - max(a, b) + min(a, b)) << endl;
}
