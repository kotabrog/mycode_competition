#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  int a[100000];
  int count = 1, flag = 0;

  cin >> N;
  if (N == 1)
  {
    cout << 1 << endl;
    return (0);
  }
  for (int i = 0; i < N; i++)
    cin >> a[i];
  for (int i = 0; i < N; i++)
  {
    if (!flag)
    {
      if (i == N - 1)
        break;
      if (a[i] < a[i + 1])
        flag = 1;
      else if (a[i + 1] < a[i])
        flag = -1;
    }
    else if (flag * a[i] < flag * a[i - 1])
    {
      count++;
      if (i == N - 1)
        break;
      if (a[i] < a[i + 1])
        flag = 1;
      else if (a[i + 1] < a[i])
        flag = -1;
      else
        flag = 0;
    }
  }
  cout << count << endl;
}
