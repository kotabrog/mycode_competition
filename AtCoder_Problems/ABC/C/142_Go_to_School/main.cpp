#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, a;
  vector<int> vec(100000);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    vec[a - 1] = i + 1;
  }
  for (int i = 0; i < n; i++)
  {
    cout << vec[i];
    if (i != n - 1)
      cout << ' ';
    else
      cout << endl;
  }
}