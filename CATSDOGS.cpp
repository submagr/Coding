#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    unsigned long t;
    scanf("%lu", &t);
    while(t--){
        unsigned long c,d,l; 
        scanf("%lu %lu %lu", &c, &d, &l);
        unsigned long long maxLegs, minLegs;
        // Min Legs: All cats on dogs
        if(c <= 2*d){
            minLegs = d*4;
        }else {
            minLegs = (c-d)*4;
        }

        // Max Legs: No cat on dog
        maxLegs = (c+d)*4;

        if (minLegs <= l and l <= maxLegs and l%4 == 0)
        // if(minLegs <= l)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
