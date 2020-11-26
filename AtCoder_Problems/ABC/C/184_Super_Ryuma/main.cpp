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

class point
{
public:
	int64_t x;
	int64_t y;

	bool eq(point a) {return x == a.x && y == a.y;}
	point(int64_t a, int64_t b) : x(a), y(b) {}
	point() {point(0, 0);}
	int64_t sum() {return x + y;}
	int64_t minus() {return x - y;}
};

bool f(point a, point b, int64_t &ans)
{
	++ans;
	if (abs(a.x - b.x) + abs(a.y - b.y) <= 3)
		return true;
	if (a.x + a.y == b.x + b.y || a.x - a.y == b.x - b.y)
		return true;
	if (abs(a.x - b.x) + abs(a.y - b.y) <= 6)
	{
		++ans;
		return true;
	}
	return false;
}

int main()
{
	bool flag = false;
	point p, q;

	int64_t temp, ans = 0;
	cin >> p.x >> p.y >> q.x >> q.y;

	flag = p.eq(q);
	if (!flag)
		flag = f(p, q, ans);
	if (!flag)
		ans = 3;
	temp = abs(p.sum() - q.sum()) / 2;
	if (p.sum() < q.sum())
	{
		point temp_p(p.x + temp, p.y + temp);
		int64_t ans_temp = 1;
		flag = f(q, temp_p, ans_temp);
		if (flag)
			ans = min(ans, ans_temp);
	}
	else
	{
		point temp_q(q.x + temp, q.y + temp);
		int64_t ans_temp = 1;
		flag = f(p, temp_q, ans_temp);
		if (flag)
			ans = min(ans, ans_temp);
	}
	temp = abs(p.minus() - q.minus()) / 2;
	if (p.minus() < q.minus())
	{
		point temp_p(p.x + temp, p.y - temp);
		int64_t ans_temp = 1;
		flag = f(q, temp_p, ans_temp);
		if (flag)
			ans = min(ans, ans_temp);
	}
	else
	{
		point temp_q(q.x + temp, q.y - temp);
		int64_t ans_temp = 1;
		flag = f(p, temp_q, ans_temp);
		if (flag)
			ans = min(ans, ans_temp);
	}
	cout << ans << endl;
}
