#include <bits/stdc++.h>
using namespace std;

int sum_digit(int n)
{
  int sum_n = 0;

  while (n != 0)
  {
    sum_n += n % 10;
    n /= 10;
  }
  return (sum_n);
}

int main()
{
  int N, temp;
  int ans = 100000;

  cin >> N;
  for (int i = 1; i < N; i++)
  {
    temp = sum_digit(i);
    temp += sum_digit(N - i);
    ans = min(temp, ans);
  }
  cout << ans << endl;
}