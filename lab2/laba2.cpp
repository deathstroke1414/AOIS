#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
#include <Windows.h>

using namespace std;

struct Stack {
    char info;
    Stack* next;
};

vector<string> sdnf;
vector<string> sknf;
string chd;
string chk;

bool mas[201];
vector<bool> ind;
char znach[] = { 'a', 'b', 'c', 'd', 'e' };
string OutStr;

Stack* del(Stack* p, char* out) {
    Stack* t = p;
    (*out) = p->info;
    p = p->next;
    delete t;
    return p;
}

Stack* add(Stack* p, char in) {
    Stack* t = new Stack;
    t->info = in;
    t->next = p;
    return t;
}


int prioritet(char a) {
    switch (a) {
    case '!': return 5;
    case '>': case '-': return 2;
    case '&': return 4;
    case '|': return 3;
    case '(': return 1;
    }
    return 0;
}

bool result(string opz) {
    Stack* begin = NULL;
    char ch, ch1 = ' ', ch2 = ' ';
    bool op1 = 0, op2 = 0, rez = 0;
    char chr = 'e' + 1;
    for (int i = 0; i < opz.size(); i++) {
        ch = opz[i];
        //cout << ch << " ";
        if (ch >= 'a' && ch <= 'e') {
            begin = add(begin, ch);
        }
        else {
            switch (ch) {
            case '|':
                begin = del(begin, &ch1);
                begin = del(begin, &ch2);
                op1 = mas[int(ch1)];
                op2 = mas[int(ch2)];
                rez = op2 + op1;

                break;
            case '&':
                begin = del(begin, &ch1);
                begin = del(begin, &ch2);
                op1 = mas[int(ch1)];
                op2 = mas[int(ch2)];
                rez = op2 * op1;
                break;
            case '!':
                begin = del(begin, &ch1);
                op1 = mas[int(ch1)];
                rez = !op1;
                break;
            case '>':
                begin = del(begin, &ch1);
                begin = del(begin, &ch2);
                op1 = mas[int(ch1)];
                op2 = mas[int(ch2)];
                rez = op2 || !op1;
                break;
            case '-':
                begin = del(begin, &ch1);
                begin = del(begin, &ch2);
                op1 = mas[int(ch1)];
                op2 = mas[int(ch2)];
                if (op1 == op2) {
                    rez = 1;
                }
                else if (op2 == 0 and op1 == 1) {
                    rez = 1;
                }
                else {
                    rez = 0;
                }
                //cout << op2 << " = " << op1 << " == " << rez;
                break;
            }

            mas[int(chr)] = rez;
            begin = add(begin, chr);
            chr++;
        }
    }
    cout << setw(5) << rez;
    return rez;
}

void evaluate(string res) {
    int len = res.size(), k;
    Stack* begin = NULL;
    char ss;
    char a = ' ';
    for (k = 0; k < len; k++) {
        ss = res[k];
        if (ss == '(')
            begin = add(begin, ss);
        if (ss == ')') {

            while ((begin->info) != '(') {
                begin = del(begin, &a);
                OutStr += a;
            }
            begin = del(begin, &a);
        }

        if (ss >= 'a' && ss <= 'e') {
            OutStr += ss;
        }

        if (ss == '&' or ss == '|' or ss == '!' or ss == '>' or ss == '-') {
            while (begin != NULL && prioritet(begin->info) >= prioritet(ss)) {
                begin = del(begin, &a);

                OutStr += a;
            }
            begin = add(begin, ss);
        }
    }

    while (begin != NULL) {
        begin = del(begin, &a);
        OutStr += a;
    }
    //cout << "    " << OutStr << "       ";
}

void printTruthTable(string expression) {
    bool pere[5] = { false, false, false, false, false };
    int var = 0;
    for (char i : expression) {
        switch (i)
        {
        case 'a':
            if (pere[0] == false) {
                pere[0] = true;
                var++;
            }
            break;

        case 'b':
            if (pere[1] == false) {
                pere[1] = true;
                var++;
            }
            break;

        case 'c':
            if (pere[2] == false) {
                pere[2] = true;
                var++;
            }
            break;

        case 'd':
            if (pere[3] == false) {
                pere[3] = true;
                var++;
            }
            break;

        case 'e':
            if (pere[4] == false) {
                pere[4] = true;
                var++;
            }
            break;

        default:
            break;
        }
    }
    int combinations = pow(2, var);
    for (int i = 0; i < var; i++) {
        switch (i)
        {
        case 0:
            if (pere[0] == true) {
                cout << 'a' << setw(3);
            }
            break;

        case 1:
            if (pere[1] == true) {
                cout << 'b' << setw(3);
            }
            break;

        case 2:
            if (pere[2] == true) {
                cout << 'c' << setw(3);
            }
            break;

        case 3:
            if (pere[3] == true) {
                cout << 'd' << setw(3);
            }
            break;

        case 4:
            if (pere[4] == true) {
                cout << 'e' << setw(3);
            }
            break;

        default:
            break;
        }
    }
    cout << setw(10) << expression << endl;
    evaluate(expression);
    for (int i = 0; i < 18 + 4 * var; i++) {
        cout << '-';
    }
    cout << endl;
    char ch;
    int col;
    string sdk = "";
    for (int i = 0; i < combinations; i++) {
        vector<bool> values;
        col = 0;
        for (int j = 0; j < var; j++) {
            values.push_back((i >> j) & 1);
        }

        for (int j = var - 1; j >= 0; j--) {
            cout << values[j] << setw(3);
            ch = znach[col];
            mas[int(ch)] = values[j];
            col++;
        }
        col = 0;

        if (result(OutStr) == 1) {
            sdk = "(";
            for (int j = var - 1; j >= 0; j--) {
                if (mas[int(znach[col])] == 0) {
                    sdk += "!";
                }
                sdk += znach[col];
                if (j != 0) {
                    sdk += "&";
                }
                col++;
            }
            sdk += ")";
            sdnf.push_back(sdk);
            chd += to_string(i);
            ind.push_back(1);
        }
        else {
            sdk = "(";
            for (int j = var - 1; j >= 0; j--) {
                if (mas[int(znach[col])] == 1) {
                    sdk += "!";
                }
                sdk += znach[col];
                if (j != 0) {
                    sdk += "|";
                }
                col++;
            }
            sdk += ")";
            sknf.push_back(sdk);
            chk += to_string(i);
            ind.push_back(0);
        }
        cout << endl;
    }

}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string expression;
    cout << "Вводим функцию\n";
    cin >> expression;
    expression = "a|!(b&c)";
    cout << endl;
    
    printTruthTable(expression);
    int col = 0;
    cout << "\nСовершенная дизъюнктивная нормальная форма (СДНФ):\n";
    for (string s : sdnf) {
        col++;
        cout << s;
        if (sdnf.size() != col) {
            cout << " | ";
        }
    }
    col = 0;
    cout << "\n\nСовершенная конъюнктивная нормальная форма (СKНФ):\n";
    for (string s : sknf) {
        cout << s;
        col++;
        if (sknf.size() != col) {
            cout << " & ";
        }
    }
    cout << "\n\nЧисловые формы:\n(";
    col = 0;
    for (char ch : chk) {
        col++;
        cout << ch;
        if (chk.length() != col) {
            cout << ", ";
        }
    }
    cout << ")&\n(";
    col = 0;
    for (char ch : chd) {
        col++;
        cout << ch;
        if (chd.length() != col) {
            cout << ", ";
        }
    }
    cout << ")|\n";
    cout << "\n\nИндексная форма:\n";
    int rez = 0;
    for (int i = 0; i < ind.size(); i++) {
        cout << ind[i];
    }
    col = 0;
    for (int i = ind.size()-1; i >= 0; i--) {
        if (ind[i] == 1) {
            rez += pow(2, col);
        }
        col++;
    }
    cout << " - " << rez;
    return 0;
}
