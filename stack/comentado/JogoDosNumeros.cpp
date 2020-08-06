#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(){
	
	int N;
	vector <ll> A;
	vector <ll> nextGreater;
	stack <int> pilhaMaior;
	vector <ll> nextSmaller;
	stack <int> pilhaMenor;
	
	cin >> N;
	
	A.resize(N);
	nextGreater.resize(N);
	nextSmaller.resize(N);
		
	for(int i = 0; i < N; i++)
		cin >> A[i];
			
	pilhaMaior.push(0);
	for(int i = 1; i < N; i++){
		while( !pilhaMaior.empty() ){
			int j = pilhaMaior.top();
			if( A[i] > A[j]){
				//printf("%lld -> %lld\n", A[j] , A[i]);
				nextGreater[j] = i;
				pilhaMaior.pop();
			}else{
				break;
			}
		}	
		pilhaMaior.push(i);
	}
	
	while( !pilhaMaior.empty() ) {
		int j = pilhaMaior.top();
		//printf("%lld -> -1\n", A[j] );
		nextGreater[j] = -1;
		pilhaMaior.pop();
	}	
	
	//printf("NextSmaller\n");
	
	pilhaMenor.push(0);
	for(int i = 1; i < N; i++){
		while( !pilhaMenor.empty() ){
			int j = pilhaMenor.top();
			if( A[i] < A[j]){
				//printf("%lld -> %lld\n", A[j] , A[i]);
				nextSmaller[j] = i;
				pilhaMenor.pop();
			}else{
				break;
			}
		}	
		pilhaMenor.push(i);
	}
	
	while( !pilhaMenor.empty() ) {
		int j = pilhaMenor.top();
		//printf("%lld -> -1\n", A[j] );
		nextSmaller[j] = -1;
		pilhaMenor.pop();
	}	
	
	for(int i = 0; i < N; i++){
		int index = nextGreater[i];
		
		if(index != -1 ){
			index = nextSmaller[index];
			if( index != -1 ){
				cout << A[index] << " ";
			}else{
				cout << -1 << " ";
			}
			
		}else{
			cout << -1 << " ";
		}
	}
	
	cout << endl;

}
