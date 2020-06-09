#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, p, flag = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> p;
    if (i + 1 != p)
      flag++;
  }
  cout << (flag > 2 ? "NO" : "YES") << endl;
}