#include <iostream>

using namespace std;

struct Nodo{
  int dato;
  Nodo *top;
};

void push(Nodo *&pila, int x){
  Nodo *new_nodo= new Nodo();
  new_nodo->dato= x;
  new_nodo->top= pila;
  pila= new_nodo;
}

bool empty(Nodo *&pila){
  return (pila->top==NULL)?true:false;

} 

void pop(Nodo *&pila){
  if(empty(pila)){
	cout<<"eliminando de la pila a "<<pila->dato<<endl;
	Nodo *aux =pila;
	pila = aux->top;
	delete aux;
	cout<<"la pila esta vacia"<< endl;
  }
  else{
    cout<<"elimimando de la pila a: "<< pila->dato<<endl;
    Nodo *aux= pila;
	pila = aux->top;
	delete aux;
	
  }

}

int main(){
  Nodo *pila= NULL;
//  cout<<pila<<endl;//<<pila->dato<<endl;
  push(pila,5);
 // cout<< pila->top <<endl;
  push(pila,6);
  push(pila,7);
  pop(pila);
  pop(pila);
  pop(pila);
//  pop(pila);

  return 0;
}
