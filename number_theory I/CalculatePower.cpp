#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll arr[50];

ll gcd(ll a, ll b){
	while(b!=0){
		ll r = a%b;
		a = b;
		b = r;
	}
	return a;
}

ll modularExponentiation(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}



int main(){
	
	ll A, B;
	cin >> A >> B;
	cout << modularExponentiation(A, B, MOD) << endl;
	
	
	
}



