#include <bits/stdc++.h>
using namespace std;

//sugarを調べる順番を逆にした
//j++ → j--
//1ms

bool match_two_num(int a, int b, int m)
{
  bool flag = false;

  for (int i = 0; i <= m / a; i++)
  {
    if ((m - a * i) % b == 0)
    {
      flag = true;
      break;
    }
  }
  return (flag);
}

int main()
{
  int A, B, C, D, E, F, max_sg;
  int ans_sg = 0, ans_wg = 0;

  cin >> A >> B >> C >> D >> E >> F;
  for (int i = 100 * A; i < F; i += 100)
  {
    if (!match_two_num(100 * A, 100 * B, i))
      continue;
    max_sg = min(F - i, i * E / 100);
    for (int j = max_sg; j >= 1; j--)
    {
      if (!(ans_sg * (j + i) < j * (ans_sg + ans_wg) || (ans_sg == 0 && j != 0)))
        continue;
      if (!match_two_num(C, D, j))
        continue;
      ans_sg = j;
      ans_wg = i;
    }
  }
  if (ans_wg == 0)
    ans_wg = 100 * A;
  cout << ans_wg + ans_sg << " " << ans_sg << endl;
}