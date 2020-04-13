#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> s(52, vector<char>(52, '#'));
vector<vector<int>> s_count(52, vector<int>(52, 0));
queue<pair<int, int>> q;
int H, W, tmp_count;

bool push_q(int m, int n)
{
  if (s[m][n] != '#' && !s_count[m][n])
  {
    s_count[m][n] = tmp_count + 1;
    if (m == H && n == W)
      return (true);
    q.push(make_pair(m, n));
  }
  return (false);
}

int main()
{
  int w_count = 0, m, n;
  pair<int, int> tmp;


  cin >> H >> W;
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      cin >> s[i][j];
      if (s[i][j] == '.')
        w_count++;
    }
  }
  q.push(make_pair(1, 1));
  while (!q.empty())
  {
    tmp = q.front();
    q.pop();
    m = tmp.first;
    n = tmp.second;
    tmp_count = s_count[m][n];
    if (push_q(m + 1, n) || push_q(m - 1, n) || push_q(m, n + 1) || push_q(m, n - 1))
      break;
  }
  if (s_count[H][W] == 0)
    cout << -1 << endl;
  else
    cout << w_count - s_count[H][W] - 1 << endl;
}