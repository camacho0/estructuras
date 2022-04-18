#include "ArBi.hpp"

using namespace std;

int main(){

	Node* nodo=NULL;

	Tree arbol(nodo);
	
	arbol.Insertar(5);
	arbol.Insertar(9);
	arbol.Insertar(6);
	arbol.Insertar(3);
	arbol.Insertar(8);
	
	arbol.preorden();
	cout<<endl;
	arbol.inorden();
	cout<<endl;
	arbol.posorden();
	cout<<endl;
	cout<<arbol.Buscar(6)<<endl;
	arbol.Borrar(6);

	arbol.preorden();
	cout<<endl;
	arbol.inorden();
	cout<<endl;
	arbol.posorden();
	cout<<endl;


	return 0;
}
