#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, L;
  cin >> N >> L;

  vector<string> v(N);
  for (int i = 0; i < N; i++)
    cin >> v[i];
  
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++)
    cout << v[i];
  cout << endl;
}
