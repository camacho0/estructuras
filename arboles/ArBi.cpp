#include "ArBi.hpp"

using namespace std;

void BorrarN(Node *&nodo){
	Node *actual;
	Node *anterior;
	Node *temp;

	if(nodo==NULL){
		cout<<"el nodo a eliminar es NULL"<<endl;
	}
	else if(nodo->izq==NULL && nodo->der ==NULL){
		temp=nodo;
		nodo=NULL;
		delete temp;
	}
	else if(nodo->izq==NULL){
		temp=nodo;
		nodo=nodo->der;
		delete temp;
	}
	else if(nodo->der==NULL){
		temp=nodo;
		nodo=nodo->izq;
		delete temp;
	}
	else{
		actual=nodo->izq;
		anterior=NULL;
		while(actual->der != NULL){
			anterior=actual;
			actual=actual->der;
		}
		nodo->dato=actual->dato;
		if(anterior==NULL){
			nodo->izq=actual->izq;
		}
		else{
			anterior->der=actual->izq;
		}
		delete actual;
	}
}


void Preorden(Node *root){
	if(root != NULL){
		cout<<root->dato<<",";
		Preorden(root->izq);
		Preorden(root->der);
	}
}

void Inorden(Node *root){
	if(root!=NULL){
		Inorden(root->izq);
		cout<<root->dato<<",";
		Inorden(root->der);
	}
}

void Posorden(Node *root){
	if(root!=NULL){
		Posorden(root->izq);
		Posorden(root->der);
		cout<<root->dato<<",";
	}
}

Tree::Tree(Node *r){
	root=r;
}

void Tree::Insertar(int n){
	Node *actual;
	Node *ultimo;
	Node *nuevo;

	nuevo=new Node();
	nuevo->dato=n;
	nuevo->izq=NULL;
	nuevo->der=NULL;

	if(root==NULL){
		root=nuevo;
	}
	else{
		actual=root;
		while(actual !=NULL){
			ultimo=actual;
			if(actual->dato==n){
				cout<<"pendejo el dato ya existe"<<endl;
				return;
			}
			else if (actual->dato > n){
				actual = actual->izq;
			}
			else{
				actual= actual->der;
			}
		}
		
		if(ultimo->dato > n){
			ultimo->izq=nuevo;
		}
		else{
			ultimo->der=nuevo;
		}
	}
}

bool Tree::Buscar(int n){
	Node *actual;
	bool encontrar=false;

	if(root==NULL){
		cout<<"el arbol esta vacio"<<endl;
	}
	else{
		actual=root;
		while(actual != NULL && !encontrar){
			if(actual->dato==n){
				encontrar=true;
			}
			else if (actual->dato > n){
				actual=actual->izq;
			}
			else{
				actual=actual->der;
			}
		}
	}
	return encontrar;
}


void Tree::Borrar(int n){
	Node *actual;
	Node *anterior;
	bool centinela=false;

	if(root==NULL){
		cout<<"el arbol esta vacio"<<endl;
		return;
	}
	else{
		actual=root;
		anterior=root;
		while(actual!=NULL && !centinela){
			if(actual->dato==n){
				centinela=true;
			}
			else{
				anterior=actual;
				if(actual->dato > n){
					actual=actual->izq;
				}
				else{
					actual=actual->der;
				}
			}
		}

		if(actual==NULL){
			cout<<"el elemento no esta en el arbol"<<endl;
		}
		else if (centinela){
			if(actual==root){
				BorrarN(root);
			}
			else if (anterior->dato > n){
				BorrarN(anterior->izq);
			}
			else{
				BorrarN(anterior->der);
			}
		}
	}
}

void Tree::preorden(void){
	Preorden(root);
}


void Tree::inorden(void){
	Inorden(root);
}

void Tree::posorden(void){
	Posorden(root);
}
