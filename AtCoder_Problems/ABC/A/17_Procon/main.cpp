#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, ans=0;
  for (int i = 0; i < 3; i++)
  {
    cin >> a >> b;
    ans += a * b;
  }
  cout << ans / 10 << endl;
}
