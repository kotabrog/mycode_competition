#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, v;
  double a, b;
  priority_queue<double, vector<double>, greater<double>> pq;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> v;
    pq.push(v);
  }
  for (int i = 0; i < n - 1; i++)
  {
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    pq.push((a + b) / 2);
  }
  cout << fixed << setprecision(5) << pq.top() << endl;
}