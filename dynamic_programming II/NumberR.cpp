#include <bits/stdc++.h>
using namespace std;


int main(){
	int T;
	
	cin >> T;
	
	while(T--){
		string s;
		int N;
		
		cin >> s;
		
		N = s.size();
		
		int maxseq = 0;
		int atual = 0;
		int contR = 0;
		for(int i = 0; i < N; i++){
			if( s[i] == 'R'){
				atual--;
				contR++;
			}else{
				atual++;
			}
			
			maxseq = max( maxseq, atual);
			if( atual < 0)
				atual = 0;
			
		}
		
		if(maxseq == 0) contR--;
		
		cout << maxseq + contR << endl;
		
		
		
		
		
	}
}
