#include<stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int x = n%8;
		if(x >= 1 && x<= 3){
			if(x%3 == 1)
				printf("%dLB\n", n+3);
			if(x%3 == 2)
				printf("%dMB\n", n+3);
			if(x%3 == 0)
				printf("%dUB\n", n+3);
		}else if(x>=4 && x<=6){
			if(x%3 == 1)
				printf("%dLB\n", n-3);
			if(x%3 == 2)
				printf("%dMB\n", n-3);
			if(x%3 == 0)
				printf("%dUB\n", n-3);
		}else if(x==7){
			printf("%dSU\n", n+1);
		}else{
			printf("%dSL\n", n-1);
		}
	}
	return 0;
}
