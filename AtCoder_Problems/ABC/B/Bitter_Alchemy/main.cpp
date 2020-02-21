#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, X, m;
  int min_m = 1000;
  int sum = 0;

  cin >> N >> X;
  for (int i = 0; i < N; i++)
  {
    cin >> m;
    min_m = min(m, min_m);
    sum += m;
  }
  X -= sum;
  cout << N + X / min_m << endl;;
}