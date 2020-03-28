#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> v(100, vector<bool>(100, false));
vector<bool> v_flag(100, false);
bool flag;
int N;

void tree(int n, int before_n)
{
  if (!flag)
    return ;
  if (v_flag[n])
  {
    flag = false;
    return ;
  }
  v_flag[n] = true;
  for (int i = 0; i < N; i++)
  {
    if (i != before_n && v[n][i])
      tree(i, n);
  }
}

int main()
{
  int M, a, b, ans = 0;


  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    v[a - 1][b - 1] = true;
    v[b - 1][a - 1] = true;
  }
  for (int i = 0; i < N; i++)
  {
    if (!v_flag[i])
    {
      flag = true;
      tree(i, 100);
      if (flag)
        ans++;
    }
  }
  cout << ans << endl;
}