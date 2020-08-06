#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	bool sq[2001] = {false};
	for(int i = 1; i*i < 2001; i++){
		if(i*i < 2001)   sq[i*i] = true;
		if(i*i*i < 2001) sq[i*i*i] = true;
	}
	
	int T;
	int N;
	
	cin >> T;
	
	while(T--){
		cin >> N;
		
		unordered_map <ll, ll> number;
	
		for(int i = 0; i < N; i++){
			ll x;
			cin >> x;
			number[x]++;
		}
		
		vector <ll> a;
		for(auto it : number){
			a.push_back(it.first);
		}
		
		ll cont = 0LL;
		
		for(int i = 0; i < a.size(); i++){
			ll f = number[a[i]];
			
			if( f > 1 && sq[2*a[i]] ){
				cont += (f*(f-1))/2;
			}
		
			for(int j = i+1; j < a.size(); j++){
				if( sq[ a[i] + a[j] ] ){
					cont += f*number[a[j]];
				}
			}
		
		}
		
		cout << cont << endl;
			
		
	}
	
	

}


//1 1 2 2 3 5

//1=> 2
//2=> 2
//3=> 1
//5=> 1

//(1,3),(1,3),(3,5)
//(2,2)

//2=>6
//6*5
//(2,2)


 
