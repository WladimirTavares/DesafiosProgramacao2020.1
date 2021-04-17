#include <bits/stdc++.h>
using namespace std;

double derrota[1001];

int main(){

	int T;
	
	cin >> T;
	
	while(T--){
		int R, G;
		cin >> R >> G;
		
		
		derrota[0] = 1.0;
		for(int i = 1; i <= G; i++){
			derrota[i] = derrota[i-1]*(double)(G-i+1)/(G-i+1+R);
			//printf("derrota[%d] = %.15lf\n", i, derrota[i]);
		}
		double res;
		if(R == 0) res = 1.0;
		else if(G == 0) res = 1.0;
		else {
			res = 0.0;
			for(int j = 0; j <= G; j = j + 2){
				res += derrota[j]*(double)(R)/(G+R-j);
				//printf("derrota[%d] = %lf\n", j, derrota[j]);
				//printf("(double)(R)/(G+R-j) %lf\n", (double)(R)/(G+R-j));
			}
		}
		printf("%.6lf\n", res);
		
	}


}
