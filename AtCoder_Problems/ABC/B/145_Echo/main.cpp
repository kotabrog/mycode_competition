#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s;
  bool flag = true;

  cin >> n >> s;
  if (n % 2 == 1)
    flag = false;
  else
  {
    for (int i = 0; i < n / 2; i++)
    {
      if (s[i] != s[n / 2 + i])
        flag = false;
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}