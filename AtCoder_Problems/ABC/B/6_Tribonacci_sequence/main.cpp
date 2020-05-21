#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int64_t> a{0, 0, 1};
  int n;
  cin >> n;
  for (int i = 3; i < n; i++)
    a.push_back((a[i-3] + a[i-2] + a[i-1]) % 10007);
  cout << a[n - 1] << endl;
}
