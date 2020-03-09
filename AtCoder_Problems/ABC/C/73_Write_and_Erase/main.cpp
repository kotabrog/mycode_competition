#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A;
  map<int, bool> a;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A;
    if (a.count(A))
      a.erase(A);
    else
      a[A] = true;
  }
  cout << a.size() << endl;
}