#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int64_t n, ans = 0, q, a, b, c;
  vector<int64_t> map_a(100001, 0);
  vector<int64_t> vec_ans;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    map_a[a]++;
    ans += a;
  }
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> b >> c;
    map_a[c] += map_a[b];
    ans += (c - b) * map_a[b];
    map_a[b] = 0;
    vec_ans.push_back(ans);
  }
  for (int i = 0; i < q; i++)
    cout << vec_ans[i] << endl;
}