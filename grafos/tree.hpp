
struct node{
	int info;
	node *left;
	node *right;
};

node* create(int info, node *n){
	if(n==NULL){
		n= new node();
		n->info = info;
		n->left = NULL;
		n->right=NULL;
		return n;
	}
	
	if(n->info >= info){
		return n->left=create(info, n->left);
		
	}
	else{
		return n->right=create(info, n->right);

	}
}
