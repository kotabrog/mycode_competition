#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, q = pow(10, 9) + 7;
  int64_t ans = 1;

  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    ans *= i;
    ans %= q;
  }
  cout << ans << endl;
}