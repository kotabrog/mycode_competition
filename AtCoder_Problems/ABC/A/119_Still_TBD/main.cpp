#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int a;
  cin >> s;
  a = (int)(s[5] - '0') * 10 + (int)(s[6] - '0');
  cout << (a <= 4 ? "Heisei" : "TBD") << endl;
}