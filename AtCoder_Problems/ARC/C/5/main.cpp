#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> c(500, vector<char>(500, '#'));
vector<vector<int>> dest_count(500, vector<int>(500, -1));
queue<pair<int, int>> q;
bool flag = false;
int H, W;

bool check_c(int m, int n, int dest)
{
  int tmp_dest;

  if (m == -1 || n == -1 || m == H || n == W)
    return (false);
  if (c[m][n] == 'g')
  {
    flag = true;
    return (true);
  }
  tmp_dest = dest;
  if (c[m][n] == '#')
    tmp_dest++;
  if (tmp_dest == 3 || (dest_count[m][n] <= tmp_dest && dest_count[m][n] != -1))
    return (false);
  dest_count[m][n] = tmp_dest;
  q.push(make_pair(m, n));
  return (false);
}

int main()
{
  pair<int, int> tmp;
  int m, n, dest;

  cin >> H >> W;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> c[i][j];
      if (c[i][j] == 's')
      {
        q.push(make_pair(i, j));
        dest_count[i][j] = 0;
      }
    }
  }
  while (!q.empty())
  {
    tmp = q.front();
    q.pop();
    m = tmp.first;
    n = tmp.second;
    dest = dest_count[m][n];
    if (check_c(m + 1, n, dest) || check_c(m - 1, n, dest) || check_c(m, n + 1, dest) || check_c(m, n - 1, dest))
      break;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}