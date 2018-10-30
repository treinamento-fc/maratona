#include <stdio.h>

int main(){
	int x,y,div;
	
	do{
		scanf("%d %d",&x,&y);
		div=(y/(y-x));
		if( x!=y/2  )
			div++;
		printf("%d\n",div);
	}while(1);
}
