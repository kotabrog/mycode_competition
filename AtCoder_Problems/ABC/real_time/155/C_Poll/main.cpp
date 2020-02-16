#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  map<string, int> strings;
  priority_queue<string, vector<string>, greater<string>> pq;
  string s;
  int max_n = 0;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> s;
    if (strings.count(s))
      strings[s]++;
    else
      strings[s] = 1;
    if (max_n < strings[s])
      max_n++;
  }

  for (auto p : strings)
  {
    auto k = p.first;
    auto v = p.second;
    if (v == max_n)
      pq.push(k);
  }
   while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
}