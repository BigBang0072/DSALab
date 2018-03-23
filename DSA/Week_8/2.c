#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int M,K;
	scanf("%d %d",&M,&K);
	int adj[M][M];
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			scanf(" %d",&adj[i][j]);
		}
	}
	int c1,c2;//city number is in zero based indexing
	scanf(" %d %d",&c1,&c2);

	
	return 0;
}