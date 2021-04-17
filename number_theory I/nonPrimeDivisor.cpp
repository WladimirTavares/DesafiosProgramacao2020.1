#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> getFactorization(ll x)
{
ll count = 0;
vector<ll> v;
count = floor(log2(x&(~(x-1))));
x /= (x&(~(x-1)));
if (count != 0)
v.push_back(count);

// Loop to find the divisors of the
// given number upto SQRT(N)
for (ll i = 3; i <= sqrt(x); i += 2) {
count = 0;
while (x % i == 0) {
count++;
x /= i;
}
if (count != 0)
v.push_back(count);
}
// Condition to check if the rest
// number is also a prime number
if (x > 1) {
v.push_back(1);
}
return v;
}

ll nonPrimeDivisors(ll N)
{
vector<ll> v = getFactorization(N);
ll ret = 1;
// Loop to count the number of
// the total divisors of given number
for (ll i = 0; i < v.size(); i++)
ret = ret * (v[i] + 1);

ret = ret - v.size();
return ret;
}

int main()
{
fast;
ll T,n;
cin>>T;
while(T--)
{
cin>>n;
if(n==1)
cout<<"1\n";
else
cout<<nonPrimeDivisors(n)<<"\n";
}

return 0;
}
