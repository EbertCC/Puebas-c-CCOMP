#include <iostream>
using namespace std;

bool esPrimo(int n) {
	if( n % 2 == 0 || n == 0 || n == 1) return false;
	for(int i = 2; i <= n/2; i++){
		if( n % i == 0){
			return false;
		}
	}
	return true;
}

/*
* Implemente una función que reciba un entero n e imprima
* los n primeros nros primos.

void printNPrimos(int n) {
	
	contador = 1
	MIENTRAS contador < n
	SI contador es primo
	imprime contador    
	contador = contador + 1        
	
}
*/
void imprimir_nprimps2(int a){// n<infinito
	int cont1 = 1;
	int cont2 = 0;
	
	while(cont1 <= a){
		if(esPrimo(cont2) == true){
			cout<<cont2<<" , ";
			cont1 = cont1 + 1; 
		}
		cont2 = cont2 + 1;
	} 
}

/*
//escrib una funcion que rsiva cadena y retorne string
int tam_cade(string cad){

	int counter{0};
    for( int i = 0; i < cad.length()  ; i++ ) {                
        int val = static_cast<int>(cad.at(i));
        if(val >= 48 && val <= 59)
            counter++;
    }
	return counter;
}
*/

int cont_cadena(string cad){
	int counter{0};
	for( int i = 0; i < cad.length()  ; i++ ) {                
		int val = static_cast<int>(cad.at(i));
		if(val >= 97 && val <= 122)
			counter++;
	}
	return counter;
}
	
void conver_cadena(string cad){
	char c;
	
	for( int i = 0; i < cad.size(); i++ ) {        
		c = cad.at(i);
		int val = static_cast<int>(c);
		if(val >= 97 && val <= 122)
			cad.at(i) = c - 32;  //toupper(c);
	}
	
	cout<<"Cdenaa mayucula : "<<cad;
}

void fibo(int num){
	int temp1 = 1;
	int temp2 = 1;
	int temp3 = 1;

	for(int i = 1; i<=num;i++){

		if(i==1){
			//temp3 = 1;
			continue;
		}
		

		temp3 = temp1 + temp2;
		temp1 = temp2;
		temp2 = temp3;
	}
	cout<<temp3;


}

int re_fibo(int n){
	if(n==1 || n ==0){
		return 1;
	} else {
		return re_fibo(n-2) + re_fibo(n-1);
	}
}

int main(){
	// 0 1 1 2 3 5 8
	long long numero;
	bool noEsPrimo = false;
	/*
	cout<<"Introduce el numero: ";cin>>numero;
	
	if( esPrimo(numero) ) {
		cout << numero << " ES PRIMO" << endl;
	}else{
		cout << numero << " NO ES PRIMO" << endl;
	}
	*/
	
	//imprimir_nprimps2(10);
	//cout<<cont_cadena("hola");
	//conver_cadena("hola");
    fibo(5);
	cout<<re_fibo(5);
	return 0;
}
