#include <bits/stdc++.h>
using namespace std;

int digit(int64_t N, int i)
{
  return (N / (int64_t)pow(10, i - 1) % 10);
}

int n_digit(int64_t N)
{
  int count = 0;
  while (N)
  {
    N /= 10;
    count++;
  }
  return count;
}

int main()
{
  int K, n, count = 9;
  vector<int> a(64);
  int64_t ans = 10;

  cin >> K;
  if (K < 10)
  {
    cout << K << endl;
    return (0);
  }
  while (count < K)
  {
    n = n_digit(ans);
    a[0] = digit(ans, n);
    for (int i = 0; i < n - 1; i++)
    {
      a[i + 1] = digit(ans, n - i - 1);
      if (abs(a[i] - a[i + 1]) <= 1)
      {
        if (i == n - 2)
        {
          count++;
          ans++;
        }
        continue;
      }
      else if (a[i] < a[i + 1])
        ans += (int64_t)((10 - a[i + 1]) * pow(10, n - i - 2));
      else
        ans += (int64_t)((a[i] - 1) * pow(10, n - i - 2));
      break;
    }
  }
  cout << ans - 1 << endl;
}