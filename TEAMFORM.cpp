#include<stdio.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,m ;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++){
            int temp1;
            scanf("%d %d", &temp1, &temp1);
        }
        if((n-2*m)%2 == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
