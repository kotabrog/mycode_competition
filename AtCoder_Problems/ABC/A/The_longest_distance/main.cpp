#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  vector<double> x(100), y(100);
  double max = 0;
  double l;

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> x[i] >> y[i];
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      l = sqrt(pow(abs(x[i] - x[j]), 2.0) + pow(abs(y[i] - y[j]), 2.0));
      if (max < l)
        max = l;
    }
  }
  cout << max << endl;
}