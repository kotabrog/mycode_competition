#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, sum_a = 0, ans = 0, start, temp_sum;
  vector<int> a(100);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum_a += a[i];
  }
  if (sum_a % n != 0)
    ans = -1;
  else
  {
    int j = 0;
    while (j < n - 1)
    {
      start = j;
      temp_sum = a[j];
      j++;
      while (temp_sum * n != sum_a * (j - start) && j < n)
      {
        temp_sum += a[j];
        j++;
      }
      ans += j - start - 1;
    }
  }
  cout << ans << endl;
}
