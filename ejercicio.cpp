/*

// suma de digitos
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int numero = 123;
	
	int cont = 0;
	
	
	while( numero != 0){
		
		cont = cont + numero%10;
		numero = numero /10;
	}
	cout<<"suma "<<cont<<endl;
	
	return 0;
}
*/

/*

//suma de secuencia de espaciales
#include <iostream>
using namespace std;

int facto(int n){
	int cont = 1;
	for(int i=1 ; i<=n;i++){
		cont = cont * i;
	}
	return cont;
}

int main(int argc, char *argv[]) {
	
	int numero = 145;
	
	int cont = 0;
	
	
	while( numero != 0){
		
		cont = cont + facto(numero%10);
		numero = numero /10;
	}
	cout<<"suma "<<cont<<endl;
	
	cout<<facto(5);
	
	return 0;
}

*/

/*
//fibonaci
// 0 1 1 2 3 5 8 ...
#include <iostream>

using namespace std;

int main(){
	int n=8;
	int t1 = 0;
	int t2 = 1;
	int t3;
	
	for(int i =1;i<=n;i++){
		if(i == 1){
			cout<<t1 <<",";
			continue;
		}
		if(i == 2){
			cout<<t2<<",";
			continue;
		}
		
		t3 = t1 + t2;
		t1 = t2;
		t2 = t3;
		
		cout<<t3<<",";
		
	}

	return 0;
}
*/


//primo
#include <iostream>

using namespace std;

int main(){
	
	int n;
	n=73;
	
	int cont = 0;
	for(int i = 1 ; i<=n;i++){
		if(n % i == 0){
			cont = cont + 1;
		}
	}
	
	cout<<cont;
	if(cont == 2 ){
		cout<<"es primo ";
	}
	
	return 0;
}
