#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K;
  int64_t now_a, move_count = 0, start_a;
  vector<int> a(200001);
  vector<bool> a_flag(200001, false);
  vector<bool> b_flag(200001, false);


  cin >> N >> K;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  now_a = 1;
  while (!a_flag[now_a])
  {
    a_flag[now_a] = true;
    now_a = a[now_a];
  }
  while (!b_flag[now_a])
  {
    b_flag[now_a] = true;
    now_a = a[now_a];
    move_count++;
  }
  start_a = now_a;
  now_a = 1;
  while (now_a != start_a)
  {
    now_a = a[now_a];
    K--;
    if (K == 0)
      break;
  }
  K = K % move_count;
  for (int i = 0; i < K; i++)
  {
    now_a = a[now_a];
  }
  cout << now_a << endl;
}
