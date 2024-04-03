#include <iostream>
#include <string>

using namespace std;


class fecha{
	
private:
	int dia;
	int mes;
	int anio;
	
public:
	
	fecha(int di, int me , int a){
		
		if(me >= 1 && me <= 12){
			mes = me;
		} else {
			mes = 1;
		}
		
		if(a >= 1900 && a <=2050){
			anio = a;
		} else {
			anio = 1900;
		}
		
		dia = di;
		//mes = me ;
		//anio = a;
	}
	
	void setDia(int d){
		dia = d;
	}
	void setMes(int m){
		
		if(m >= 1 && m <= 12){
			mes = m;
		} else {
			mes = 1;
		}
	}
	void setAnio(int an){
		
		if(an >= 1900 && an <=2050){
			anio = an;
		} else {
			anio == 1900;
		}
	}
		
	int getDia()const{
		return dia;
	}
	int getMes()const{
		return mes;
	}
	int getAnio()const{
		return anio;
	}
	bool esbisiesto()const{
		
		if(anio % 4 == 0 || anio % 400 == 0 ){
			return true;
		} else {
			return false;
		}
	}
	
	void imprimirFecha(){
		cout<< dia << " - " << mes << " - " << anio ; 
	}
		
	
	
};

int main(){
	
	fecha fecha_1(3,1,2020) ;
	fecha fecha_2(20,12,1500) ;
	
	//fecha_1.setMes(12);
	
	fecha_1.imprimirFecha();
	cout<<endl;
	if(fecha_1.esbisiesto() == 1){
		cout<<"esbisiesto "<<endl;
	} else {
		cout << "no es bisiesto"<<endl;
	}
	
	cout<<endl;
	

	fecha_2.imprimirFecha();
	cout<<endl;
	if(fecha_2.esbisiesto() == 1){
		cout<<"esbisiesto "<<endl;
	} else {
		cout << "no es bisiesto"<<endl;
	}
	
	
	
	
	return 0;
}
