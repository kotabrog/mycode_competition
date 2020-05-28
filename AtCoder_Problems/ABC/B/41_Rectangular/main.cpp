#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t a, b, c, q = 1000000007;
  cin >> a >> b >> c;
  cout << (((a % q) * (b % q)) % q * (c % q)) % q << endl;
}