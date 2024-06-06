#include <iostream>
#include <algorithm>

using namespace std;

class Persona{
protected:
	string nombre;
	int edad;
public:
	Persona():nombre(""),edad(0){}
	Persona(string n,int e):nombre(n),edad(e){}
	string getNombre() const;
	void setNombre(string n);
	int getEdad() const;
	void setEdad(int e);
	void print() const;
	~Persona();
	
	
};

string Persona::getNombre()const{
	return nombre;
}
int Persona::getEdad()const{
	return edad;
}

Persona::~Persona(){
	
}

void Persona::setNombre(string n){
	this->nombre = n ;
}

void Persona::setEdad(int e){
	this->edad = e;
}
void Persona::print()const{
	cout<<"nombre : "<<nombre<<"  edad : "<<edad<<endl;
}

bool verificar_edad(const Persona &a, const Persona &b){
	return a.getEdad()<b.getEdad();
}

bool verificar_nombre(const Persona &a, const Persona &b){
	return a.getNombre()<b.getNombre();
}

int main(int argc, char *argv[]) {
	const int tamanio = 3;
	Persona *p;
	p = new Persona[tamanio];
	
	//p->setNombre("hola");
	
	// para 3 personas
	for(int i=0 ; i < tamanio ; i++){
		string nom;
		int edad;
		cout<<i <<" -> ingrese nombre : ";
		cin>>nom;
		cout<<i <<" -> ingrese edad : ";
		cin>>edad;
		
		(p+i) -> setNombre (nom);
		(p+i) -> setEdad (edad);
			
	}
	
	// crear otro puntero que punte desde el ultimo al primero
	Persona *ptr = p;//(p+tamanio-1);
	
	cout<<endl;
	cout<<"Imprimir del ultimo al primero"<<endl;
	for(int i = tamanio-1 ; i >= 0 ; i --){
		cout<<"nombre "<< (ptr+i) -> getNombre() << endl;
		cout<<"edad "<< (ptr+i) -> getEdad() << endl;
	}
	cout<<endl;
	
	
	cout<<"Imprimir indice impar "<<endl;
	for(int i=0 ; i < tamanio ; i++){
		if((i)%2 != 0){
			cout<<"nombre "<< (ptr+i) -> getNombre() << endl;
			cout<<"edad "<< (ptr+i) -> getEdad() << endl;
		}
	}
	
	cout<<endl;
	cout<<"Orden de edad"<<endl;
	sort(p , p + tamanio,verificar_edad);
	for(int i = 0 ; i <= tamanio-1 ; i ++){
		cout<<"nombre "<< (ptr+i) -> getNombre() << endl;
		cout<<"edad "<< (ptr+i) -> getEdad() << endl;
	}
	cout<<endl;
	
	cout<<endl;
	cout<<"Orden de nombre"<<endl;
	sort(p , p + tamanio,verificar_nombre);
	for(int i = 0 ; i <= tamanio-1 ; i ++){
		cout<<"nombre "<< (ptr+i) -> getNombre() << endl;
		cout<<"edad "<< (ptr+i) -> getEdad() << endl;
	}
	cout<<endl;
	
	
	
	
	delete []p;
	return 0;
}

