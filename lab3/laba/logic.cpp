
#include "logic.h"

#include "ConsoleApplication1.cpp"

Logic::Logic() {

}
Logic::Logic(std::string expr) {
	this->expr = expr;
	this->showExpr();
	this->makeTable();
	this->makeResult();
	this->makePDNF();
	this->makePCNF();
	this->makeNumPDNF();
	this->makeNumPCNF();
	this->makeIndexForm();
	this->makeVars();
	this->showTable();
	this->showCarnoTable(1);
	this->showPDNF();
	this->showNumPCNF();
	this->showPCNF();
	this->showNumPDNF();
	this->showCarnoTable(1);
	this->showIndexForm();
	this->makeCarnoTable();
	this->showCarnoTable(0);
}

int Logic::getIndexForm() {
	return this->index_form;
}
string Logic::getPDNF() {
	return this->pdnf;

}
string Logic::getPCNF() {
	return this->pcnf;
}
string Logic::getVars() {
	return this->vars;

}
inline void Logic::setExpr(string str) {
	this->expr = str;
	makeResult();
	makeIndexForm();
}

void Logic::showTable() {
	for (int i = 0; i < truthTable[0].size(); i++)
	{
		for (int j = 0; j < truthTable.size(); j++)
		{
			std::cout << truthTable[j][i] << " ";
		}
		cout << endl;
	}
}
void Logic::showCarnoTable(int z) {
	if (z == 0) {
		cout << "Таблица Карно:" << endl;
		for (int j, i = 0; i < carno_table.size(); i++)
		{
			for (j = 0; j < carno_table[i].size(); j++)
			{
				cout << setw(6) << carno_table[i][j] << "| ";
			}
			cout << endl;
		}
	}
	bool operation = true;
	Node* begin = NULL;
	begin = changeForm(*this, false);
	while (operation == true)
	{
		operation = false;
		begin = glueStage(begin, *this, operation);
	}
	operation = true;
	cout << "ДНФ после:" << make_min_form(&begin, *this, false) << endl;
	begin = changeForm(*this, true);
	while (operation == true)
	{
		operation = false;
		begin = glueStage(begin, *this, operation);
	}
	cout << "КНФ после:" << make_min_form(&begin, *this, true) << endl;
	deleteAll(&begin);
}
void Logic::showExpr() {
	cout << expr << endl;
}
void Logic::showPDNF() {
	cout << "сднф: " << pdnf << endl;
}
void Logic::showPCNF() {
	cout << "скнф: " << pcnf << endl;
}
void Logic::showNumPCNF() {
	cout << "(";
	for (int num : num_pdnf) {
		cout << num << " ";
	}

	cout << ")|" << endl;
}
void Logic::showNumPDNF() {
	cout << "(";
	for (int num : num_pcnf) {
		cout << num << " ";
	}

	cout << ")&" << endl;
}
void Logic::showIndexForm() {

	cout << "Индекс: " << index_form << endl;
}

char Logic::disunction(char a, char b)
{
	return (a == '1' || b == '1') ? '1' : '0';
}
char Logic::conunction(char a, char b)
{
	return (a == '1' && b == '1') ? '1' : '0';
}
char Logic::implication(char a, char b)
{
	return (a <= b) ? '1' : '0';
}
char Logic::equivalation(char a, char b)
{
	return (a == b) ? '1' : '0';
}
char Logic::revers(char a)
{
	return (a == '1') ? '0' : '1';
}

void Logic::makeCarnoTable() {
	string vars_set, vars_before, vars_after;
	vars_set = vars;
	vars_set.insert(vars.length() / 2, "/");
	int i = 0;
	while (i < vars_set.size())
		if (vars_set[i] == '/')
			break;
		else
		{
			vars_before.push_back(vars_set[i]);
			i++;
		}
	i++;
	while (i < vars_set.size()) {
		vars_after.push_back(vars_set[i]);
		i++;
	}
	carno_table.push_back({ vars_set });
	switch (vars_before.size())
	{
	case 1:
		carno_table.push_back({ "0" });
		carno_table.push_back({ "1" });

		break;

	case 2:
		carno_table.push_back({ "00" });
		carno_table.push_back({ "01" });
		carno_table.push_back({ "11" });
		carno_table.push_back({ "10" });

		break;

	default:
		break;
	}
	switch (vars_after.size())
	{
	case 1:
		carno_table[0].push_back("0");
		carno_table[0].push_back("1");
		break;

	case 2:
		carno_table[0].push_back("00");
		carno_table[0].push_back("01");
		carno_table[0].push_back("11");
		carno_table[0].push_back("10");

		break;
	case 3:
		carno_table[0].push_back("000");
		carno_table[0].push_back("001");
		carno_table[0].push_back("011");
		carno_table[0].push_back("010");
		carno_table[0].push_back("100");
		carno_table[0].push_back("101");
		carno_table[0].push_back("111");
		carno_table[0].push_back("110");
		break;

	default:
		break;
	}
	string bin_val;
	for (int i = 1; i < carno_table.size(); i++)
	{
		for (int j = 1; j < carno_table[0].size(); j++)
		{
			carno_table[i].push_back(" ");
		}
	}
	for (int i = 1; i < truthTable[0].size(); i++)
	{
		for (int j = 0; j < truthTable.size(); j++)
		{
			bin_val += truthTable[j][i];
		}
		for (int k = 1; k < carno_table.size(); k++)
		{
			if (bin_val.substr(0, vars_before.size()) == carno_table[k][0]) {
				for (int m = 1; m < carno_table[0].size(); m++)
				{
					if (bin_val.substr(vars_before.size(), vars_after.size()) == carno_table[0][m])
					{
						carno_table[k][m] = bin_val[bin_val.size() - 1];
						break;
					}
				}
				break;
			}
		}
		bin_val.clear();
	}
}
void Logic::makeTable()
{
	bool repeat = false;
	for (int i = 0; i < expr.length(); i++)
	{
		if (isalpha(expr[i])) {
			for (int j = 0; j < truthTable.size(); j++)
			{
				if (expr[i] == truthTable[j][0])
					repeat = true;
			}
			if (repeat == false)
				truthTable.push_back({ expr[i] });

		}
	}
	for (auto& vec : truthTable)
		vec.resize(pow(2, truthTable.size()) + 1);
	for (int a, i = 1; i < truthTable[0].size(); i++)
	{
		a = i - 1;
		for (int j = truthTable.size() - 1; j >= 0; j--)
		{
			if (a != 0) {
				truthTable[j][i] = (a % 2 == 0) ? '0' : '1';
				a /= 2;
			}
			else
				truthTable[j][i] = '0';
		}
	}

}
void Logic::makeResult() {
	if (truthTable[truthTable.size() - 1][0] == '=')
		truthTable.pop_back();
	int size = truthTable.size();
	int number;
	vector<char> value(truthTable[0].size());
	Node* begin = NULL;
	for (char sign : expr)
	{
		if (isalpha(sign)) {
			for (number = 0; number < truthTable.size() && truthTable[number][0] != sign; number++) {}
			if (begin == NULL || begin->operatorS == '(') {
				begin = inNode(begin, truthTable[number]);
			}
			else
				begin = makeOperation(begin, sign, number, value);
		}
		else {
			if (sign != ')' && (begin != NULL || sign != '('))
				begin = inNode(begin, sign);
			else if (begin != NULL && begin->next != NULL && begin->next->operatorS == '(')
			{
				deleteSecondLast(&begin);
				truthTable.push_back(begin->data);
				deleteLast(&begin);
				number = truthTable.size() - 1;
				begin = makeOperation(begin, sign, number, value);
			}
		}
	}
	if (begin != NULL) {
		while (truthTable.size() != size)
			truthTable.erase(truthTable.end() - 1);
		truthTable.push_back(begin->data);
		truthTable[truthTable.size() - 1][0] = '=';
		deleteAll(&begin);
	}
}
Node* Logic::makeOperation(Node* begin, char sign, int number, vector<char> value)
{
	switch (begin->operatorS)
	{
	case '!':
		for (int i = 1; i < truthTable[0].size(); i++)
		{
			value[i] = revers(truthTable[number][i]);
		}
		deleteLast(&begin);
		if (begin != NULL && begin->operatorS != '(')
		{
			truthTable.push_back(value);
			number = truthTable.size() - 1;
			begin = makeOperation(begin, sign, number, value);
			truthTable.erase(truthTable.end() - 1);
		}
		else
			begin = inNode(begin, value);

		break;
	case '&':
		for (int i = 1; i < truthTable[0].size(); i++)
		{
			value[i] = conunction(begin->next->data[i], truthTable[number][i]);
		}
		deleteLast(&begin);
		deleteLast(&begin);
		begin = inNode(begin, value);
		break;

	case '|':
		for (int i = 1; i < truthTable[0].size(); i++)
		{
			value[i] = disunction(begin->next->data[i], truthTable[number][i]);
		}
		deleteLast(&begin);
		deleteLast(&begin);
		begin = inNode(begin, value);
		break;
	case '-':
		for (int i = 1; i < truthTable[0].size(); i++)
		{
			value[i] = implication(begin->next->data[i], truthTable[number][i]);
		}
		deleteLast(&begin);
		deleteLast(&begin);
		begin = inNode(begin, value);
		break;
	case '~':
		for (int i = 1; i < truthTable[0].size(); i++)
		{
			value[i] = equivalation(begin->next->data[i], truthTable[number][i]);
		}
		deleteLast(&begin);
		deleteLast(&begin);
		begin = inNode(begin, value);
		break;
	case '(':
		begin = inNode(begin, truthTable[number]);
		break;
	default:
		break;
	}
	return begin;
}

void Logic::makePDNF()
{
	pdnf += '(';
	for (int i = 1; i < truthTable[0].size(); i++)
		if (truthTable[truthTable.size() - 1][i] == '1')
		{
			if (pdnf != "(")
				pdnf += "|(";
			for (int j = 0; j < truthTable.size() - 1; j++) {
				if (j != truthTable.size() - 2)
					if (truthTable[j][i] == '0') {
						pdnf += '!';
						pdnf += truthTable[j][0];
						pdnf += '&';
					}
					else {
						pdnf += truthTable[j][0];
						pdnf += '&';
					}
				else if (truthTable[j][i] == '0') {
					pdnf += '!';
					pdnf += truthTable[j][0];
				}
				else
					pdnf += truthTable[j][0];
			}
			if (i != truthTable[0].size() - 1)
				pdnf += ")";
			else
				pdnf += ')';
		}
}
void Logic::makePCNF()
{
	pcnf += '(';
	for (int i = 1; i < truthTable[0].size(); i++)
		if (truthTable[truthTable.size() - 1][i] == '0')
		{
			if (pcnf != "(")
				pcnf += "&(";
			for (int j = 0; j < truthTable.size() - 1; j++) {
				if (j != truthTable.size() - 2)
					if (truthTable[j][i] == '1') {
						pcnf += '!';
						pcnf += truthTable[j][0];
						pcnf += '|';
					}
					else {
						pcnf += truthTable[j][0];
						pcnf += '|';
					}
				else if (truthTable[j][i] == '1') {
					pcnf += '!';
					pcnf += truthTable[j][0];
				}
				else
					pcnf += truthTable[j][0];
			}
			pcnf += ')';
		}
}
void Logic::makeNumPDNF() {
	int num = 0;
	for (int i = 1; i < truthTable[0].size(); i++)
		if (truthTable[truthTable.size() - 1][i] == '1')
		{
			num = 0;
			for (int deg = 0, j = truthTable.size() - 2; j >= 0; j--, deg++) {

				if (truthTable[j][i] == '1') {
					num += pow(2, deg);
				}
			}
			num_pdnf.push_back(num);

		}
}
void Logic::makeNumPCNF() {
	int num = 0;
	for (int i = 1; i < truthTable[0].size(); i++)
		if (truthTable[truthTable.size() - 1][i] == '0')
		{
			num = 0;
			for (int deg = 0, j = truthTable.size() - 2; j >= 0; j--, deg++) {

				if (truthTable[j][i] == '1') {
					num += pow(2, deg);
				}
			}
			num_pcnf.push_back(num);

		}
}
void Logic::makeIndexForm() {
	index_form = 0;
	for (int deg = 0, i = truthTable[0].size() - 1; i > 0; i--, deg++)
		if (truthTable[truthTable.size() - 1][i] == '1')
			index_form += pow(2, deg);
}
void Logic::makeVars() {
	for (int j = 0; j < truthTable.size() - 1; j++)
	{
		this->vars += truthTable[j][0];
	}
}