#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;


int main(){
    long t;
    scanf("%ld", &t);
    while(t--){
        bool correct = true;
        char str[100005];
        bzero(str, 100005);
        scanf("%s", str);
        int l = strlen(str);
        bool c, e, s;
        c = false;
        e = false;
        s = false;
        for(int i=0; i<l; i++){
            if(str[i] == 'C'){
                if(s or e){
                    correct = false;
                    break;
                }
                c = true;
            }else if(str[i] == 'E'){
                if(s) {
                    correct = false;
                    break;
                }
                e = true;
            }else if(str[i] == 'S'){
                s=true;
            }
        }
        if(correct)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
