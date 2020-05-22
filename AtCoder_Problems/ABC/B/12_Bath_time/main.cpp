#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  printf("%02d:", n / (60*60));
  printf("%02d:", n /60 % 60);
  printf("%02d\n", n % 60);
}
