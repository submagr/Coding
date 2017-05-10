#include<iostream>
#include<stdio.h>
#include<climits>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int m = INT_MIN;
        int temp;
        for(int i=0; i<n; i++){
            scanf("%d", &temp);
            if(temp > m){
                m = temp;
            }
        }
        cout << n-m << endl;
    }
}
