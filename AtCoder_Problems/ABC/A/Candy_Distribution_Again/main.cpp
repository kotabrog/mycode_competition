#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, x;
  cin >> N >> x;

  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  sort(a.begin(), a.end());

  int count = 0;
  int temp = 0;
  for (int i = 0; i < N; i++)
  {
    temp += a[i];
    if (x < temp || (temp < x && i == N - 1))
      break;
    count++;
  }
  cout << count << endl;
}
