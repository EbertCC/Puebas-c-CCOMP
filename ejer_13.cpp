#include <iostream>

using namespace std;

struct ascd{
    bool operator()(int a,int b){
        return a<b;
    }
};

struct desc{
    bool operator()(int a, int b){
        return a>b;
    }
};

struct nodo{
    int valor;
    nodo *next;
    nodo(int v, nodo* n=nullptr){
        valor = v;
        next = n;
    }
};

void crear(int *p, nodo*& lista){
    lista = new nodo(*p);
    p++;
    for(nodo* n = lista ; *p>0;p++, n = n -> next){
        n->next = new nodo(*p);
    }
}

void print(nodo *lista){
    cout<<" lista -> ";
    for( ; lista ; lista = lista -> next){
        cout<<lista->valor<<" ";
    }
}


template<typename T>
void ordenar(nodo *& lista, T comp){
    if(lista == nullptr && lista->next == nullptr){
        return;
    }
    for(nodo* i = lista; i->next != nullptr ; i = i ->next){
        for(nodo* j = i->next ; j != nullptr ; j = j -> next){

            if(comp(j->valor,i->valor)){
                int temp =i->valor;
                i->valor = j->valor;
                j->valor = temp;
            }
        }
    }



}


int main(){
    int A[] = {7,18,9,8,2,-1};

    nodo *milista;
    crear(A,milista);
    print(milista);

    //orden asc
    ordenar(milista,desc());
    print(milista);

    return 0;

}