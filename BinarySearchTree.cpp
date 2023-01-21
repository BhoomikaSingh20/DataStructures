//Binary Search Tree

#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int val){
			data = val;
			left = NULL;
			right= NULL;
		}
};
//insert values in BST
node* insertBST(node* root, int val){
	if(root==NULL){
		root = new node(val);
		return root;
	}
	if(val<root->data){
		root->left = insertBST(root->left,val);
	}
	else{
		root->right= insertBST(root->right,val);
	}
	return root;
}
//Inorder successor
node* inorderSucc(node*root){
	node* curr = root;
	while(curr && curr->left!=NULL){
		curr = curr->left;
	}
	return curr;
}
//Delete an element from BST
node* deleteBST(node* root, int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data>key){
		root->left = deleteBST(root->left,key);
	}
	else if(root->data<key){
		root->right = deleteBST(root->right,key);
	}
	else{
		if(root->left==NULL){
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			node* temp = root->left;
			free(root);
			return temp;
		}
		else{
			node* temp = inorderSucc(root->right);
			root->data = temp->data;
			root->right= deleteBST(root->right,temp->data);
		}
	}
	return root;
}
//Searching an element in BST
node* searchBST(node* root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		return root;
	}
	else if(root->data>key){
		return searchBST(root->left,key);
	}
	return searchBST(root->right,key);

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
//Level Order Traversal
void level_order(node* root){
	if (root==NULL){
		return;
	}
	queue <node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* curr_node = q.front();
		q.pop();
		if(!curr_node==NULL){
			cout << curr_node->data << " ";
			if(curr_node->left){
				q.push(curr_node->left);
			}
			if(curr_node->right){
				q.push(curr_node->right);
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
	int root_ele;
	cout << "Enter the root of tree: ";
	cin  >> root_ele;
	node* root = new node(root_ele);

	char ch = 'y';
	while(ch=='y' or ch=='Y'){
		cout << "\n***** MENU *****\n";
		cout << "1.Insert an element x\n";
		cout << "2.Delete an element x\n";
		cout << "3.Search an element x and change its value to y and then place it at appropriate position\n";
		cout << "4.Display elements of BST in preorder, postorder and inorder\n";
		cout << "5.Display elements of BST in level-by-level traversal\n";
		cout << "6.Display height of BST\n";
		cout << endl;
		
		int choice;
		cout << "Enter your choice: ";
		cin  >> choice;
		
		if(choice==1){
			int x;
			cout << "Enter the element: ";
			cin  >> x;
			insertBST(root,x);
		}
		else if(choice==2){
			int x;
			cout << "Enter the element: ";
			cin  >> x;
			if(deleteBST!=NULL){
				deleteBST(root,x);
			}
			else{
				cout << "Element doesn't exist!" << endl;
			}
		}
		else if(choice==3){
			int x,y;
			cout << "Enter the element to search: ";
			cin  >> x;
			if(searchBST==NULL){
				cout << "Element doesn't exist:" << endl;
			}
			searchBST(root,x);
			root = deleteBST(root,x);
		
			cout << "Enter the new element to insert: ";
			cin  >> y;
			insertBST(root,y);
		}
		else if(choice==4){
			char ch1 = 'y';
			while(ch1=='y'or ch1=='Y'){
				cout << "\n***** TRAVERSALS *****\n";
				cout << "1.Preorder Traversal\n";
				cout << "2.Postorder Traversal\n";
				cout << "3.Inorder Traversal\n";
				cout << endl;
				
				int choice2;
				cout << "Enter your choice: ";
				cin  >> choice2;
				
				if(choice2==1){
					pre_order(root);
				}
				else if(choice2==2){
					post_order(root);
				}
				else if(choice2==3){
					in_order(root);
				}
				else{
					cout << "Invalid choice!\n";
				}
				cout << "\nWant to continue traversal?(y/n): ";
				cin  >> ch1;
			}
		}
		else if(choice==5){
			cout << "\nLevel-by-Level Traversal\n";
			level_order(root);
		}
		else if(choice==6){
			cout << "\nHeight of Tree is:\n";
			cout << height_tree(root);
			cout << endl;
		}
		else{
			cout << "\nInvalid choice!\n";
		}
		cout << "\nWant to continue?(y/n): ";
		cin  >> ch;
	}
	
	return 0;
}
