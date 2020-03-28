#include <bits/stdc++.h>
using namespace std;

int main()
{
  int X, Y, A, B, C, tmp, r_count = 0, flag;
  int64_t ans = 0;
  priority_queue<int> p;
  priority_queue<int> q;
  priority_queue<int> r;

  cin >> X >> Y >> A >> B >> C;
  for (int i = 0; i < A; i++)
  {
    cin >> tmp;
    p.push(tmp);
  }
  for (int i = 0; i < B; i++)
  {
    cin >> tmp;
    q.push(tmp);
  }
  for (int i = 0; i < C; i++)
  {
    cin >> tmp;
    r.push(tmp);
  }
  while (r_count < X + Y)
  {
    if (X == 0)
    {
      if (r.empty())
        flag = 2;
      else
      {
        if (r.top() > q.top())
          flag = 3;
        else
          flag = 2;
      }
    }
    else if (Y == 0)
    {
      if (r.empty())
        flag = 1;
      else
      {
        if (r.top() > p.top())
          flag = 3;
        else
          flag = 1;
      }
    }
    else
    {
      if (r.empty())
      {
        if (p.top() > q.top())
          flag = 1;
        else
          flag = 2;
      }
      else
      {
        if (p.top() >= q.top() && p.top() >= r.top())
          flag = 1;
        else if (q.top() >= p.top() && q.top() >= r.top())
          flag = 2;
        else
          flag = 3;
      }
    }
    if (flag == 1)
    {
      ans += p.top();
      p.pop();
      X--;
    }
    else if (flag == 2)
    {
      ans += q.top();
      q.pop();
      Y--;
    }
    else
    {
      ans += r.top();
      r.pop();
      r_count++;
    }
    flag = 0;
  }
  cout << ans << endl;
}