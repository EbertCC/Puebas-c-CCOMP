#include <iostream>

using namespace std;

bool decide(int valor){
    return (valor % 2 == 0);
}


class nodo{
    public:
    int info;
    nodo *next;

    nodo(){next = nullptr;}
    nodo(int i , nodo *n = nullptr){
        info = i;
        next = n;
    }

};


void split(nodo *& lista_1, nodo *&lista_2,bool(*decide)(int) ){

    lista_2 = nullptr;
    nodo* p = lista_1;
    nodo* aux = nullptr;
    nodo* cola = nullptr;

    while( p != nullptr){
        if(decide(p -> info)){
            aux = p;
            p = p -> next;
        }else{

            nodo* temp = p;
            p = p -> next;

            if( aux != nullptr){
                aux -> next = p;
            }else{
                lista_1 = p;
            }
            temp->next = nullptr;

            if(lista_2 == nullptr){
                lista_2 = temp;
                cola = temp;
            }else{
                cola -> next = temp;
                cola = temp;
            }
        }

    }


}

void printList(nodo *head){
    while(head != nullptr){
        cout<< head -> info<<" ";
        head = head -> next;
    }
}

int main(){

    nodo *a = new nodo(1);
    a->next = new nodo(2);
    a->next->next = new nodo(3);
    a->next->next->next = new nodo(4);
    a->next->next->next->next = new nodo(5);


    nodo *b = nullptr;

    split(a,b,decide);

    cout << "Lista a (numeros pares): ";
    printList(a);

    cout << "Lista b (numeros impares): ";
    printList(b);

    return 0;
}