#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int s, i = 2;
  vector<bool> a(1000001, false);

  cin >> s;
  a[s] = true;
  while(true)
  {
    if (s % 2 == 0)
      s /= 2;
    else
      s = 3 * s + 1;
    if (a[s])
      break;
    a[s] = true;
    i++;
  }
  cout << i << endl;
}