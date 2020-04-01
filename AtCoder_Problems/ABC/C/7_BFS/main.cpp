#include <bits/stdc++.h>
using namespace std;

int main()
{
  pair<int, int> s;
  pair<int, int> g;
  queue<pair<int, int>> q;
  vector<vector<char>> c(50, vector<char>(50));
  vector<vector<int>> c_n(50, vector<int>(50, 2500));
  int R, C, m, n, count = 0;

  cin >> R >> C;
  cin >> s.first >> s.second;
  cin >> g.first >> g.second;
  s.first--;
  s.second--;
  g.first--;
  g.second--;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
      cin >> c[i][j];
  }
  q.push(s);
  c_n[s.first][s.second] = 0;
  while (!q.empty())
  {
    m = q.front().first;
    n = q.front().second;
    count = c_n[m][n];
    if (q.front() == g)
      break;
    q.pop();
    if (c[m][n] == '#')
      continue;
    c[m][n] = '#';
    q.push(make_pair(m - 1, n));
    q.push(make_pair(m + 1, n));
    q.push(make_pair(m, n - 1));
    q.push(make_pair(m, n + 1));
    c_n[m - 1][n] = min(c_n[m - 1][n], count + 1);
    c_n[m + 1][n] = min(c_n[m + 1][n], count + 1);
    c_n[m][n - 1] = min(c_n[m][n - 1], count + 1);
    c_n[m][n + 1] = min(c_n[m][n + 1], count + 1);
  }
  cout << count << endl;
}