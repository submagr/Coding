#include<stdio.h>

int main(){
	int t;
	long long n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld", &n, &m);
		if(n%2==0 || m%2==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
