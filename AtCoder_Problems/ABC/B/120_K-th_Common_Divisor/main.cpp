#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int a, b, k, k_count = 0, i;

  cin >> a >> b >> k;
  i = min(a, b);
  while (true)
  {
    if (a % i == 0 && b % i == 0)
    {
      k_count++;
      if (k_count == k)
        break;
    }
    i--;
  }
  cout << i << endl;
}