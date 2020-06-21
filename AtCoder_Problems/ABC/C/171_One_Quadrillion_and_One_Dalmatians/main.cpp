#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int64_t n, len_ans = 0;
  vector<char> ans;

  cin >> n;
  while (n != 0)
  {
    ans.push_back((char)('a' + ((n - 1) % 26)));
    n = (n - 1) / 26;
    len_ans++;
  }
  for (int i = 0; i < len_ans; i++)
    cout << ans[len_ans - 1 - i];
  cout << endl;
}