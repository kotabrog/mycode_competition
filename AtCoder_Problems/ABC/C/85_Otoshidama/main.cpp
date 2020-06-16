#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, Y, k;

  cin >> N >> Y;
  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j <= N; j++)
    {
      k = N - i - j;
      if (k < 0)
        break;
      if (i * 10000 + j * 5000 + k * 1000 == Y)
      {
        cout << i << " " << j << " " << k << endl;
        return (0);
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}