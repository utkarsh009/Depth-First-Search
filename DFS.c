#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

struct Node {
	int data;
	struct Node* next;
};

void addEdge (struct Node** head, int dest) {
	while((*head)->next != NULL)
		head = &((*head)->next);
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = dest;
	node->next = NULL;
	(*head)->next = node;
}

void dfsTraversal(int root, struct Node* adjlist[], int visited[]) {	
	if (visited[root] == 1)
		return;
	struct Node** node = &(adjlist[root]);
	visited[root] = 1;
	printf("%d\n", root);
	struct Node** head = &adjlist[root];
	while((*head)->next != NULL)
		head = &((*head)->next);
	if ((*node)->next != NULL)	
		do {
			dfsTraversal((*node)->next->data, adjlist, visited);
			node = &((*node)->next);
		} while(node != head);
	for (int i=0;i<SIZE;i++)
		if (!visited[i])
			dfsTraversal(i,adjlist,visited);
}

int main () {
	struct Node* adjlist[SIZE] = {NULL};
	struct Node** head[SIZE];
	for (int i=0;i<SIZE;i++) {
		adjlist[i] = (struct Node*)malloc(sizeof(struct Node));
		adjlist[i]->data = i;
		adjlist[i]->next = NULL;
	}
	for (int i=0;i<SIZE;i++)
		head[i] = &adjlist[i];
	int visited[SIZE] = {0};
	addEdge(head[5],0);
	addEdge(head[5],2);
	addEdge(head[2],3);
	addEdge(head[3],1);
	addEdge(head[4],0);
	addEdge(head[4],1);
	addEdge(head[0],1);
	dfsTraversal(5,adjlist,visited);
	return 0;
}
	
