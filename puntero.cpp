#include <iostream>
using namespace std;

void sawp(int *a , int *b){
	
	int temp = *a;
	
	*a = *b;
	*b =  temp;
	
}
	
void crear(float *&ptr, int tam){
	
	ptr = new float[tam];
	
}
void ingresar(float *ptr, int tam){
	
	for(int i = 0 ; i < tam ; i++){
		*(ptr+i) = rand()%10;
	}
}

void imprimir(float *ptr , int tam){
	for(int i = 0 ; i< tam ; i++){
		cout<<*(ptr+i)<<" ";
	}
	cout<<endl;
}
void borrar(float *ptr, int tam){
	delete ptr;
}
	
	void unir(char *p1, char *p2)
	{
		while(*p1){
			p1++;      
		}
		while(*p2){
			*p1=*p2;   
			p2++;      
			p1++;      
		}
		
		
		
	}
	
int main(int argc, char *argv[]) {
	
	int a,b;
	a = 2;
	b = 10;
	
	//sawp(&a,&b);
	//cout<<a<<"  "<<b;
	int tam1 = 10;
	int tam2 = 11;
	
	float *ptr1,*ptr2;
	
	crear(ptr1,tam1);
	ingresar(ptr1,tam1);
	imprimir(ptr1,tam1);
	borrar(ptr1,tam1);
	
	crear(ptr2,tam2);
	ingresar(ptr2,tam2);
	imprimir(ptr2,tam2);
	borrar(ptr2,tam2);
	
	
	
	char p1[10],p2[10];
	cout << "ingrese 1 cadena de caracteres : ";
	cin.getline(p2,10);
	cout << "ingrese 2 cadena de caracteres : ";
	cin.getline(p1,10);
	
	unir(p1,p2);
	
	cout <<p1<< endl;
	return 0;
	
	
	return 0;
}

/*
//6.
#include <iostream>
using namespace std;

void suma(int a,int b)
{
cout<<"Introdujo suma: "<<a<<"+"<<b<<"= "<<a+b;
}
void resta(int a,int b)
{
cout<<"Introdujo resta: "<<a<<"-"<<b<<"= "<<a-b;
}
void multiplicaion(int a,int b)
{
cout<<"Introdujo multiplicaion: "<<a<<"*"<<b<<"= "<<a*b;
}
void division(int a,int b)
{
cout<<"Introdujo division: "<<a<<"/"<<b<<"= "<<a/b;
}

int main()
{
int a,b;
void (*p[4])(int,int)={suma,resta,multiplicaion,division};
cout<<"INGRESE 2 NUMEROS"<<endl;
cin>>a;
cin>>b;

int opc;
cout<<"opcion 0 : suma "<<endl;
cout<<"opcion 1 : resta "<<endl;
cout<<"opcion 2 : multiplicaion "<<endl;
cout<<"opcion 3 : division "<<endl;
cout<<"\nIntroduzca una opcion entre 0 y 3: ";
cin>>opc;
while(opc>=0 && opc<=3)
{
(*p[opc])(a,b);
cout<<"\nIntroduzca una opcion entre 0 y 3: ";
cin>>opc;
}
return 0;
}

*/
