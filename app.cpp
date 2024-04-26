#include <bits/stdc++.h>

#define ll long long
#define fri(n) for (ll i = 0; i < n; i++)
#define frj(n) for (ll j = 0; j < n; j++)
using namespace std;

int main()
{

  ll n, cont = 0, num;

  cin >> n;

  fri(n)
  {
    cont = 0;
    cin >> num;

    vector<ll> v(num);

    frj(num)
    {
      cin >> v[j];
    }
    sort(v.begin(), v.end());
    for (ll j = 0; j < num; j++)
    {
      ll temp = count(v.begin(), v.end(),v[j]);
      if (temp > cont )
      {
        cont = temp;
      }
      j += temp -1;
    }
    cout << num - cont << endl;
  }


  return 0;
}
