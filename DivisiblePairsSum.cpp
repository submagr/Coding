#include<stdio.h>
int main(){
	int n, k ;
	scanf("%d %d", &n, &k);
	int a[n];
	for(int i = 0; i<n ; i++){
		scanf("%d", &a[i]);
	}
	int count=0;
	for(int i = 0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if((a[i]+a[j])%k == 0){
				count += 1;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
