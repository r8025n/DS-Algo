#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *left=NULL;
	struct node *right=NULL;
};

struct node *newnode,*root,*temp,*parent;

void insrt(int x){
	newnode=(struct node*)malloc(sizeof(struct node));

	if(root==NULL){
		root=newnode;
		root->data=x;
		printf("THis is the root\n");
	}
	else{
		temp=root;
		newnode->data=x;
		while(temp!=NULL){
			if(x<temp->data){
				printf("going LEFT of %d\n",temp->data);
				parent=temp;
				temp=temp->left;
			}
			else{
				printf("going RIGHT of %d\n",temp->data);
				parent=temp;
				temp=temp->right;
			}
		}

		if(newnode->data<parent->data)
            parent->left=newnode;
		else
            parent->right=newnode;
	}
}



void printTree(struct node *current){
	if(current==NULL)
		return;
	printf("%d ",current->data);
	printTree(current->left);
	printTree(current->right);
}

void deleteNode(){}


int main(){
	int n,x;
	root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insrt(x);
	}

	printTree(root);

	return 0;
}
