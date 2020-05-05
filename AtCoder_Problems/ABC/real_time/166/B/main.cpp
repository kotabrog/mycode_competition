#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<bool> sn(100, false);
  int N, K, count = 0, d, a;

  cin >> N >> K;
  for (int i = 0; i < K; i++)
  {
    cin >> d;
    for (int j = 0; j < d; j++)
    {
      cin >> a;
      sn[a - 1] = true;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (!sn[i])
      count++;
  }
  cout << count << endl;
}