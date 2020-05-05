#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, A, B, count = 0;
  vector<int> H(100000);
  vector<bool> check_flag(100000, true);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> H[i];
  for (int i = 0; i < M; i++)
  {
    cin >> A >> B;
    if (H[A - 1] > H[B - 1])
      check_flag[B - 1] = false;
    else if (H[A - 1] < H[B - 1])
      check_flag[A - 1] = false;
    else
    {
      check_flag[B - 1] = false;
      check_flag[A - 1] = false;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (check_flag[i])
      count++;
  }
  cout << count << endl;
}