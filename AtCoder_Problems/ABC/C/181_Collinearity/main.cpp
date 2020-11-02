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

int main()
{
	int n;
	vector<vector<int>> xy(100, vector<int> (2));
	vector<vector<int>> temp(2, vector<int> (2));
	bool flag = false;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> xy[i][0] >> xy[i][1];
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				temp[0][0] = xy[i][0] - xy[j][0];
				temp[0][1] = xy[i][1] - xy[j][1];
				temp[1][0] = xy[k][0] - xy[j][0];
				temp[1][1] = xy[k][1] - xy[j][1];
				if (temp[0][0] * temp[1][1] == temp[1][0] * temp[0][1])
				{
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			break;
	}
	cout << (flag ? "Yes" : "No") << endl;
}
