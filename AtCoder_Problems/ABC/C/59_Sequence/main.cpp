#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  vector<int64_t> a(100000);
  int64_t ans1 = 0, ans2 = 0, sum = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
  {
    if (i % 2 != 0 && sum + a[i] >= 0)
    {
      ans1 += abs(sum * (-1) - 1 - a[i]);
      sum = - 1;
    }
    else if (i % 2 == 0 && sum + a[i] <= 0)
    {
      ans1 += abs(sum * (-1) + 1 - a[i]);
      sum = 1;
    }
    else
      sum += a[i];
  }
  sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0 && sum + a[i] >= 0)
    {
      ans2 += abs(sum * (-1) - 1 - a[i]);
      sum = - 1;
    }
    else if (i % 2 != 0 && sum + a[i] <= 0)
    {
      ans2 += abs(sum * (-1) + 1 - a[i]);
      sum = 1;
    }
    else
      sum += a[i];
  }
  cout << min(ans1, ans2) << endl;
}