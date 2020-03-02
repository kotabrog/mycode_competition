#include <bits/stdc++.h>
using namespace std;

int64_t calc_digit(int64_t n)
{
  int ans = 0;
  while(n != 0)
  {
    ans++;
    n /= 10;
  }
  return (ans);
}

int main()
{
  int64_t N, ans = 11, i = 1;

  cin >> N;
  while (i * i <= N)
  {
    if (N % i == 0)
      ans = min(max(calc_digit(i), calc_digit(N / i)), ans);
    i++;
  }
  cout << ans << endl;
}