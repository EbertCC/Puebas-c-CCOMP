#include <iostream>
#include <string>

using namespace std;

class cuenta {
	
private:
	string nombre;
	int edad;
	float monto;
public:
	
	cuenta( string nom, int ed, float mon){
		nombre = nom;
		edad = ed;
		if(mon < 0)
			monto = 0;
		else
			monto = mon;
	}
	
	void setName(string nom){
		nombre = nom;
	}
	void setEdad(int ed){
		edad = ed;
	}
	void setMonto(float mon){
		if( mon < 0 ){
			monto = 0;
			
		}else{
			monto = mon;
		}
		
	}
		
	void ingresarMonto(float num){
		
		monto = monto + num;
		
	}
	
	void retirarMonto(float num){
		if(num > monto){
			monto = monto;
			cout<<"monto incorrecto"<<endl;
		} else{
			monto = monto - num;
		}
	}
	
	string getName()const{
		return nombre;
	}
	int getEdad()const{
		return edad;
	}
	float getMonto()const{
		return monto;
	}
		
};

int main(){
/*
	cuenta cuenta_1;
	
	cuenta_1.setName("ebert");
	cuenta_1.setEdad(19);
	cuenta_1.setMonto(-500);
	cuenta_1.ingresarMonto(1000);
	cuenta_1.retirarMonto(10000);
	
	cout<<cuenta_1.getName()<<" "<<cuenta_1.getEdad()<<" "<<cuenta_1.getMonto()<<endl;
*/
	cuenta cuenta_2("juan",15,-500);
	cout<<cuenta_2.getName()<<" "<<cuenta_2.getEdad()<<" "<<cuenta_2.getMonto()<<endl;
	
	return 0;
	
}
