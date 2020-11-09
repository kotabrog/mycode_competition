#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int64_t gcd(int64_t a,int64_t b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int64_t a,int64_t b){return a/gcd(a, b)*b;}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応
bool is_prime(int64_t a){if(a<=1)return false;for(int64_t i=2;(int64_t)i*i<=a;i++){if(a%i==0)return false;}return true;}
int get_adp(double x, int n){return (int)round((x-(int)x)*pow(10,n))%10;} // 小数点以下の指定桁の値を取得
int64_t sigma(int64_t s, int64_t n){return n*(2*s+n-1)/2;}

//順列の全列挙
// vector<int> v(N);
// iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
// do {
//	for(auto x : v) cout << x << " "; cout << "\n";     // v の要素を表示
// } while( next_permutation(v.begin(), v.end()) ); 

//bit全探索
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//	bitset<ビット数> s(tmp);
//	// (ビット列sに対する処理)
// }

int n, a_n = 0;
vector<int> a(100);

void f(int index, int sum_n, int count, int *ans)
{
	int i;
	if (index == -1)
	{
		*ans = min(*ans, count + n - sum_n);
		return ;
	}
	i = (n - sum_n) / a[index];
	while (i >= 0)
	{
		if (*ans < count + i)
			break ;
		// cout << count << endl;
		f(index - 1, sum_n + i * a[index], count + i, ans);
		i--;
	}
}

int main()
{
	int ans = 100000;

	cin >> n;
	for (int i = 6; i <= n; i*=6)
		a[a_n++] = i;
	for (int i = 9; i <= n; i*=9)
		a[a_n++] = i;
	sort(a.begin(), a.begin() + a_n);
	f(a_n - 1, 0, 0, &ans);
	cout << ans << endl;
}
