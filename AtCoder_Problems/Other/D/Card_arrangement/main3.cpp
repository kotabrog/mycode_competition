#include <bits/stdc++.h>
using namespace std;

int n, k, ans=0;
vector<int> card(10);
vector<bool> comb_flag(100000000, false);

int calc_card(vector<int> a)
{
  int result = 0;
  for (int i = 0; i < k; i++)
  {
    if (card[a[i]] > 9)
      result = result * 100 + card[a[i]];
    else
      result = result * 10 + card[a[i]];
  }
  return (result);

}

int main()
{
  int temp;

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> card[i];
  for (int i0 = 0; i0 < n; i0++)
  {
    for (int i1 = 0; i1 < n; i1++)
    {
      if (i1 == i0)
        continue;
      for (int i2 = 0; i2 < n; i2++)
      {
        if (i2 == i1 || i2 == i0)
          continue;
        for (int i3 = 0; i3 < n; i3++)
        {
          if (i3 == i2 || i3 == i1 || i3 == i0)
            continue;
          vector<int> a(k);
          a[0] = i0;
          a[1] = i1;
          if (k > 2)
            a[2] = i2;
          if (k > 3)
            a[3] = i3;
          temp = calc_card(a);
          if (!comb_flag[temp])
          {
            comb_flag[temp] = true;
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
