#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s, t = "b";

  cin >> n >> s;
  n = (n - 1) / 2;
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0)
      t = "a" + t + "c";
    else if (i % 3 == 1)
      t = "c" + t + "a";
    else
      t = "b" + t + "b";
  }
  cout << (s == t ? n : -1) << endl;
}
