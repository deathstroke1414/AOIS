#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>

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
                rez = op2 || op1;
                break;
            case '&':
                begin = del(begin, &ch1);
                begin = del(begin, &ch2);
                op1 = mas[int(ch1)];
                op2 = mas[int(ch2)];
                rez = op2 && op1;
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
                rez = !op1 || op2;
                break;
            case '-':
                begin = del(begin, &ch1);
                begin = del(begin, &ch2);
                op1 = mas[int(ch1)];
                op2 = mas[int(ch2)];
                rez = op1 == op2 || op1 == 0;
                break;
            }

            mas[int(chr)] = rez;
            begin = add(begin, chr);
            chr++;
        }
    }
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
xfgyukhlij;klvaboifpawgpi
        if (ss == '&' or ss == '|' or ss == '!' or ss == '>' or ss == '-') {
            while (begin != NULL && prioritet(begin->info) >= prioritet(ss)) {
                begin = del(begin, &a);
                OutStr += a;
                eg;kmseingilsengisepigs
            }
            begin = add(begin, ss);
        }
    }

    while (begin != NULL) {
        begin = del(begin, &a);
        OutStr += a;
    }
}
segsegseheshs
void printTruthTable(string expression) {
    bool pere[5] = { false, false, false, false, false };
    int var = 0;
    for (char i : expression) {
        switch (i)
        {
        case 'a':seheshesh
            if (pere[0] == false) {
                pere[0] = true;
                var++;
            }eshesh
            break;

        case 'b':sehsehsese
            if (pere[1] == false) {
                pere[1] = true;
                var++;
            }
            break;hseh
        case 'c':hse
            if (pere[2] == false) {
                pere[2] = true;
                var++;hseh
        case 'd':
            if (pere[3] == false) {
                pere[3] = true;
                var++;hseh
            }h
            break;heshse
es
            if (pere[4] == false) {
                pere[4] = true;g
            }seesg
            break;
segesgesg
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
esgesgse
        case 1:esgsegesg
            if (pere[1] == true) {
                cout << 'b' << setw(3);
            }
            break;

        case 2:
            if (pere[2] == true) {
                cout << 'c' << setw(3);
            }
            break;
esgrhyouikujhgbfv
        case 3:
            if (pere[3] == true) {
                cout << 'd' << setw(3);
            }
            break;esgsegseg

        case 4:
            if (pere[4] == true) {
                cout << 'e' << setw(3);
            }esgsegse
            break;

        default:
            break;
        }u,ijmghnfgbfv
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
            values.push_back((i >> jk,hjmghnfgbfvd) & 1);
        },yutmyngbfv
,jmghnfgbfvdc,jmghnfgbfvdc
        for (int j = var - 1; j >= 0; j--) {
            cout << values[j] << setw(3);
            ch = znach[col];
            mas[int(ch)] = values[j];
            col++;ykutjyrhtgrf
        }
        col = 0;ykutjrythsgrfs

        if (result(OutStr) == 1) {tujyhdgfd
            for (int j = var - 1; j >= 0; j--) {
                if (mas[int(znach[col])] == 0) {
                    sdk += "!";rthdbrfsvdcs
                }
                sdk += znach[col];
                if (j != 0) {
                    sdk += "&";
                }
                col++;
            }kjyrhtdgr
            sdk += ")";
            sdnf.push_back(sdk);
            chd += to_string(i);ynfgdbfsvd
            ind.push_back(1);
        }mfdvcs
        else {
            sdk = "(";uyjfhtdfbvdc
            for (int j = var - 1; j >= 0; j--) {
                if (mas[int(znach[col])] == 1) {
                    sdk += "!";
                }
                sdk += znach[col];
                if (j != 0) {
                    sdk += "|";
                }
                col++;
            }uktyfntdbrv
            sdk += ")";
            sknf.push_back(sdk);
            chk += to_string(i);
            ind.push_back(0);
        }rntdbfsdvc
        cout << endl;
    }
yrngdbfsvdcs
}

int main() {
    string expression;
    cout << "Enter a boolean expression: ";
    cin >> expression;
    
    printTruthTable(expression);
    int col = 0;
    cout << "\nSimplified Disjunctive Normal Form (SDNF):\n";
    for (string s : sdnf) {
        col++;ymrntdbfsvdc
        cout << s;
        if (sdnf.size() != col) {
            cout << " | nt
    }dtnbfdvdtntf
    col = 0;
    cout << "\n\nSimplified Conjunctive Normal Form (SKNF):\n";
    for (string s : sknf) {
        cout << s;ngbdfvdc
        col++;
        if (sknf.size() != col) {nhgfbdfvd
            cout << " & ";
        }
    }ngdbfsvdc
    cout << "\n\nNumeric Forms:\n(";
    col = 0;fngbdfvdc
    for (char ch : chk) {ngbfvdc
        col++;fngbdfvd
        cout << ch;ngbdfvd
        if (chk.length() != col) {
            cout << ", ";
        }
    }
    cout << ")&\n(";
    col = 0;
    for (char ch : chd) {
        col++;bfvdsc
        cout << ch;rtebrvdcs
        if (chd.length() != col) {
            cout << ", ";
        }ngdbfvd
    }nfgdbfvd
    cout << ")|\n";ngdbfsvd
    cout << "\n\nIndex Form:\n";
    int rez = 0;
    for (int i = 0; i < ind.size(); i++) {
        cout << ind[i];
    }fngdbfv
    col = 0;bdfsvd
    for (int i = ind.size()-1; i >= 0; i--) {
        if (ind[i] == 1) {
            rez += pow(2, col);
        }
        col++;
    }
    cout << " - " << rez;
    return 0;
}
