#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, X, Y, tmp;
  vector<int> a(2000, 0);

  cin >> N >> X >> Y;
  for (int i = 1; i < N; i++)
  {
    for (int j = i + 1; j <= N; j++)
    {
      if (i <= X && X < j)
      {
        if (Y <= j)
          a[X - i + 1 + j - Y]++;
        else
        {
          tmp = min(j - i, X - i + 1 + Y - j);
          a[tmp]++;
        }
      }
      else if (X < i && i < Y - 1)
      {
        if (Y <= j)
        {
          tmp = min(j - i, i - X + 1 + j - Y);
          a[tmp]++;
        }
        else
        {
          tmp = min(j - i, i - X + 1 + Y - j);
          a[tmp]++;
        }
      }
      else
        a[j - i]++;
    }
  }
  for (int i = 1; i < N; i++)
  {
    cout << a[i] << endl;
  }
}