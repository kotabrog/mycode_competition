#include <bits/stdc++.h>
using namespace std;

// TLE

void sugar_fn(int C, int D, int E, int F, int wg, int sg, int *ret_sg)
{
  if (F < sg + wg || wg * E < sg * 100)
    return;
  *ret_sg = max(*ret_sg, sg);
  sugar_fn(C, D, E, F, wg, sg + C, ret_sg);
  cout << sg << " " << wg << endl;
  sugar_fn(C, D, E, F, wg, sg + D, ret_sg);
}

void water_fn(int A, int B, int C, int D, int E, int F, int *ans_sg, int *ans_wg, int wg)
{
  int sg = 0;

  if (F < wg)
    return;
  sugar_fn(C, D, E, F, wg, 0, &sg);
  cout << sg << " " << wg << endl;
  if (*ans_sg * (sg + wg) < sg * (*ans_sg + *ans_wg) || *ans_sg * *ans_wg == 0)
  {
    *ans_sg = sg;
    *ans_wg = wg;
  }
  water_fn(A, B, C, D, E, F, ans_sg, ans_wg, wg + A * 100);
  water_fn(A, B, C, D, E, F, ans_sg, ans_wg, wg + B * 100);
}

int main()
{
  int A, B, C, D, E, F;
  int ans_sg = 0, ans_wg = 0;

  cin >> A >> B >> C >> D >> E >> F;
  water_fn(A, B, C, D, E, F, &ans_sg, &ans_wg, 0);
  cout << ans_wg + ans_sg << " " << ans_sg << endl;
}