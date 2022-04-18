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
		void Insertar(int n);
		bool Buscar(int n);
		void Borrar(int n);
		void preorden(void);
		void inorden(void);
		void posorden(void);
};

void BorrarN(Node *&nodo);
void Preorden(Node *root);
void Inorden(Node *root);
void Posorden(Node *root);
