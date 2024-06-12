#pragma once
#include <cmath>
#include "Node.cpp"
#include <string>
#include <algorithm>
#include <iomanip>


using namespace std;

class Logic
{
public:
	vector<vector<char>> truthTable;
	Logic(string expr);
	Logic();
	void setExpr(string str);
	int getIndexForm();
	string getPCNF();
	string getPDNF();
	string getVars();
	void showTable();
	void showCarnoTable(int z);
	void showExpr();
	void showPDNF();
	void showPCNF();
	void showNumPCNF();
	void showNumPDNF();
	void showIndexForm();
	string pdnf;

	string vars;

	vector<vector<string>> carno_table;
	int index_form = 0;
	string expr;
	string pcnf;
	vector<int> num_pdnf;
	vector<int> num_pcnf;

	void makePDNF();
	void makePCNF();
	void makeNumPDNF();
	void makeNumPCNF();
	void makeIndexForm();
	void makeVars();
	void makeCarnoTable();
	void makeTable();
	void makeResult();
	Node* makeOperation(Node* begin, char sign, int number, vector<char> value);
	char disunction(char a, char b);
	char conunction(char a, char b);
	char implication(char a, char b);
	char equivalation(char a, char b);
	char revers(char a);

private:
};