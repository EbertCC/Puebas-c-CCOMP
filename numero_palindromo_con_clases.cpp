#include <iostream>

using namespace std;

class palin{
private:
	int numero;
public:
	explicit palin(int num){
		numero = num;
	}
	
	void set_numero(int num){
		numero = num;
	}
	int get_numero()const{
		return numero;
	}
	
	bool numero_es_palin()const{
		
		int numero_pa = numero;
		int numero_ori = numero;
		int numero_revertido = 0;
		int ultimo_digito;
		
		while(numero_pa != 0){
			ultimo_digito = numero_pa%10;
			
			numero_revertido = numero_revertido*10 + ultimo_digito; 
			
			numero_pa = numero_pa/10;
		}
		if(numero_ori == numero_revertido){
			return true;
		}else{
			return false;
		}
	}
	
};

int main(){
	int num;
	palin numero1(5);
	//cout<< numero1.get_numero()<<endl;
	
	cout<<"ingre numero : "<<endl;
	cin>> num ;
	numero1.set_numero(num);
	//cout<< numero1.get_numero();
	
	
	if(numero1.numero_es_palin() == true ){
		cout<<"es palin"<<endl;
	} else {
		cout<<"no es palin"<<endl;
	}
	
	return 0;
}
