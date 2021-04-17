#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1e5 + 1 ;

typedef struct{
	int left, right;
} node; 



node tree[2*MAXN];
int arr[2*MAXN];


node merge( node a, node b){
	node res;
	if( a.left != -1)
		res.left = a.left;
	else
		res.left = b.left;
	
	if(b.right != -1){
		res.right = b.right;
	}else{
		res.right = a.right;
	}
	return res;
}

void printNode(int idx, node a){
	printf("tree[%d] = (%d,%d)\n", idx, a.left, a.right );
}

void build(int* arr, int n)  {  
	for (int i=0; i<n; i++){     
		if(arr[i] == 0){
			tree[n+i].left  = -1;
			tree[n+i].right = -1;
		}else{
			tree[n+i].left  = i;
			tree[n+i].right = i;
		}
		
		//printNode(n+i, tree[n+i]);
	}
		
	for (int i = n - 1; i > 0; --i){      
		tree[i] = merge ( tree[i<<1] , tree[i<<1 | 1] );     
		//printNode(n+i, tree[n+i]);
	}
} 


// function to update a tree node 
void updateTreeNode(int p, int n)  
{   
	if(arr[p] == 1) return ;
	arr[p] = 1;
	tree[p+n].left = p;
	tree[p+n].right  = p;
	//printNode(p+n, tree[p+n]);
	 
	p = p+n;     
	for (int i=p; i > 1; i >>= 1){ 
		tree[i>>1] = merge ( tree[i], tree[i^1] ); 
		//printNode(i>>1, tree[i>>1]);
	}
} 


node query(int l, int r, int n)  {  
	
	node ans;
	ans.left = -1;
	ans.right = -1;
			
	// loop to find the sum in the range 
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
	{ 
		//printf("l %d r %d\n", l, r);
		if (l&1){
			//printNode(l, tree[l]);
			ans = merge ( ans , tree[l++]);
			 
		}
		if (r&1){
			//printNode(r-1, tree[r-1]);
			ans = merge ( ans , tree[--r]); 
		}
	} 
		
	return ans; 
} 

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	build(arr, n);
	
	for(int i = 0; i < q; i++){
		int op, idx;
		scanf("%d %d", &op, &idx);
		
		
		if(op==0){
			node a = query(0, idx, n);
			node b = query(idx+1, n, n);
			//printNode(0, a);
			//printNode(0, b);
			
			printf("%d %d\n", a.right, b.left);
			
			
		}else{
			updateTreeNode(idx, n);
		}
	}
	
	
	
}
	
	
	
