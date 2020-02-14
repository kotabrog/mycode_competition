#include <bits/stdc++.h>
using namespace std;

int main()
{
  priority_queue<int> a;
  int N;
  int temp;
  int A_sum = 0;
  int B_sum = 0;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    a.push(temp);
  }
  for (int i = 0; i < N / 2; i++)
  {
    A_sum += a.top();
    a.pop();
    B_sum += a.top();
    a.pop();
  }
  if (!a.empty())
    A_sum += a.top();
  cout << A_sum - B_sum << endl;
}