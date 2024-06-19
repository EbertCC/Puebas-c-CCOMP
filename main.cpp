#include <iostream>

using namespace std;

class Persona{
    private:
    int edad;
    string nombre;
    
    public:
    Persona();
    Persona(string nombre,int edad);
    ~Persona();
    void setNombre(string nombre);
    void setEdad(int edad);
    string getNombre()const;
    int getEdad()const;
    virtual void imprimir() const=0;

    friend ostream& operator<<(ostream & os,const Persona& persona);
};

Persona::Persona(){

}
Persona::Persona(string nombre,int edad){
    this->nombre = nombre;
    this->edad = edad;
}
void Persona::setNombre(string nombre){
    this->nombre=nombre;
}
void Persona::setEdad(int edad){
    this->edad=edad;
}
string Persona::getNombre()const{
    return nombre;
}
int Persona::getEdad()const{
    return edad;
}

ostream & operator<<(ostream &os,const Persona & persona){
    os<<"Nombre :"<<persona.nombre<<" , Edad : "<<persona.edad;
    return os;
}
Persona::~Persona(){

}

bool Odernar_Edad(const Persona &a, const Persona &b){
    return a.getEdad()<b.getEdad();
}

class Estudiante : public Persona {
    private:
    string grado;
    
    public:
    Estudiante();
    Estudiante(string nombre,int edad,string grado);
    void setGrado(string grado);
    string getGrado()const;
    ~Estudiante();
    void imprimir()const override;

    friend ostream& operator<<(ostream& os, const Estudiante &estudiante);
};

Estudiante::Estudiante(){

}
Estudiante::Estudiante(string nombre,int edad,string grado):Persona(nombre,edad){
    this->grado = grado;
}
void Estudiante::setGrado(string grado){
    this->grado = grado;
}
string Estudiante::getGrado()const{
    return grado;
}
void Estudiante::imprimir()const{
    cout<<"Nombre : "<<getNombre()<<" , Edad : "<<getEdad()<<" , Grado : "<<getGrado()<<endl;
}

ostream& operator<<(ostream& os, const Estudiante &estudiante){
    os<<static_cast<const Persona&>(estudiante);
    os<<", grado "<<estudiante.grado;
    return os;
}
Estudiante::~Estudiante(){

}

class Profesor : public Persona {
    private:
    string curso;
    public:

    Profesor();
    Profesor(string nombre,int edad,string curso);
    void setCurso(string curso);
    string getCurso()const;
    ~Profesor();
    void imprimir()const override;
    
    friend ostream& operator<<(ostream & os, const Profesor &o);

};

ostream& operator<<(ostream &os , const Profesor &o){
    os<<" Nombre : "<<o.getNombre()<<" , Edad : "<<o.getEdad()<<" , Curso : "<<o.curso;
    return os;
}

Profesor::Profesor(){

}
Profesor::Profesor(string nombre,int edad,string curso):Persona(nombre,edad){
    this->curso=curso;
}
void Profesor::setCurso(string curso){
    this->curso=curso;
}
string Profesor::getCurso()const{
    return curso;
}
void Profesor::imprimir()const{
    cout<<"Nombre : "<<getNombre()<<" , Edad : "<<getEdad()<<" , Curso : "<<getCurso()<<endl;
}
Profesor::~Profesor(){

}
int main(){
    /*
    const int tamanio = 1;
    Persona *obj1;
    obj1 = new Persona[tamanio];
    cout<<"Ingrese datos : "<<endl;
    for(int i = 0 ; i<tamanio ; i++){
        string nombre;
        int edad;
        cout<<"Ingrese nombre ["<<i<<"] : "<<endl;
        //getline(cin,nombre);
        cin>>nombre;
        cout<<"Ingrese edad ["<<i<<"] : "<<endl;
        cin>>edad;

        (obj1+i) -> setNombre(nombre);
        (obj1+i) -> setEdad(edad);
    }
    
    Persona *ptr = obj1;
    cout<<"Imprimir puntero "<<endl;
    for(int i = 0 ; i<tamanio ;i++){
        cout<<i<<" -> "<< (ptr+i) -> getNombre() <<endl;
        cout<<i<<" -> "<< (ptr+i) -> getEdad() <<endl;
        cout<<endl;
    }


    delete []obj1;
    */

    //Persona per1;
    //Persona per2("Ebert",24);
		
	Estudiante est1;
	Estudiante est2("juan",23,"primero");
		
	Profesor prof1;
	Profesor prof2("alvaro",34,"mate");

    est2.imprimir();
	prof2.imprimir();

    cout<<est2;
    cout<<prof2;


    return 0;

}