#include <iostream>
using namespace std;

int potencia(int a, int b){
	int cont = 1;
	for(int i=0 ; i<b;i++){
		cont = cont * a;
	}
	return cont;
}

bool esprimo(int a){
    int cont = 0;
    for(int i=1;i<=a;i++){
        if(a%i == 0){
            cont = cont + 1;
        }
    }
    if(cont == 2){
        return true;
    } else {
        return false;
    }


}

void imprimir_nprimps(int a){ // n<100
    int cont = 0;
	for(int i=0; i<100; i++){
		if(esprimo(i) == true){
			cont = cont + 1;
			cout<<i<<" , ";
		}
		if(cont == a){
			break;
		}
	}
}

void imprimir_nprimps2(int a){// n<infinito
	int cont1 = 1;
	int cont2 = 0;
	
	while(cont1 <= a){
		if(esprimo(cont2) == true){
			cout<<cont2<<" , ";
			cont1 = cont1 + 1; 
		}
		cont2 = cont2 + 1;
	} 
}

int main(int argc, char *argv[]) {
	
	//cout<<"potencia (3,4)"<<potencia(3,4);
	
    //cout<<"es pirmo el : "<<esprimo(7);
    
	imprimir_nprimps2(10);

	return 0;
}
