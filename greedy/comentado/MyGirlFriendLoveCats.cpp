#include <bits/stdc++.h>

#define ALL(c) c.begin(), c.end() 

typedef unsigned long long  ll;
using namespace std;




int main(){
	int n;	
	vector <ll> strenght; //strenght
	vector <ll> calories; //calories

	cin >> n;
	
	strenght.resize(n);
	calories.resize(n);
	for(int i = 0; i < n; i++)
		cin >> strenght[i];
		
	for(int i = 0; i < n; i++)
		cin >> calories[i];
		
	sort( ALL(strenght) );
	sort( ALL(calories) );	
	
	ll sum = 0LL;
	for(int i = 0; i < n; i++){
		//cout << strenght[i] << " " << calories[i] << endl;
		sum += strenght[i]*calories[i];
	}
	
	cout << sum << endl;


}



