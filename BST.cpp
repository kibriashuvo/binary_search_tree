#include <stdio.h>

class Node{
public:
	int value;
	Node* left;
	Node* right;
};

class BST{
public:
	Node* root;
	
	void init(){
		root = NULL;
	}
	//----------------Insertion----------------------
	void insert(int value){
		
		Node* newNode = new Node;
		
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;

		if (root == NULL){
			root = newNode;
		}
		else{
			addNode(newNode, root);
		}
	}

	void addNode(Node* curr, Node* root){
		if (curr->value < root->value){
			if (root->left == NULL){
				root->left = curr;
			}
			else{
				addNode(curr, root->left);
			}
		}
		else{
			if (root->right == NULL){
				root->right = curr;
			}
			else{
				addNode(curr, root->right);
			}
		}
	}
//-------------Printing-----------------------
	void Print(Node* curr){
		if (curr == NULL){
			return;
		}
		Print(curr->left);
		printf("%d   ", curr->value);
		Print(curr->right);
	}

	void printList(){
		Print(root);
	}



//------------------Deletion------------------------------------
		
	void deleteNode(Node*& root){				// This Function deletes the Matching Node which is passed by reference
		
		int data;
		Node* temp;
		temp = root;
		
		if (root->left == NULL){
			root = root->right;
			delete(temp);
		}
		else if (root->right == NULL){
			root = root->left;
			delete(temp);
		}
		else{
			getMax(root->left, data);			//Find The max Number in ""LEFT"" Sub-Tree
			root->value = data;					//Replace the data of the passed Node with the max value
			delHelper(root->left, data);		//Recursive call to the helper fuction
		}
	}

	void deletePublic(int key){					// This Function is called at main
		delHelper(root, key);					//Helper Function call
	}

	void delHelper(Node*& root, int key){		//Helper Fuction
		if (root == NULL){
			printf("Not found");
			return;
		}
		else if (key < root->value)
			delHelper(root->left, key);
		else if (key > root->value)
			delHelper(root->right, key);
		else
			deleteNode(root);
	}

	void getMax(Node* root, int& data){
		while (root->right != NULL)
			root = root->right;
		data = root->value;
	}


//-------------------Searching----------------------
	bool searchNodeHelper(Node* root,int value){
		
		if (root == NULL){
			return false;
		}
		else if (value < root->value){
			searchNodeHelper(root->left, value);
		}
		else if (value > root->value){
			searchNodeHelper(root->right, value);
		}
		else{
			return true;
		}
		
	}

	bool searchNode(int key){
		
		return searchNodeHelper(root, key);
		
	}

};

int main(){
	BST b;
	b.init();
	int input;
	int option;
	
	while (true){
		printf("\n\n\n================================================\n");
		printf("  ------------------WELCOME---------------------\n");
		printf("  -------------Binary Search Tree---------------\n");
		printf("================================================\n");
		printf("\n1. Press 1 to insert a Number\n");
		printf("\n2. Press 2 to delete a Number\n");
		printf("\n3. Press 3 to search a Number\n");
		printf("\n4. Press 0 to exit\n\n");

		
		printf("\nEnter your choice:");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			{
				while (true)
				{
					printf("\n\n--------------------Insertion---------------------- \n\nPress '-1' to exit");
					printf("\n\nEnter the Insertion number:");
					scanf("%d", &input);
					if (input == -1)
						break;
					b.insert(input);
					printf("\n\nTree:  ");
					b.printList();

				}
				break;
			}

		case 2:
			{
				while (true)
				{
					printf("\n\n-------------------Deletion--------------------\n\nPress '-1' to exit\n\n\n");
					b.printList();
					printf("\n\nEnter the Deletion number:");
					scanf("%d", &input);
					if (input == -1)
						break;
					else if (b.root == NULL){
						printf("\n\nList is Empty!!!!!!!!\n\n");
						break;
					}
					b.deletePublic(input);
					printf("\n");


				}
				break;
			}
		case 3:
		{
			while (true)
			{
				printf("\n\n-------------------Search--------------------\n\nPress '-1' to exit\n\n\n");
				
				printf("\n\nEnter the Search Key:");
				scanf("%d", &input);
				if (input == -1)
					break;
				
				bool found = b.searchNode(input);
				
				if (found)
					printf("\nFound!!");
				else
					printf("Not Found!!");
				printf("\n");

				b.printList();


			}
			break;
		}


		case 0:
			return 0;
				
		default:{
			printf("\nPlease Enter a Valid choice\n");
			break;
		}
		}
	}
	 
		           

		
	

	



}