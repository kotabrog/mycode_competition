#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N = 0, tmp_i;
  int64_t ans = 0, num, tmp_num;

  cin >> num;
  tmp_num = num;
  while (tmp_num)
  {
    N++;
    tmp_num /= 10;
  }
  for (int tmp = 0; tmp < (1 << N - 1); tmp++)
  {
    bitset<10> s(tmp);
    tmp_num = num;
    tmp_i = 0;
    for (int i = 1; i < N; i++)
    {
      if (s[i - 1])
      {
        ans += tmp_num % (int)pow(10, i - tmp_i);
        tmp_num = tmp_num / (int)pow(10, i - tmp_i);
        tmp_i = i;
      }
    }
    ans += tmp_num;
  }
  cout << ans << endl;
}