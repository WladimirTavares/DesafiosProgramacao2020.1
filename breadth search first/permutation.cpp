#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef vector <int> vi;
vi arr;

vi reverse(vi v, int start, int end){

	vi result(v);
	
	for(int i = start, j = end; i < j; i++,j--){
		swap(result[i], result[j]);
	}
	
	return result;
	

}

void print(vi v){
	for(int i = 0; i < (int)v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

bool increasing(vi v){

	for(int i = 1; i < (int)v.size(); i++){
		if( v[i-1] > v[i]) return false;
	}
	
	return true;
}

int main(){

	int n;
	cin >> n;
	
	arr.resize(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}	
	
	queue < vi > q;
	map <vi, int> dist;
		
	q.push( arr );
	dist[arr] = 0;
	int ans = -1;
	
	while( !q.empty() ){
		
		vi v = q.front();
		q.pop();
		
		if( increasing(v) ){
			ans = dist[v];
			break;
		}
		
		
		for(int i = 1; i < n; i++){
			vi u = reverse(v, 0, i);
			
			if( dist.count(u) == 0){
				//cout << "vizinhos: ";
				//print(u);
				//cout << "------" << endl;
				
				dist[u] = dist[v] + 1;
				q.push(u);
			}
			
		
		}
		
		
	
	}
	
	cout << ans << endl;
		
	
	
	
	

}
