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

vector<int> d(10);
int n, dig;

vector<bool> copy_vec(vector<bool> v, int n)
{
	vector<bool> a(n);
	for (int i = 0; i < n; i++)
		a[i] = v[i];
	return (a);
}

bool is_753(int d)
{
	return (d == 7 || d == 5 || d == 3);
}

int func(int index, vector<bool> flag, int flag_sum)
{
	int score = 0;

	if (index == -1)
		return (flag_sum == 3);
	if (flag[4])
	{
		vector<bool> temp = copy_vec(flag, 5);
		temp[3] = false;
		score += func(index - 1, temp, flag_sum);
	}
	flag[4] = false;
	for (int i = 0; i < 3; i++)
	{
		if (flag[3] && d[index] < i * 2 + 3)
			continue ;
		vector<bool> temp = copy_vec(flag, 5);
		if (temp[3] && d[index] > i * 2 + 3)
			temp[3] = false;
		if (!temp[i])
		{
			temp[i] = true;
			score += func(index - 1, temp, flag_sum + 1);
		}
		else
			score += func(index - 1, temp, flag_sum);
	}
	return (score);
}

int main()
{
	int ans;
	
	cin >> n;
	int n_temp = n;
	dig = 0;
	while (n_temp)
	{
		d[dig++] = n_temp % 10;
		n_temp /= 10;
	}
	vector<bool> flag(5, false);
	flag[3] = true;
	flag[4] = true;
	ans = func(dig - 1, flag, 0);
	cout << ans << endl;
}
