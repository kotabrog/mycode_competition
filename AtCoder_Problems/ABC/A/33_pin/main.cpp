#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a;
  cin >> n;
  if (n / 1000 == ((n / 100) % 10) && n / 1000 == (n / 10) % 10 && n / 1000 == n % 10)
    cout << "SAME" << endl;
  else
    cout << "DIFFERENT" << endl;
}
