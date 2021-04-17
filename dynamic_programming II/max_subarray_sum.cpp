#include <bits/stdc++.h>

using namespace std;


int max_subarray_sum( vector <int> & a){

	int current_sum = a[0];
	int best_sum = a[0];
	
	for(int i = 1; i < (int)a.size(); i++){
		current_sum = max( current_sum + a[i], a[i]);
		best_sum = max( best_sum, current_sum);
	}
	
	return best_sum;

}

int main(){
	int n;
	vector <int> a;
	while( cin >> n && n > 0){
		a.resize(n);	
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		int ans = max_subarray_sum(a);
		if(ans <= 0)
			cout << "Losing streak."  << endl;
		else
			cout << "The maximum winning streak is "<< ans << "." << endl;	
	}

}

