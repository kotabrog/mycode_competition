#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> uv(100000, vector<vector<int>>(2));
vector<vector<int>> uv_N(100000, vector<int>(2, 0));
vector<int> even_odd(100000, -1);
int N;

void dfs(int n)
{
  int tmp;
  for (int i = 0; i < uv_N[n][0]; i++)
  {
    tmp = uv[n][0][i];
    if (even_odd[tmp] != -1)
      continue;
    even_odd[tmp] = even_odd[n];
    dfs(tmp);
  }
  for (int i = 0; i < uv_N[n][1]; i++)
  {
    tmp = uv[n][1][i];
    if (even_odd[tmp] != -1)
      continue;
    if (even_odd[n] == 1)
      even_odd[tmp] = 0;
    else
      even_odd[tmp] = 1;
    dfs(tmp);
  }
}

int main()
{
  int u, v, w;

  cin >> N;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> u >> v >> w;
    if (w % 2 == 0)
    {
      uv[u - 1][0].push_back(v - 1);
      uv[v - 1][0].push_back(u - 1);
      uv_N[u - 1][0]++;
      uv_N[v - 1][0]++;
    }
    else
    {
      uv[u - 1][1].push_back(v - 1);
      uv[v - 1][1].push_back(u - 1);
      uv_N[u - 1][1]++;
      uv_N[v - 1][1]++;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (even_odd[i] == -1)
    {
      even_odd[i] = 0;
      dfs(i);
    }
  }
  for (int i = 0; i < N; i++)
    cout << even_odd[i] << '\n';
}