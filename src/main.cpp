
/*
 * Unfinished tree template class.
 * Warning : this class is not going to do the job without ecxeption.
 *

*/
#define USE_NODE
#include <iostream>

using namespace std;

template <typename T>
#ifdef USE_NODE
struct Node {
    Node<T>* ptrRight;
    Node<T>* ptrLeft;
    Node<T>* ptr;
    T data;
    Node() {
        ptrRight = NULL;
        ptrLeft = NULL;
    }
};
#endif

template <typename T>
class Tree {
    Node<T>* ptrCurrent;
    Node<T>* ptrStart;
public:
    Tree(){
        ptrStart = new Node<T>;
        ptrCurrent = ptrStart;
    }

    Tree<T>* Pointer;

    void Add(T Data){
        Node<T>* ptr = new Node<T>;
        ptr->data = Data;
        Node<T>* Temp =ptrStart;
        while((Temp->ptrRight != NULL && ptr->data > Temp->data) || (Temp->ptrLeft != NULL && ptr->data < Temp->data)){
            cout << Temp->data << endl;
            if(ptr->data > Temp->data){
                Temp = Temp->ptrRight;
                //cout << Temp->data << endl;
            }
            else {
                Temp = Temp->ptrLeft;
                cout << "L" << endl;
            }
        }
        if(Temp->data < Data)
           Temp->ptrRight = ptr;
        else
            Temp->ptrLeft = ptr;
    }

/*    Node<T> *operator [] (uint Subscript){
        if(Subscript >= 0 && Subscript <= size){
            uint __it = 0;
            for(Node<T> *ptr = ptrStart;ptr->; ptr = ptr->ptrNext){
                if(__it == Subscript)
                    return ptr;
                __it++;
            }
        }
    }
*/

    Node<T>* Search(T Data){
        Node<T>* ptrSearch;
        ptrSearch = ptrStart;
        while(!(ptrSearch->data == Data) || !(ptrSearch->ptr != NULL)){
            if(ptrSearch->data < Data){
                ptrSearch = ptrSearch->ptrRight;
                cout << "Right" << endl;
            }
            else{
                ptrSearch = ptrSearch->ptrLeft;
                cout << "Left" << endl;
            }
        }
        return ptrSearch;
    }

    void Sort(){

    }

    int Weight(){

    }

};

int main(){
    Tree<int> MyTree;
    MyTree.Add(12);
    MyTree.Add(45);
    MyTree.Add(54);
    MyTree.Add(32);
    MyTree.Add(324);
    cout << MyTree.Search(12)->data;
    return 0;
}
