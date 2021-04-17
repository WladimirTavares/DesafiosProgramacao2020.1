#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1e5 + 1 ;

typedef struct{
	int even, odd;
} node; 


node tree[2*MAXN];
int arr[2*MAXN];

node merge( node a, node b){
	node res;
	res.even = a.even + b.even;
	res.odd  = a.odd + b.odd;
	return res;
}


void build(int* arr, int n)  {  
	for (int i=0; i<n; i++){     
		if(arr[i]%2 == 0){
			tree[n+i].even  = 1;
		  tree[n+i].odd   = 0;
		}else{
			tree[n+i].even  = 0;
		  tree[n+i].odd   = 1;
		}
	}
		
	for (int i = n - 1; i > 0; --i){      
		tree[i] = merge ( tree[i<<1] , tree[i<<1 | 1] );     
	}
} 


// function to update a tree node 
void updateTreeNode(int p, int v, int n)  
{   
	if(v%2==0){
		tree[p+n].even = 1;
		tree[p+n].odd  = 0;
	}else{
		tree[p+n].even = 0;
		tree[p+n].odd  = 1;
	}
	
	p = p+n;     
	for (int i=p; i > 1; i >>= 1){ 
		tree[i>>1] = merge ( tree[i], tree[i^1] ); 
	}
} 


node query(int l, int r, int n)  {  
	
	node ans;
	ans.even = 0;
	ans.odd  = 0;
			
	// loop to find the sum in the range 
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
	{ 
		if (l&1){
			ans = merge ( ans , tree[l++]);
			 
		}
		if (r&1){
			ans = merge ( ans , tree[--r]); 
		}
	} 
		
	return ans; 
} 

int main(){
	int n, q;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		arr[i] = arr[i]%2;
	}
	build(arr, n);
	
	scanf("%d", &q);
	
	for(int i = 0; i < q; i++){
		int op, l, r;
		scanf("%d %d %d", &op, &l, &r);
		
		if(op==0){
			l--;
			updateTreeNode(l, r, n);
			
		}else if(op==1){
			l--;
			node ans = query(l, r, n);
			printf("%d\n", ans.even);
		}else if(op==2){
			l--;
			node ans = query(l, r, n);
			printf("%d\n", ans.odd);
		}
		
		
	}
	
	
	
}
	
	
	
