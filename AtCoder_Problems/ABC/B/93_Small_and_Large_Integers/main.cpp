#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, k;

  cin >> a >> b >> k;
  for (int i = 0; i < k; i++)
  {
    if (a + i <= b)
      cout << a + i << endl;
  }
  for (int i = 0; i < k; i++)
  {
    if (b - k + i + 1 >= a + k)
      cout << b - k + i + 1 << endl;
  }
}