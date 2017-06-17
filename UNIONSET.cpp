#include<stdio.h>
#include<strings.h>
using namespace std;

unsigned long long ar[2500][40];

void printBitWise(unsigned long long num){
    for(int i=63; i>=0; i--){
        if(i%8 == 7){
            printf(" ");
        }
        printf("%llu", ((num>>i)&(1ULL)));
    }
    printf("\n");
}

void setBit(int i, int bit){
    int j=bit/64;
    int l=bit%64;
    ar[i][j]=ar[i][j]|(1ULL<<l);
}

bool match(int i, int j, int k){
    for(int l=0; l<k/64+1; l++){
        if((l+1)*64 <= k){ // All bits should be matched
            if((ar[i][l]|ar[j][l]) != 0xffffffffffffffff){
                return false;
            }
        } else { // Not all bits should be matched. 
            unsigned long long mask = (1ULL<<(k-l*64)) - 1;
            if((ar[i][l]|ar[j][l]) != mask){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        bzero(ar, 2500*40*8);
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++){
            int len;
            scanf("%d", &len);
            for(int j=0; j<len; j++){
                int bit;
                scanf("%d", &bit);
                setBit(i, bit-1);
            }
        }

        unsigned long count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(match(i,j,k))
                    count +=1;
            }
        }
        printf("%lu\n", count);
    }
}
