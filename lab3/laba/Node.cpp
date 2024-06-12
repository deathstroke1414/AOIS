#include <iostream>
#include <vector>

using namespace std;


struct Node {
    vector<char> data;  // данные
    char operatorS = NULL;  // оператор
    Node* next = NULL;  // указатель на следующий узел
};

//  добавление нового узла в начало 
inline Node* inNode(Node* newN, vector<char> data, char flag) {
    Node* top = new Node;
    top->data = data;
    top->operatorS = flag;
    top->next = newN;
    return top;
}

//  удаление всех узлов
inline void deleteAll(Node** newN) {
    Node* top;
    while (*newN != nullptr) {
        top = *newN;
        *newN = (*newN)->next;
        delete top;
    }
}

// удаление второго с конца узла
inline void deleteSecondLast(Node** newN) {
    Node* top = (*newN)->next;
    (*newN)->next = (*newN)->next->next;
    delete top;
}

//  удаление последнего узла
inline void deleteLast(Node** newN) {
    Node* top;
    top = *newN;
    *newN = (*newN)->next;
    delete top;
}

//  вывод содержимого
inline void view(Node* begin) {
    if (begin == nullptr) {
        cout << "пусто" << endl;
        return;
    }
    cout << "элементы:";
    while (begin != nullptr) {
        for (int i = 0; i < begin->data.size(); i++) {
            cout << begin->data[i];
        }
        cout << " ";
        begin = begin->next;
    }
    cout << endl;
}

// добавление новых узлов

inline Node* inNode(Node* newN, vector<char> data) {
    Node* top = new Node;
    top->data = data;
    top->next = newN;
    return top;
}
// добавление новых узлов
inline Node* inNode(Node* newN, char data) {
    Node* top = new Node;
    top->operatorS = data;
    top->next = newN;
    return top;
}
