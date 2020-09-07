#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int64_t gcd(int64_t a,int64_t b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int64_t a,int64_t b){return a/gcd(a, b)*b;}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応
bool is_prime(int a){if(a<=1)return false;for(int i=2;(int64_t)i*i<=a;i++){if(a%i==0)return false;}return true;}
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



int main()
{
	int n;
	vector<int> ng(4);
	bool flag = true;
	cin >> n >> ng[1] >> ng[2] >> ng[3];
	if (n == ng[1] || n == ng[2] || n == ng[3])
		flag = false;
	if (n == 300 && ((ng[1] % 3 == 0 && ng[1] < n)|| (ng[2] % 3 == 0 && ng[2] < n) || (ng[3] % 3 == 0 && ng[3] < n)))
		flag = false;
	if (n == 299)
	{
		int temp = 0;
		for (int i = 1; i < 4; i++)
			if (ng[i] % 3 == 2 && ng[i] < n)
				temp = max(ng[i], temp);
		if (temp != 0)
		{
			for (int i = 1; i < 4; i++)
			{
				if (ng[i] < min(temp, n) && ng[i] % 3 == 0)
				{
					flag = false;
				}
				if (ng[i] == temp + 1)
					flag = false;
			}
		}
	}
	if (n == 298)
	{
		if (max(ng[1], max(ng[2], ng[2])) < n && max(ng[1], max(ng[2], ng[3])) % 3 == 1 && min(ng[1], min(ng[2], ng[3])) % 3 == 0)
		{
			for (int i = 1; i < 4; i++)
			{
				if (ng[i] % 3 == 2)
					flag = false;
			}
		}
	}
	if (ng[1] != ng[2] && ng[1] != ng[3] && ng[2] != ng[3] && max(ng[1], max(ng[2], ng[3])) - min(ng[1], min(ng[2], ng[3])) == 2 && ng[1] < n)
		flag = false;
	cout << (flag ? "YES" : "NO") << endl;
}