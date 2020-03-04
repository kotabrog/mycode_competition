#include <bits/stdc++.h>
using namespace std;

//TLE

void sorted_arrays(int a[100000], int N, int *count, int i, int temp_c, bool flag)
{
  if (i == N)
  {
    *count = min(*count, temp_c);
    return;
  }
  if (i == 0)
  {
    sorted_arrays(a, N, count, 1, 1, true);
    sorted_arrays(a, N, count, 1, 1, false);
    return;
  }
  if ((flag && a[i] < a[i - 1]) || (!flag && a[i - 1] < a[i]))
  {
    sorted_arrays(a, N, count, i + 1, temp_c + 1, true);
    sorted_arrays(a, N, count, i + 1, temp_c + 1, false);
  }
  else
    sorted_arrays(a, N, count, i + 1, temp_c, flag);
}

int main()
{
  int N;
  int a[100000];
  int count = 100000;

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> a[i];
  sorted_arrays(a, N, &count, 0, 1, true);
  cout << count << endl;
}
