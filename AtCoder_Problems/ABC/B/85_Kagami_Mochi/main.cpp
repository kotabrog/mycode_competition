#include <bits/stdc++.h>
using namespace std;

int main()
{
  unordered_set<int> set;
  int N;
  int temp;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    set.insert(temp);
  }
  cout << set.size() << endl;
}