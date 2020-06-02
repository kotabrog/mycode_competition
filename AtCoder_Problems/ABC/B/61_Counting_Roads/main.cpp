#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, temp;
  cin >> N >> M;

  vector<int> count(N, 0);
  for (int i = 0; i < 2 * M; i++)
  {
    cin >> temp;
    count[temp - 1]++;
  }
  for (int i = 0; i < N; i++)
    cout << count[i] << endl;
}