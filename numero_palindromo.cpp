#include <iostream>
#include <string>


using namespace std;

int main(){
	int numero;
	int numero_original;
	int numero_revertido = 0;
	int aux;
	
	cout<<"ingrese numero : ";
	cin>>numero;
	
    numero_original = numero;
	
	while( numero != 0){
		aux = numero%10;
		numero_revertido = numero_revertido * 10 + aux;
		
		cout<<"el auxliar es : "<<aux<<", el numero reverido es :"<<numero_revertido<<endl;
		numero = numero/10;
	}
	
	if(numero_original == numero_revertido){
		cout<<"numero es palindromo "<<endl;
	}else{
		cout<<"numero no es palindromo"<<endl;
	}
	
	
	
	return 0;
}
