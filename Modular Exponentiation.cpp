#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long res=1;
	long xx=x;
	while(n>0)
	{
		if(n%2==0){
			xx = (xx%m*xx%m)%m;
			n/=2;
		}else{
			(res*=xx)%=m;
			n--;
		}
	}
	return int(res%m);
}
