#include <iostream>

using namespace std;

struct Nodo{
  int dato;
  Nodo *sig;
};

void push(Nodo *&primero, Nodo *& ultimo,  int x){
  if(primero ==0){
    Nodo *new_nodo= new Nodo();
	new_nodo-> dato= x;
	new_nodo ->sig = NULL;
    primero = new_nodo;
	ultimo = new_nodo;
  }
  else{
    Nodo *new_nodo= new Nodo();
	new_nodo->dato=x;
	new_nodo->sig= NULL;
	ultimo->sig = new_nodo;
	ultimo = new_nodo;
  }
}

bool empty(Nodo *&primero, Nodo *& ultimo){
  return  (primero == ultimo)? true: false;
} 

void pop(Nodo *&primero, Nodo *&ultimo){
  if(empty(primero, ultimo)){
    cout<<"eliminando a: "<< primero->dato<<endl;
    Nodo *aux= primero;
	primero=aux->sig;
	delete aux;
    cout<< "la cola esta vacia"<<endl; 
	cout<<"haces otro pop y te parto tu madre"<<endl;
  }
  else{
    cout<<"eliminando a: "<<primero->dato<<endl;
	Nodo *aux=primero;
	primero=aux->sig;
	delete  aux;
  }
}

int main(){
  Nodo *primero=NULL;
  Nodo *ultimo=NULL;
  push(primero, ultimo, 2);
  push(primero, ultimo,4);
  pop(primero, ultimo);
  pop(primero, ultimo);
  return 0;
}
