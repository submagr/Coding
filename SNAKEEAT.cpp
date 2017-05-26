#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

long findSuccessor(long long int *ar, long n, long long int key){
    if(n==1){
        return (key <= ar[0])?0:-1;
    }
    long midIndex = (n+1)/2 - 1;
    if(key <= ar[midIndex])
        return findSuccessor(ar, midIndex+1, key);
    else if(ar[midIndex] < key and key <= ar[midIndex+1])
        return midIndex+1;
    else if(ar[midIndex+1] < key){
        long temp=findSuccessor(ar+midIndex+1, n-midIndex-1, key);
        return (temp>=0)?(midIndex+temp+1):-1;
    }
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long n,q;
        scanf("%ld %ld", &n, &q);
        long long int ar[n];
        for(int i=0; i<n; i++){
            scanf("%lld", &ar[i]);
        }
        if(q>0) // Sort array
            sort(ar, ar+n);
        for(int i=0; i<q; i++){
            long long int key;
            scanf("%lld", &key);
            long sucIndex = findSuccessor(ar, n, key);
            if(sucIndex == -1){
                printf("0\n");
                continue;
            }

            long reqSnakes = n-sucIndex;
            sucIndex -= 1;
            if(sucIndex>0){
                long eatIndex = 0; 
                while(sucIndex>eatIndex){
                    eatIndex += key - ar[sucIndex] ;
                    if(sucIndex>eatIndex){
                        reqSnakes += 1;  
                        sucIndex -= 1; 
                    }else{
                        break;
                    }
                }
                printf("%ld\n", reqSnakes); 
            }
        }
    }
    return 0;
}
