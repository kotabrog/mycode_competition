#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int a,int b){return (int64_t)a*b/gcd(a, b);}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応
bool is_prime(int a){if(a<=1)return false;for(int i=2;(int64_t)i*i<=a;i++){if(a%i==0)return false;}return true;}

//順列の全列挙
// vector<int> v(N);
// iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
// do {
//   for(auto x : v) cout << x << " "; cout << "\n";    // v の要素を表示
// } while( next_permutation(v.begin(), v.end()) ); 

int main()
{
  int n, m, p, ac_count = 0, wa_count = 0;
  vector<bool> ac(100000, false);
  vector<int> wa(100000, 0);
  string s;

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> p >> s;
    if (s == "AC")
    {
      if (!ac[p - 1])
      {
        ac_count++;
        ac[p - 1] = true;
      }
    }
    else
    {
      if (!ac[p - 1])
        wa[p - 1]++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (ac[i])
      wa_count += wa[i];
  }
  cout << ac_count << " " << wa_count << endl;
}