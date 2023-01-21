//Binary Tree

#include<iostream>
#include<queue>
using namespace std;
//construct node
class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int val){
			data  = val;
			left  = NULL;
			right = NULL;
		}
};
//preorder traversal
void pre_order(node* root){
	if(root==NULL){
		return;
	}
	cout << root->data << " ";
	pre_order(root->left);
	pre_order(root->right);
}
//postorder traversal
void post_order(node* root){
	if(root==NULL){
		return;
	}
	post_order(root->left);
	post_order(root->right);
	cout << root->data << " ";
}
//inorder traversal
void in_order(node* root){
	if(root==NULL){
		return;
	}
	in_order(root->left);
	cout << root->data << " ";
	in_order(root->right); 
}
//searching an element 'curr' in an inorder set 
int search(int inorder[],int start, int end, int curr)
{
	for(int i=start;i<=end;i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}
//building a tree using preorder and inorder sets
node* pre_buildTree(int preorder[],int inorder[],int start,int end){
	static int index = 0;
	
	if(start>end){
		return NULL;
	}
	
	int curr = preorder[index];
	index++;
	node* curr_node = new node(curr);
	
	if(start==end){
		return curr_node;
	}
	int pos = search(inorder,start,end,curr);
	curr_node->left = pre_buildTree(preorder,inorder,start,pos-1);
	curr_node->right= pre_buildTree(preorder,inorder,pos+1,end);
	
	return curr_node;
}
//building a tree using postorder and inorder sets
node* post_buildTree(int postorder[],int inorder[],int start, int end){
	static int index = end;
	if(start>end){
		return NULL;
	}
	
	int curr = postorder[index];
	index--;
	node* curr_node = new node(curr);
	if(start==end){
		return curr_node;
	}
	
	int pos = search(inorder,start,end,curr);
	curr_node->right = post_buildTree(postorder,inorder,pos+1,end);
	curr_node->left  = post_buildTree(postorder,inorder,start,pos-1);
	
	return curr_node;
}
//Level Order Traversal
void level_order(node* root){
	if (root==NULL){
		return;
	}
	queue <node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* Node = q.front();
		q.pop();
		if(!Node==NULL){
			cout << Node->data << " ";
			if(Node->left){
				q.push(Node->left);
			}
			if(Node->right){
				q.push(Node->right);
			}
		}
		else if(!q.empty()){
			q.push(NULL);
		}
	}
}
//height of binary tree
int height_tree(node* root){
	if(root == NULL){
		return 0;
	}
	int left_height = height_tree(root->left);
	int right_height = height_tree(root->right);
	
	return (max(left_height,right_height)+1);
}

int main(){
//	int postorder[]= {4,2,5,3,1};
//	int preorder[] = {1,2,4,3,5};
//	int inorder[]  = {4,2,1,5,3};
//	
//	cout << "\n***** BUILD TREE USING PRE AND IN-ORDER *****\n"; 
//	node* root1 = pre_buildTree(preorder,inorder,0,4);
//	in_order(root1);
//
//	cout << "\n***** BUILD TREE USING POST AND IN-ORDER *****\n"; 
//	node* root2 = post_buildTree(preorder,inorder,0,4);
//	in_order(root2);
	
	node* root = new node(1);
	
	root->left = new node(2);
	root->right= new node(3);
	
	root->left->left = new node(4);
	root->left->right= new node(5);
	root->right->left= new node(6);
	root->right->right=new node(7);
	
	cout << "\n***** HEIGHT OF TREE *****\n";
	cout << height_tree(root);
	
	cout << "\n***** LEVEL ORDER *****\n";
	level_order(root);
	
	cout << "\n***** PREORDER *****\n";
	pre_order(root);
	cout << "\n***** INORDER *****\n";
	in_order(root);
	cout << "\n***** POSTORDER *****\n";
	post_order(root); 
	
	return 0;
}
