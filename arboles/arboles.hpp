#include <iostream>


//using namespace std;
struct Node{
	int dato;
	Node* izq;
	Node* der;
};

class Tree{
	private:
		Node *root;

	public:
		Tree(Node *r);
		//Node* ClearNode(int n);
		//void InsertarNode(int n);
		void preorden(void);
		void inorden(void);
		void posorden(void);
};


void CrearNode(Node *&a,int n);
void InsertarNode(Node *&a, int n);
void Preorden(Node *root);
void Inorden(Node *root);
void Posorden(Node *root);
