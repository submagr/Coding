#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<int> ar(2*n);
        for(int i=0; i<2*n; i++){
            int temp;
            scanf("%d", &temp);
            ar[i] = temp;
        }
        sort(ar.begin(), ar.end());
        cout << ar[(3*n-1)/2] << endl;
        for(int i=0; i<n; i++){
            cout << ar[i] << " " << ar[n+i] << " ";
        }
        cout << endl;
    }
    return 0;
}
