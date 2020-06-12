#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int main()
{
  int n, a;
  vector<int> b(200000, 0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> a;
    b[a - 1]++;
  }
  for (int i = 0; i < n; i++)
    cout << b[i] << endl;
}