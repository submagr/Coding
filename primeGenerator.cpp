#include<stdio.h>
using namespace std;

void generatePrimes(long * primes, long n){
	bool isPrime[n];
	for(long i = 0; i<n; i++){
		isPrime[i] = true;
	}
	// isPrimes is a long array where number is (index+1) and value is primes[i]	
	isPrime[0] = false;
	primes[0] = 2;
	long primeCount = 1;
	long checkCount = 2; 

	while(checkCount < n){
		if(!isPrime[checkCount] || (checkCount+1)%2 == 0){
			isPrime[checkCount] = false;
			checkCount+=1;
			continue;
		}
		primes[primeCount] = checkCount+1;
		primeCount+=1;
		long multiplier = 3;
		long factor = (checkCount+1)*multiplier;
		while(factor < (n+1)){
			isPrime[factor-1] = false;
			multiplier+=2;
			factor = (checkCount+1)*multiplier;
		}
		checkCount+=1;
	}
	return;
}

bool isPrime(long *primesList, long length, long key){
	// Binary Search	
	if(length<=0){
		return false;
	}
	long mid = (length)/2 ;
	if(primesList[mid] == key)
		return true;
	else if(primesList[mid] < key)
		return isPrime(primesList+(mid+1), length-mid-1, key);
	else
		return isPrime(primesList, mid, key);
}

int main(){
	long t;
	scanf("%ld", &t);
	long n;
	scanf("%ld", &n);
	long primes[n];
	for(long i=0; i<n; i++){
		primes[i] = 0;
	}
	generatePrimes(primes, n);
	long length = 0;
	for(long i=0; i<n; i++){
		if(primes[i] == 0){
			break;
		}
		length+=1;
	}
	while(t--){
		long check;
		scanf("%ld", &check);
		printf("%d\n", isPrime(primes, length, check));
	}
	return 0;
}
