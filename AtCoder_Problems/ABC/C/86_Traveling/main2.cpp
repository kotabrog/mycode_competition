#include <bits/stdc++.h>
using namespace std;

void traveling(int *N, vector<vector<int>> txy, int t, int x, int y, int i)
{
  if (*N == 0)
    return ;
  if (t == txy[*N - 1][0] + 1)
    return ;
  
  int dift, difx, dify;
  dift = txy[i][0] - t;
  difx = abs(txy[i][1] - x);
  dify = abs(txy[i][2] - y);
  // cout << t << "," << x << "," << y << "," << i << endl;
  if (dift != 0)
  {
    if (dift < difx + dify)
      return ;
  }
  else
  {
    if (difx || dify)
      return ;
    i++;
    if (i == *N)
    {
      *N = 0;
      return ;
    }
  }
  // cout << t << "," << x << "," << y << "," << i << endl;

  // if (txy[i][0] == t && (txy[i][1] != x || txy[i][2] != y))
  //   return ;
  // if (txy[i][0] == t)
  // {
  //   i++;
  //   if (i == *N)
  //     *N = 0;
  // }
  if (abs(txy[i][1] - (x + 1)) < difx)
    traveling(N, txy, t + 1, x + 1, y, i);
  if (x != 0 && abs(txy[i][1] - (x - 1)) < difx)
    traveling(N, txy, t + 1, x - 1, y, i);
  if (abs(txy[i][2] - (y + 1)) <= dify || y == 0)
    traveling(N, txy, t + 1, x, y + 1, i);
  else
    traveling(N, txy, t + 1, x, y - 1, i);
}

int main()
{
  int N;
  cin >> N;

  vector<vector<int>> txy(N, vector<int>(3));
  for (int i = 0; i < N; i++)
    cin >> txy[i][0] >> txy[i][1] >> txy[i][2];
  // cout << N << endl;
  traveling(&N, txy, 0, 0, 0, 0);
  // cout << N << endl;
  if (N == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}