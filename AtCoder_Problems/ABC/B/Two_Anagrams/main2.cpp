#include <bits/stdc++.h>
using namespace std;

// reference: MedAzizTousli 

int main()
{
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.begin());
  sort(t.rbegin(), t.rend());
  cout << (t > s? "Yes": "No") << endl;
}
