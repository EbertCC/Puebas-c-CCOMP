#include <iostream>
#include <string>

using namespace std;


class estudiante {
	
private:
	string nombre;
	int edad;
public:
	
	estudiante(string no, int e){
		nombre = no;
		edad = e;
	}
	
	void setName(string nom){
		nombre = nom;
	}
	void setEdad(int ed){
		edad = ed;
	}
	string getName()const{
		return nombre;
	}
	int getEdad()const{
		return edad;
	}
	
	bool esmayor()const{
		if(edad >= 18){
			return true;
		} else{
			return false;
		}
	}
	
};

int main(){
	
	/*
	estudiante estudiante_1("ebert",17);
	
	cout<<estudiante_1.getName()<< " "<< estudiante_1.getEdad() << endl;
	cout<<estudiante_1.esmayor();
	*/
	
	string nom;
	int edad;
	
	estudiante estudiante_2(" ",0);
	
	cout<<"Ingrese Nombre : "<<endl;
	
	getline(cin,nom);
	//cin>>nom;
	
	cout<<"Ingrese Edad : "<<endl;
	cin>>edad;
	
	estudiante_2.setName(nom);
	estudiante_2.setEdad(edad);
	
	
	cout<<endl;
	cout<<"nombre estudiante : "<<estudiante_2.getName()<<endl; 
	cout<<"edad :" << estudiante_2.getEdad()<<endl;
	
	if(estudiante_2.esmayor() == 1 ){
		cout<<"es mayor de edad "<<endl;
	} else {
		cout<<"es menor de edad";
	}
	
}
