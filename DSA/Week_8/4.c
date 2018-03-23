#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct node{
	int val;
	int cid;
	struct node *next;
};
void add_node(int pid,int cid,int val,struct node *graph[]);
void print_graph(int M,struct node *graph[]);


int main(){
	int M;
	scanf("%d",&M);
	int adj[M][M];
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			scanf(" %d",&adj[i][j]);
		}
	}

	//making the "adj-list" graph O(m^3)
	printf("Building Graph\n");
	struct node *graph[M];
	for(int i=0;i<M;i++){
		graph[i]=NULL;
		for(int j=0;j<M;j++){
			if(adj[i][j]!=0){//0 being our no path pointer
				add_node(i,j,adj[i][j],graph);
			}
		}
	}
	printf("Printing Graph\n");
	print_graph(M,graph);

	//Finding the cycle with negetive gradient loop
	for(int i=0;i<M;i++){
		int visited[M];
		for(int j=0;j<M;j++){
			visited[j]=0;
		}
		visited[i]=1;
	}

	return 0;
}

void add_node(int pid,int cid,int val,struct node *graph[]){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->cid=cid;
	temp->val=val;
	temp->next=NULL;

	struct node *head=graph[pid];
	if(head==NULL){
		graph[pid]=temp;
		return;
	}
	while(head->next!=NULL){//will run at max O(M) for each addn
		head=head->next;
	}
	head->next=temp;
}
void print_graph(int M,struct node *graph[]){
	for(int i=0;i<M;i++){
		struct node *head=graph[i];
		while(head!=NULL){
			printf("%d %d %d\n",i,head->cid,head->val);
			head=head->next;
		}
	}
}

int detect_negetive_cycle(int cost,int pid,int visited[],struct node *graph[]){
	//the cost is cost incurred till now
	struct node *head=graph[pid];
	if(visited[pid]==1){
		
	}
}

