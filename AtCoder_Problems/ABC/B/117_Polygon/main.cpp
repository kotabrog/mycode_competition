#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, l, max_l = 0, sum_l = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> l;
    sum_l += l;
    max_l = max(l, max_l);
  }
  cout << (max_l < sum_l - max_l ? "Yes" : "No") << endl;
}