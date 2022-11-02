#include<stdio.h>
#include<string.h>

int main(){
	int n, min, c;
	long long int a[100005], genap, ganjil;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &a[i]);		
	}
	genap = 0, ganjil = 0, c = 0;
	min = 100000;
	for(int j=0;j<n;j++){
		if(a[j]%2 == 0){
			genap += a[j];
		}else if(a[j]%2 != 0){
			ganjil += a[j];
			if(a[j] < min){
				min = a[j];
			}
			c++;
		}
	}
	if(c%2 == 0){
		printf("%lld\n", genap+ganjil);
	}else if(c%2 != 0){
		printf("%lld\n", genap+ganjil-min);
	}
	return 0;
}
