#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  cout << (s == "SUN" ? 7 : s == "MON" ? 6 : s == "TUE" ? 5 : s == "WED" ?  4 : s == "THU" ? 3 : s == "FRI" ? 2 : 1) << endl;
}