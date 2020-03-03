#include <bits/stdc++.h>
using namespace std;

// d = ax + by (dは最大公約数)と求めたが、
// x, y が負の数であるという可能性を考慮していなかった

int gcd(int a, int b)
{
  int temp;

  while (b)
  {
    temp = b;
    b = a % b;
    a = temp;
  }
  return (a);
}

void water_fn(int A, int B, int gcdCD, int E, int F, int *ans_sg, int *ans_wg, int wg)
{
  int sg;

  if (F < wg)
    return;
  // cout << sg << " " << wg << endl;
  sg = (min(F - wg, wg * E / 100) / gcdCD) * gcdCD;
  if (*ans_sg * (sg + wg) < sg * (*ans_sg + *ans_wg) || *ans_sg * *ans_wg == 0)
  {
    *ans_sg = sg;
    *ans_wg = wg;
  }
  water_fn(A, B, gcdCD, E, F, ans_sg, ans_wg, wg + A * 100);
  water_fn(A, B, gcdCD, E, F, ans_sg, ans_wg, wg + B * 100);
}

int main()
{
  int A, B, C, D, E, F;
  int ans_sg = 0, ans_wg = 0;

  cin >> A >> B >> C >> D >> E >> F;
  water_fn(A, B, gcd(C, D), E, F, &ans_sg, &ans_wg, 0);
  cout << ans_wg + ans_sg << " " << ans_sg << endl;
}