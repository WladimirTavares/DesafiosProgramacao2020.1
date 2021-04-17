#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int A[MAXN];


int main(){
	int T;
	
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;
		
		int allNegative = true;
		int maiorValor;
		for(int i = 0; i < N;i++){
			cin >> A[i];
			if( A[i] > 0) allNegative = false;
			if( i == 0) maiorValor = A[i];
			else maiorValor = max( maiorValor, A[i]);
		}
		
		int maxseq = 0;
		int maxsum = 0;
		int atual  = 0;
		
		
		for(int i = 0; i < N;i++){
			if( A[i] > 0 ) maxsum = max( maxsum, maxsum + A[i]);
			
			atual += A[i];
			
			if(atual < 0){
				atual = 0;
			}
			
			maxseq = max( maxseq, atual );
			//printf("maxseq %d maxsum %d\n", maxseq, maxsum);
		}
		
		if(allNegative)
			printf("%d %d\n", maiorValor, maiorValor);
		else
			printf("%d %d\n", maxseq, maxsum );
		
	}
	
	



}
