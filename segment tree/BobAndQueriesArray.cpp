#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 5e5 + 1 ;



int tree[2*MAXN] = {0};
int arr[2*MAXN] = {0};



// function to update a tree node 
void updateTreeNode1(int n, int p)  
{   
	arr[p]++;
	tree[p+n]++;
	 
	p = p+n;     
	for (int i=p; i > 1; i >>= 1) 
		tree[i>>1] = tree[i] + tree[i^1]; 
	
} 


// function to update a tree node 
void updateTreeNode2(int n, int p)  
{  
	if(arr[p] == 0) return;
	
	arr[p]--;
	tree[p+n]--;
	p = p+n;     
	for (int i=p; i > 1; i >>= 1) 
		tree[i>>1] = tree[i] + tree[i^1]; 
}
	
	



  
int query(int n, int l, int r)  {  
	
	int ans = 0;
			
	// loop to find the sum in the range 
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
	{ 
		//printf("l %d r %d\n", l, r);
		if (l&1){
			ans = ans + tree[l++] ; 
		}
		if (r&1){
			ans = ans + tree[--r] ; 
		}
	} 
		
	return ans; 
} 

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	
	for(int i = 0; i < q; i++){
		int op;
		scanf("%d", &op);
		if(op==1){
			int idx;
			scanf("%d", &idx);
			idx--;
			updateTreeNode1(n, idx);
		}else if(op==2){
			int idx;
			scanf("%d", &idx);
			idx--;
			updateTreeNode2(n, idx);
		}else{
			int l, r;
			scanf("%d %d", &l, &r);
			l--;
			int ans = query(n, l, r);
			printf("%d\n", ans);
		}	
	}
	
	
	
	
	
	
}
	
	
	
