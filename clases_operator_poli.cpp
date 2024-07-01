#include <iostream>

using namespace std;

class Poligono {
    protected:
    int base ; 
    int altura;

    public:

    Poligono();
    Poligono(int base,int altura);
    void set_Base(int base);
    void set_Altura(int altura);
    int get_Base()const;
    int get_Altura()const;
    ~Poligono();
    void mostrar()const;
    virtual void area() const=0;

    friend ostream& operator<<(ostream& os,const Poligono& poligono);
    friend bool operator==(const Poligono& lhs,const Poligono& rhs);
    friend bool operator!=(const Poligono& lhs,const Poligono& rhs);

};

Poligono::Poligono(){

}
Poligono::Poligono(int base,int altura){
    this->base=base;
    this->altura=altura;
}
void Poligono::set_Base(int base){
    this->base=base;
}
void Poligono::set_Altura(int altura){
    this->altura=altura;
}
int Poligono::get_Base()const{
    return base;
}
int Poligono::get_Altura()const{
    return altura;
}
void Poligono::mostrar()const{
    cout<<"Poligono de base : "<<base<<" y altura : "<<altura<<endl;

}
ostream& operator<<(ostream& os ,const Poligono& poligono){
    os<<"Poligono de base "<<poligono.base<<" y altura "<<poligono.altura;
    return os;
}
bool operator==(const Poligono& lhs, const Poligono& rhs){
    return lhs.base == rhs.base && lhs.altura == rhs.altura;
}
bool operator!=(const Poligono& lhs, const Poligono& rhs){
    return !( (lhs.base == rhs.base) && (lhs.altura == rhs.altura) ); 
}

Poligono::~Poligono(){

}

class Triangulo : public Poligono{
    protected:
    string color;
    public:

    Triangulo();
    Triangulo(int base,int altura,string color);
    void set_Color(string color);
    string get_Color()const;
    void mostrar();
    ~Triangulo();
    void area()const override;
    friend ostream& operator<<(ostream& os,const Triangulo& triangulo);
    friend Triangulo operator*(const Triangulo& lhs, const Triangulo& rhs);

};

Triangulo::Triangulo(){

}
Triangulo::Triangulo(int base,int altura,string color):Poligono(base,altura){
    this->color=color;
}
void Triangulo::set_Color(string color){
    this->color=color;
}
string Triangulo::get_Color()const{
    return color;
}
void Triangulo::mostrar(){
    cout<<"Triangulo de base : "<<base<<" , altura de : "<<altura<<" y de color "<<color<<endl;

}
void Triangulo::area()const{
    cout<<"Triangulo tiene un area de (Base * altura)/2 : "<<(base*altura)/2<<endl;
}
ostream& operator<<(ostream& os, const Triangulo& triangulo){
    os<<"triangulo de base "<<triangulo.base<<" y altura "<<triangulo.altura;
    return os;
}
Triangulo operator*(const Triangulo& lhs, const Triangulo& rhs){
    return Triangulo( lhs.base*rhs.base , lhs.altura*rhs.altura,lhs.color );
}
Triangulo::~Triangulo(){

}

class Rectangulo : public Poligono{
    protected:
    string color;
    public:
    Rectangulo();
    Rectangulo(int base,int altura,string color);
    void set_Color(string color);
    string get_Color()const;
    void mostrar();
    ~Rectangulo();
    void area()const override;
    friend ostream& operator<<(ostream& os ,const Rectangulo& rectangulo);
    friend Rectangulo operator*(const Rectangulo& lhs, const Rectangulo& rhs);
};
Rectangulo::Rectangulo(){

}
Rectangulo::Rectangulo(int base,int altura,string color):Poligono(base,altura){
    this->color = color;
}
void Rectangulo::set_Color(string color){
    this->color = color;
}
string Rectangulo::get_Color()const{
    return color;
}
void Rectangulo::mostrar(){
    cout<<"Rectangulo de base: "<<base<<" , altura : "<<altura<<" y de color :"<<color<<endl;

}
void Rectangulo::area()const{
    cout<<"Rectangulo tiene un area de base*altura : "<<base*altura<<endl;
}
ostream& operator<<(ostream& os,const Rectangulo& rectangulo){
    os<<"rectangulo de base "<<rectangulo.base<<" y de altura "<<rectangulo.altura;
    return os;
}
Rectangulo operator*(const Rectangulo& lhs, const Rectangulo& rhs){
    return Rectangulo(lhs.base * rhs.base , lhs.altura*rhs.altura , lhs.color);
}
Rectangulo::~Rectangulo(){
    
}


int main(){
	int const tamanio=2;//4
	
	//ejemplo 1 
	//Poligono a(12,32);
	Triangulo b(4,6,"azul");
	Rectangulo c(7,5,"rojo");
	//a.mostrar();
	b.mostrar();
	c.mostrar();
	b.area();
	c.area();
	cout<<b<<endl;
    cout<<c;
    Triangulo b2(4,6,"negro");
    cout<<endl;
    cout<<b*b2;
    /*
	if(b==b2){
		cout<<"son iguales ";
	}else{
		cout<<"son diferentes ";
	}*/
	
	/*
	//ejemplo 2
	Poligono *poly[tamanio];
	poly[0] = new Rectangulo(4, 5,"rojo");
	poly[1] = new Triangulo(4, 5,"azul");
	poly[2] = new Rectangulo(5, 6,"amarillo");
	poly[3] = new Triangulo(5, 6,"celeste");
	//Poligono *ptr = poly;
	for(int i =0; i <tamanio;i++){
		poly[i]->area();
	}
	for(int i =0; i <tamanio;i++){
		delete poly[i];
	}
	*/
	
	//ejemplo 3
	/*
	Poligono** list = new Poligono*[tamanio];
	list[0] = new Rectangulo(4, 5, "rojo");
	list[1] = new Triangulo(4, 5, "azul");
	list[2] = new Rectangulo(5, 6, "amarillo");
	list[3] = new Triangulo(5, 6, "celeste");
	
	delete[] list;
	*/
	
	/*
	//ejemplo 4
	Poligono *poligo[tamanio];
	
	for(int i = 0 ; i <tamanio;i++){
		int opc;
		cout<<"Ingrese Triangulo(0) o Rectangulo(1) : "; cin>>opc;
		if(opc == 0){
			int bas,alt;
			string color;
			cout<<"ingrese base y altura : "; cin>>bas ; cin >>alt;
			cout<<" ingrese color : "; cin>>color;
			
			poligo[i] = new Triangulo(bas,alt,color);
		}else{
			int bas,alt;
			string color;
			cout<<"ingrese base y altura : "; cin>>bas ; cin >>alt;
			cout<<" ingrese color : "; cin>>color;
			
			poligo[i] = new Rectangulo(bas,alt,color);
		}
	}


	
	for(int i = 0 ; i < tamanio; i++){
		poligo[i]->area();
	}
	
    cout<<"ördenar por area de poligono "<<endl;

    //sort()

	delete [] poligo;
	
    */

    return 0;
}