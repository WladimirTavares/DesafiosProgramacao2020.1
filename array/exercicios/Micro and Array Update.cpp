#include <bits/stdc++.h>
#define ALL(v) (v).begin(),(v).end() 

using namespace std;



int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        int max_dif;
        cin >> n >> k;
        vector<int> ar(n);
        max_dif = 0;
        for(int ar_i = 0; ar_i < n; ar_i++){
           cin >> ar[ar_i];
           int dif =  k - ar[ar_i];
           max_dif = max( max_dif, dif);
        }
        cout << max_dif << endl;
        
    }
    return 0;
}

