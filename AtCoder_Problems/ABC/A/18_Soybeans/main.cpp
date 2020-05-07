#include <bits/stdc++.h>
using namespace std;

void ft_out(int a, int b, int c)
{
  cout << a << '\n' << b << '\n' << c << endl;
}

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b)
  {
    if (c > a)
      ft_out(2, 3, 1);
    else
    {
      if (b > c)
        ft_out(1, 2, 3);
      else
        ft_out(1, 3, 2);
    }
  }
  else
  {
    if(c > b)
      ft_out(3, 2, 1);
    else
    {
      if(a > c)
        ft_out(2, 1, 3);
      else
        ft_out(3, 1, 2);
    }
  }
}
