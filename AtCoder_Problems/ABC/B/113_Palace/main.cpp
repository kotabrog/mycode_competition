#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, T, A, H;
  int ans;
  double ans_H = 1000000;

  cin >> N >> T >> A;
  for (int i = 1; i <= N; i++)
  {
    cin >> H;
    if (abs(A - (T - H * 0.006)) < ans_H)
    {
      ans_H = abs(A - (T - H * 0.006));
      ans = i;
    }
  }
  cout << ans << endl;
}