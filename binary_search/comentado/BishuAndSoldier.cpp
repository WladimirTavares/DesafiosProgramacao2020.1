#include <bits/stdc++.h>
#define ALL(c) c.begin(), c.end()


using namespace std;


int main(){
	int N;
	vector <int> v;
	vector <int> sum;
	int Q, x;
	
	cin >> N;
	v.resize(N);
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	sort( ALL(v) );
	sum.resize(N);
	for(int i = 0; i < N; i++){
		if( i == 0 ) sum[i] = v[i];
		else sum[i] = sum[i-1] + v[i];
	}
	
	cin >> Q;
	
	for(int i = 0; i < Q; i++){
		cin >> x;
		vector<int>::iterator up;
		up = upper_bound ( ALL(v), x); // devolve o primeiro maior  
		int index = up - v.begin();
		//printf("index %d\n", index );
		if( index == N ){ 
			cout << index << " " << sum[N-1] << endl;
		}else{
			if(index == 0 ) 
				cout << 0 << " " << 0 << endl;
			else
				cout << index << " " << sum[index-1] << endl;	
		}
		
		
	}
	
		
	
	

}
