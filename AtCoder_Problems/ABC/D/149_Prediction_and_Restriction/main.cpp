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


// r->s->p->r
// r->p->s->r

int	rsp(char c)
{
	if (c == 's')
		return (0);
	if (c == 'p')
		return (1);
	return (2);
}

int main()
{
	int n, k, ans = 0;
	vector<int> rsp_v(3);
	string t;
	char c;
	bool flag;

	cin >> n >> k >> rsp_v[0] >> rsp_v[1] >> rsp_v[2] >> t;
	for (int i = 0; i < k; i++)
	{
		flag = false;
		ans += rsp_v[rsp(t[i])];
		// cout << rsp_v[rsp(t[i])] << " ";
		c = t[i];
		for (int j = 1; j < n / k; j++)
		{
			char temp = t[i + j * k];
			if (flag || c != temp)
			{
				flag = false;
				ans += rsp_v[rsp(temp)];
				// cout << rsp_v[rsp(temp)] << " ";
			}
			else
				flag = true;
			c = temp;
		}
		if (i < n % k)
		{
			char temp = t[i + (n / k) * k];
			if (flag || c != temp)
			{
				flag = false;
				ans += rsp_v[rsp(temp)];
				// cout << rsp_v[rsp(temp)] << ":" << i << " ";
			}
			else
				flag = true;
			c = temp;
		}
	}
	// cout << endl;
	cout << ans << endl;
}

// 6 8 8 7 6