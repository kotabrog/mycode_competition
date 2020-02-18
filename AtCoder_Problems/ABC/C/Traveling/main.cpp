#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<vector<int>> txy(N + 1, vector<int>(3));
  for (int i = 0; i < 2; i++)
    txy[0][i] = 0;
  for (int i = 0; i < N; i++)
    cin >> txy[i + 1][0] >> txy[i + 1][1] >> txy[i + 1][2];

  int dift, difx, dify;
  for (int i = 0; i < N; i++)
  {
    dift = txy[i + 1][0] - txy[i][0];
    difx = abs(txy[i + 1][1] - txy[i][1]);
    dify = abs(txy[i + 1][2] - txy[i][2]);
    if (dift < difx + dify)
      N = 0;
    if ((dift % 2) != ((difx + dify) % 2))
      N = 0;
  }

  if (N != 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}