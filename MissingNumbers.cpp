#include<stdio.h>
int main(){
	int m, n; 
	scanf("%d", &n);
	int a[201];
	for(int i = 0; i< 201; i++){
		a[i] = -100000;
	}
	int st; 
	int temp;
	for(int i =0; i< n; i++){
		scanf("%d", &temp);
		if(i == 0){
			st = temp;
			a[100] = 1;
		}else{
			if(a[100 + temp-st] == -100000){
				a[100+temp-st] = 1;
			}
			else{
				a[100+temp-st] +=1;
			}
		}
	}
	scanf("%d", &m);
	for(int i =0; i< m; i++){
		scanf("%d", &temp);
		if(a[100 + temp-st] == -100000){
			a[100+temp-st] = 0;
		}
		a[100+temp-st] -=1;
	}
	for(int i = 0; i<201; i++){
		if(a[i] != -100000 && a[i] != 0){
			printf("%d ", st+i-100);
		}
	}
	printf("\n");
	return 0;
}
