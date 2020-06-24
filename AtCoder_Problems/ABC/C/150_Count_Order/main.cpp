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

bool vect_equal(vector<int> a, vector<int> b, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (a[i] != b[i])
      return (false);
  }
  return (true);
}

int main()
{
  int n, p_num, q_num;
  vector<int> p(8), q(8);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> q[i];
  vector<int> v(n);
  int i = 1;
  for (int j = 1; j <= n; j++)
    v[j-1] = j;
  do {
      if (vect_equal(v, p, n))
        p_num = i;
      if (vect_equal(v, q, n))
        q_num = i;
    i++;
  } while(next_permutation(v.begin(), v.end()));
  cout << abs(p_num - q_num) << endl;
}