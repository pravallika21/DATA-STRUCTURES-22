#include <iostream>
using namespace std;
#define MAX 20

struct node
{
	char data; // either alphabet or operator
	struct node *left, *right;
};

class ExprADT
{
	char input[MAX];
	public:
		ExprADT()
		{
			cout<<"Enter input expression (i.e., postfix):";
			cin>>input;
		}
		struct node * buildExpressionTree(struct node *);
		void inorder(struct node *);
		void postorder(struct node *);
		void preorder(struct node *);
		void printTree(struct node *,int);
};

struct node * ExprADT :: buildExpressionTree(struct node *t) {

	struct node *stk[MAX];
	int top = 0;
	struct node *temp, *x,*y;

	for(int i=0;input[i]!='\0';i++)
	{
		char ch = input[i];
		if(isalpha(ch) || isdigit(ch))
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = ch;
			temp->left = temp->right = NULL;
			stk[++top] = temp;
		}
		else
		{
			y = stk[top--];
			x = stk[top--];
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = ch;
			temp->left = x;
			temp->right = y;
			stk[++top] = temp;	
		}
	}
	return stk[top--];					
}

void ExprADT :: inorder(struct node *t){
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
}

void ExprADT :: postorder(struct node *t){

	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout<<t->data<<" ";
	}
}

void ExprADT :: preorder(struct node *t){

	if(t!=NULL)
	{
		cout<<t->data<<" ";
		preorder(t->left);
		preorder(t->right);	
	}
}
void ExprADT :: printTree(struct node *t,int level)
{
		if(t!=NULL)
		{
			printTree(t->right, level+1);
			for(int i=0;i<level;i++)
				cout<<"  ";
			cout<<t->data<<"\n";
			printTree(t->left, level+1);
		}			
}

int main()
{
	ExprADT obj;
	struct node *root = NULL;

	root = obj.buildExpressionTree(root);
	cout<<"\n Inorder...\n";
	obj.inorder(root);
	cout<<"\n Preorder...\n";
	obj.preorder(root);
	cout<<"\n Postorder...\n";
	obj.postorder(root);
	cout<<"\n The expression tree structure is....\n\n";
	obj.printTree(root,1);
	
	return 0;
}
