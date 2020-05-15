#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a;
  cin >> a;
  cout << (a == 'A' ? 'T' : a == 'T' ? 'A' : a == 'C' ? 'G' : 'C') << endl;
}