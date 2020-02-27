#include <bits/stdc++.h>
using namespace std;

int main()
{
  int W, H, N;
  cin >> W >> H >> N;

  int left = 0, right = W, bottom = 0, top = H;
  int x, y, a;
  for (int i = 0; i < N; i++)
  {
    cin >> x >> y >> a;
    if (a == 1)
      left = max(left, x);
    if (a == 2)
      right = min(right, x);
    if (a == 3)
      bottom = max(bottom, y);
    if (a == 4)
      top = min(top, y);
  }
  cout << max((right - left), 0) * max((top - bottom), 0) << endl;
}