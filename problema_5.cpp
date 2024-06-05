#include <iostream>
#include <string>

using namespace std;

//creo mi clase
class Employee{
public:
	//inicializo mis funciones miembro
	Employee(const string&, const string&);
	~Employee();
	string getFirstName() const;
	string getLastName() const;
	static unsigned int getOunt();
	
private:
	//creo mis atributos
	string firstName;
	string lastName;
	static unsigned int count;
};

// a
// declaro mis funciones miembro
unsigned int Employee::count = 0;
Employee::Employee(const string &firstName, const string &lastName){
	this->firstName = firstName ;
	this->lastName = lastName;
	++count;
}
Employee::~Employee(){
	--count;
}
unsigned int Employee ::getOunt(){
	return count;
}


int main() {
	
	// b
	//creo 5 obejtos en el stack
	Employee employees[5] = {
	    	Employee("Ebert", "Condori"),
			Employee("Rodolfo", "Casquino"),
			Employee("Juan", "Carlos"),
			Employee("Denis", "Talavera"),
			Employee("Diego", "Escobar")
	};
	
	//c
	//creo 5 obejtos en el heat
	Employee *employees_2  = new Employee[5]{
		    Employee("Ebert", "Condori"),
			Employee("Rodolfo", "Casquino"),
			Employee("Juan", "Carlos"),
			Employee("Denis", "Talavera"),
			Employee("Diego", "Escobar")
	};
	
	// d
	// imprime 10 empleados
	cout<<"Numero actual de count(empleados)"<<Employee::getOunt()<<endl; //imprime 10 porque es una varible static que guarda el total
	
	// e
	// elimino con la funcion delete para new y utilizo el destructor de mi clase
	delete[] employees_2;
	for (int i = 0; i < 5; ++i) {
		employees[i].~Employee();
	}
	
	// f
	//impprime 0 porque libere la memoria de mis obejetos 
	cout<<"Numero actual de count(empleados)"<<Employee::getOunt()<<endl;
	
	// g
	//creo 2 obejetos utilizando new para guardar en heap
	Employee* obejt1 = nullptr;
	Employee* obejt2 = nullptr;
	
	if(true){
		obejt1 = new Employee("Ebert","Condori");
		obejt2 = new Employee("Luis","Casquino");
		
	}
	
	// h
	// imprime 2 
	cout<<"Numero actual de count(empleados)"<<Employee::getOunt()<<endl;
	
	// i
	// elemino los obejtos del heat con delete
	delete obejt1;
	delete obejt2;
	
	return 0;
}
