#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, a;
  vector<int> x(100001, 0);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    if (a == 0)
    {
      x[0]++;
      x[1]++;
    }
    else
    {
      x[a - 1]++;
      x[a]++;
      x[a + 1]++;
    }
  }
  a = 0;
  for (int i = 0; i < 100001; i++)
    a = max(a, x[i]);
  cout << a << endl;
}