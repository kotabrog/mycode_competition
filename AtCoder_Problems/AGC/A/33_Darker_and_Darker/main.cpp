#include <bits/stdc++.h>
using namespace std;

int H, W, ans = 0;
vector<vector<char>> a(1002, vector<char>(1002, '#'));
vector<vector<int>> a_count(1002, vector<int>(1002, 0));
queue<pair<int, int>> q;

void push_q(int m, int n, int tmp_count)
{
  if (a_count[m][n] || a[m][n] == '#')
    return ;
  q.push(make_pair(m, n));
  a[m][n] = '#';
  a_count[m][n] = tmp_count + 1;
  ans = max(ans, a_count[m][n]);
}

int main()
{
  int m, n;
  pair<int, int> tmp;

  cin >> H >> W;
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == '#')
        q.push(make_pair(i, j));
    }
  }
  while (!q.empty())
  {
    tmp = q.front();
    q.pop();
    m = tmp.first;
    n = tmp.second;
    push_q(m + 1, n, a_count[m][n]);
    push_q(m - 1, n, a_count[m][n]);
    push_q(m, n + 1, a_count[m][n]);
    push_q(m, n - 1, a_count[m][n]);
  }
  cout << ans << endl;
}