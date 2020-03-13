#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, num = 1, count = 0, tmp;
  vector<int> a(1000001);

  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  while (num != 2 && a[num] != 0)
  {
    tmp = num;
    num = a[num];
    a[tmp] = 0;
    count++;
  }
  if (num != 2)
    count = -1;
  cout << count << endl;
}