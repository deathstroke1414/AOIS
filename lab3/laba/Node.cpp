#include <iostream>
#include <vector>

using namespace std;


struct Node {
    vector<char> data;  // ������
    char operatorS = NULL;  // ��������
    Node* next = NULL;  // ��������� �� ��������� ����
};

//  ���������� ������ ���� � ������ 
inline Node* inNode(Node* newN, vector<char> data, char flag) {
    Node* top = new Node;
    top->data = data;
    top->operatorS = flag;
    top->next = newN;
    return top;
}

//  �������� ���� �����
inline void deleteAll(Node** newN) {
    Node* top;
    while (*newN != nullptr) {
        top = *newN;
        *newN = (*newN)->next;
        delete top;
    }
}

// �������� ������� � ����� ����
inline void deleteSecondLast(Node** newN) {
    Node* top = (*newN)->next;
    (*newN)->next = (*newN)->next->next;
    delete top;
}

//  �������� ���������� ����
inline void deleteLast(Node** newN) {
    Node* top;
    top = *newN;
    *newN = (*newN)->next;
    delete top;
}

//  ����� �����������
inline void view(Node* begin) {
    if (begin == nullptr) {
        cout << "�����" << endl;
        return;
    }
    cout << "��������:";
    while (begin != nullptr) {
        for (int i = 0; i < begin->data.size(); i++) {
            cout << begin->data[i];
        }
        cout << " ";
        begin = begin->next;
    }
    cout << endl;
}

// ���������� ����� �����

inline Node* inNode(Node* newN, vector<char> data) {
    Node* top = new Node;
    top->data = data;
    top->next = newN;
    return top;
}
// ���������� ����� �����
inline Node* inNode(Node* newN, char data) {
    Node* top = new Node;
    top->operatorS = data;
    top->next = newN;
    return top;
}
