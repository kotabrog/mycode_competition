#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << (n <= 59 ? "Bad" : n <= 89 ? "Good" : n <= 99 ? "Great" : "Perfect") << endl;
}
