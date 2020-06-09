#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, ans;
  
  cin >> n;
  if (n < 10)
    ans = n;
  else if (n < 100)
    ans = 9;
  else if (n < 1000)
    ans = 9 + n - 99;
  else if (n < 10000)
    ans = 909;
  else if (n == 100000)
    ans = 90909;
  else
    ans = 909 + n - 9999;
  cout << ans << endl;
}