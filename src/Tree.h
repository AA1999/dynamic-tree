#ifndef TREE_H
#define TREE_H

/*
 * Unfinished tree template class.
 * Warning : this class is not going to do the job without ecxeption.
*/
#define USE_NODE

#include <iostream>

using namespace std;

template <typename T>

class Tree {
    Node* ptrCurrent;
    Node* ptrStart;
public:
    struct Node {
        Node* ptrRight;
        Node* ptrLeft;
        Node* ptr;
        T data;
        Node() {
            ptrRight = NULL;
            ptrLeft = NULL;
        }
    };
    Tree(){
        ptrStart = new Node<T>;
        ptrCurrent = ptrStart;
    }

    Tree<T>* Pointer;

    void Add(T Data){
        Node* ptr = new Node;
        ptr->data = Data;
        Node* Temp =ptrStart;
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

    Node* Search(T Data){
        Node* ptrSearch;
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

#endif
