#include <bits/stdc++.h>
using namespace std;

int main()
{
  int D;
  cin >> D;
  cout << (D==25 ? "Christmas" : D==24 ? "Christmas Eve" : D==23 ? "Christmas Eve Eve" : "Christmas Eve Eve Eve") << endl;
}