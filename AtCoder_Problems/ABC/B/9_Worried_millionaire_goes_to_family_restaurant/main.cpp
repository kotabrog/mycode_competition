#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a;
  priority_queue<int> pq;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    pq.push(a);
  }
  a = pq.top();
  while (!pq.empty())
  {
    if (pq.top() < a)
    {
      a = pq.top();
      break;
    }
    else
      pq.pop();
  }
  cout << a << endl;
}
