#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << (n % 10 == 3 ? "bon" : n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8 ? "pon" : "hon") << endl;
}