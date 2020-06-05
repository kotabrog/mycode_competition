#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n;
  cin >> n;
  cout << (n < 105 ? 0 : n < 135 ? 1 : n < 165 ? 2 : n < 189 ? 3 : n < 195 ? 4 : 5) << endl;
}