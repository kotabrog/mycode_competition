#include <bits/stdc++.h>
using namespace std;

int main() {
  priority_queue<int64_t> pq;
  
  int N;
  cin >> N;
  int64_t a;
  
  for (int i=0; i < N; i++)
  {
   	cin >> a;
    pq.push(a);
  }
  
  int64_t top;
  top = pq.top();
  
  int count = 0;
  while (pq.top() == top)
  {
   	count++;
    pq.pop();
    if (pq.empty())
      break;
  }
  
  cout << top << " " << count << endl;
}
