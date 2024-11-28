#include <iostream>

using namespace std;

class par{
    public:
    bool operator()(int b){
        return b%2==0;
    }

};

class tres{
    public:
    bool operator()(int b){
        return b%3==0;
    }
};

class nodo{
    public:
    int valor;
    nodo *next;

    nodo(int a,nodo *n = nullptr):valor(a),next(n){}

};

template<class T>
void split(nodo *& lista_A , nodo *& lista_B , T criterio){

    nodo * p = lista_A;
    lista_B = nullptr;
    nodo * prev_A = nullptr;
    nodo * last_B = nullptr;

    while( p != nullptr){

        if(criterio(p->valor) ){
            prev_A = p;
            p = p ->next;
        }else{

            nodo* temp = p;
            p = p -> next;

            if(prev_A == nullptr){
                lista_A = p;
            }else{
                prev_A -> next = p;
            }

            temp -> next =nullptr;

            if(lista_B == nullptr){
                lista_B = temp;
                last_B = temp;
            }else{
                last_B -> next = temp;
                last_B = temp;
            }
        }

    }

}

void printlist(nodo* head){
    while (head != nullptr)
    {
        cout<<head->valor<<" ";
        head = head -> next;
    }
    
}

void deltelista(nodo *&head){
    while (head != nullptr)
    {
        nodo *temp = head;
        head = head ->next;
        delete temp;
    }
    
}
int main(){

    nodo *a = new nodo(1);
    a->next = new nodo(2);
    a->next->next = new nodo(3);

    nodo *b = nullptr;

    split(a,b,tres());

    //printlist(a)<<endl;
    //printlist(b);
    //cout << "Lista A (pares):" << endl;
    //printList(a);
    //cout << "Lista B (no pares):" << endl;
    //printList(b);

    cout << "Lista A (pares):" << endl;
    printlist(a);
    cout << "Lista B (no pares):" << endl;
    printlist(b);


    deltelista(a);
    deltelista(b);
    return 0;
}