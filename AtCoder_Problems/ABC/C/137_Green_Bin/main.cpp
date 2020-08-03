#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int a,int b){return (int64_t)a*b/gcd(a, b);}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応
bool is_prime(int a){if(a<=1)return false;for(int i=2;(int64_t)i*i<=a;i++){if(a%i==0)return false;}return true;}
int get_adp(double x, int n){return (int)round((x-(int)x)*pow(10,n))%10;} // 小数点以下の指定桁の値を取得
int64_t sigma(int64_t s, int64_t n){return n*(2*s+n-1)/2;}

//順列の全列挙
// vector<int> v(N);
// iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
// do {
//   for(auto x : v) cout << x << " "; cout << "\n";    // v の要素を表示
// } while( next_permutation(v.begin(), v.end()) ); 

//bit全探索
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//   bitset<ビット数> s(tmp);
//   // (ビット列sに対する処理)
// }

int main()
{
  int n, p = 2;
  string s;
  vector<int> prime_num(26);
  int64_t count = 0, temp;

  n = 0;
  while (n < 26)
  {
    while (!is_prime(p))
      p++;
    prime_num[n] = p;
    n++;
    p++;
  }
  cin >> n;
  vector<int64_t> a(n, 1);
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (int j = 0; j < 10; j++)
      a[i] *= prime_num[(int)(s[j] - 'a')];
  }
  sort(a.begin(), a.end());
  temp = 0;
  for (int i = 1; i < n; i++)
  {
    if (a[temp] != a[i])
    {
      temp = i - temp - 1;
      if (temp > 0)
        count += sigma(1, temp);
      temp = i;
    }
  }
  temp = n - 1 - temp;
  if (temp > 0)
    count += sigma(1, temp);
  // for (int i = 0; i < n; i++)
  //   cout << a[i] << endl;
  cout << count << endl;
}