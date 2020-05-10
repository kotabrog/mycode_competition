#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A, r;
  string s = "No";

  cin >> N >> A;
  r = N % 500;
  if (r <= A)
    s = "Yes";
  cout << s << endl;
}