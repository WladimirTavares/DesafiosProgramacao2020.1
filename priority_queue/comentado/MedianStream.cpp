#include <bits/stdc++.h>

using namespace std;

int N;
int meio;
priority_queue <int, vector <int>, less<int> > q1;
priority_queue <int, vector <int>, greater <int> > q2;
	

int main(){
	
	
	scanf("%d", &N);
	scanf("%d", &meio);
	printf("%d\n", meio);
	for(int i = 1; i <= N-1; i++){
		int x;
		scanf("%d",&x);
		//printf("meio %d\n", meio );
		
		if( x < meio ){
			//printf("adiciona esquerda\n");
			if( q1.size() <= q2.size() ){
				q1.push(x);
			}else{
				q2.push(meio);
				
				if( q1.top() > x){
					meio = q1.top();
					q1.pop();
					q1.push(x);
				}else{
					meio = x;
				}
				
			}
		}else{
			//printf("adiciona direita\n");
			
			if( q1.size() >= q2.size() ){
				q2.push(x);
			}else{
				q1.push(meio);
				
				if( q2.top() < x ){
					meio = q2.top();
					q2.pop();
					q2.push(x);
				}else{
					meio = x;
				}
				
			}
		}
		
		if( q1.size() == q2.size() )
			printf("%d\n", meio);
		else if(q1.size() > q2.size() ){
			int median = (meio + q1.top())/2;
			printf("%d\n", median);
		}else{
			int median = (meio + q2.top())/2;
			printf("%d\n", median);
		}
		
	}
	
	

}
