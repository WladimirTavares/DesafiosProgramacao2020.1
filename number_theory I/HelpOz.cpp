#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[101];

int main(){
	int M;
	
	cin >> M;
	
	for(int i = 0; i < M; i++){
		cin >> arr[i];
	}
	
	int d = abs( arr[0] - arr[1] );
	
	for(int k = 2; k <= d; k++){
		if( d%k == 0){
			map <int,int> resto;			
			for(int i = 0; i < M; i++){
				resto[ arr[i]%k ]++;
			}
			
			if(resto.size() == 1){
				cout << k << " ";
			}
		}
	}
	
	

}
