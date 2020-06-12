#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int main()
{
  int a, b, h, m;
  double ta, tb, t;

  cin >> a >> b >> h >> m;
  ta = 30 * h + (double)m / 2;
  tb = 6 * m;
  t = min(abs(ta - tb), 360 - abs(ta - tb));
  t = sqrt(a * a + b * b - 2 * a * b * cos(t / 180 * M_PI));
  cout << fixed << setprecision(9) << t << endl;
}