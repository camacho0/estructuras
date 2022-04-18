#include "arboles.hpp"

using namespace std;
void CrearNode(Node *&a,int n){
	a = new Node();
	a->dato=n;
	a->izq=NULL;
	a->der=NULL;
	//cout<<a->dato;
}


void InsertarNode(Node *&a, int n){
	if(a==NULL){
		CrearNode(a,n);
	}
	else{
		int valor=a->dato;
		if(n<valor){
			InsertarNode(a->izq,n);
		}
		else{
			InsertarNode(a->der,n);
		}
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

void Tree::preorden(void){
	Preorden(root);
}


void Tree::inorden(void){
	Inorden(root);
}

void Tree::posorden(void){
	Posorden(root);
}
