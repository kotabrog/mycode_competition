#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  int64_t ans = 1;
  vector<int64_t> a(100000);
  bool flag = true;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 0)
    {
      flag = true;
      ans = 0;
      break;
    }
    if (a[i] < (int64_t)pow(10, 9) * (int64_t)pow(10, 9) / ans + 1)
      ans *= a[i];
    else
      flag = false;
  }
  cout << (flag ? ans : -1) << endl;
}