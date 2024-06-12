#include "logic.h"



inline Node* changeForm(Logic a, bool flag)
{
	Node* begin = NULL;
	vector<char> el_expr;
	string new_form;
	if (flag == true)
		new_form = a.getPDNF();
	else
		new_form = a.getPCNF();
	new_form.erase(std::remove_if(new_form.begin(), new_form.end(), [](char c) {
		return c == '(' || c == ')' || c == '&' || c == '|';
		}), new_form.end());
	for (int i = 0, j; i < new_form.size() - 1; )
	{
		for (j = 0; el_expr.size() != a.getVars().size(); j++)
		{
			if (isalpha(new_form[i + j]))
			{
				el_expr.push_back('1');
			}
			else
			{
				el_expr.push_back('0');
				j++;
			}

		}
		i += j;
		begin = inNode(begin, el_expr, '-');
		el_expr.clear();
	}
	return begin;
}
inline Node* glueStage(Node* begin, Logic a, bool& operation) {
	Node* newbegin = NULL;
	vector<char> el_expr;
	while (begin != NULL)
	{
		Node* t = begin->next;
		while (t != NULL)
		{
			int mistake = 0;
			for (int i = 0; i < a.getVars().size(); i++)
			{
				if (begin->data[i] == t->data[i])
					el_expr.push_back(begin->data[i]);
				else
				{
					mistake++;
					if (mistake == 1) {
						el_expr.push_back('x');
					}
					else
					{
						el_expr.clear();
						break;
					}
				}
			}

			if (el_expr.size() != 0 && mistake != 0)
			{
				operation = true;
				begin->operatorS = '+';
				t->operatorS = '+';
				newbegin = inNode(newbegin, el_expr, '-');
			}
			if (mistake == 0)
				begin->operatorS = '+';
			t = t->next;
			el_expr.clear();
			mistake = 0;
		}
		if (begin->operatorS == '+')
		{
			deleteLast(&begin);
		}
		else
		{
			newbegin = inNode(newbegin, begin->data, '-');
			deleteLast(&begin);
		}
	}
	return newbegin;
}
inline string make_pdnf_form(Node* begin, Logic a)
{
	string pdnf;
	Node* t = begin;
	while (t != NULL)
	{
		pdnf += '(';
		for (int i = 0; i < t->data.size(); i++) {
			switch (t->data[i])
			{
			case '0':
				pdnf += '!';
				pdnf += a.getVars()[i];
				break;
			case '1':
				pdnf += a.getVars()[i];
				break;
			default:
				break;
			}
			if (isalpha(pdnf.back()))
				pdnf += '&';
		}
		if (pdnf.back() == '&')
			pdnf.pop_back();
		pdnf += ")|";
		t = t->next;
	}
	pdnf.pop_back();

	return pdnf;
}
inline string make_pcnf_form(Node* begin, Logic a)
{
	string pcnf;
	Node* t = begin;
	while (t != NULL)
	{
		pcnf += '(';
		for (int i = 0; i < t->data.size(); i++) {
			switch (t->data[i])
			{
			case '0':
				pcnf += '!';
				pcnf += a.getVars()[i];
				break;
			case '1':
				pcnf += a.getVars()[i];
				break;
			default:
				break;
			}
			if (isalpha(pcnf.back()))
				pcnf += '|';
		}
		if (pcnf.back() == '|')
			pcnf.pop_back();
		pcnf += ")&";
		t = t->next;
	}
	if (!pcnf.empty())
		pcnf.pop_back();

	return pcnf;
}
inline string make_min_form(Node** begin, Logic a, bool flag)
{
	Logic b;
	b.truthTable = a.truthTable;
	Node* t = NULL, * lt = NULL;
	while (*begin != NULL) {
		t = *begin;
		*begin = t->next;
		if (flag == true)
			b.setExpr(make_pdnf_form(*begin, a));
		else
			b.setExpr(make_pcnf_form(*begin, a));
		if (b.getIndexForm() != a.getIndexForm())
		{
			*begin = t;
			break;
		}
		else {
			t->next = NULL;
			delete t;
		}

	}
	while (t->next != NULL)
	{
		lt = t;
		t = t->next;
		lt->next = t->next;
		if (flag == true)
			b.setExpr(make_pdnf_form(*begin, a));
		else
			b.setExpr(make_pcnf_form(*begin, a));
		if (b.getIndexForm() != a.getIndexForm()) {
			lt->next = t;
		}
		else
		{
			t->next = NULL;
			delete t;
			t = lt;
		}
	}
	if (flag == true)
		return make_pdnf_form(*begin, a);
	else
		return make_pcnf_form(*begin, a);

}

inline void show_calc_table(vector<vector<string>> table, string expr, string not_vertix_form, bool type) {
	if (type)
		cout << "ДНФ до верификации:";
	else
		cout << "кнф до верификации:";
	cout << not_vertix_form << endl;;
	cout << "Таблица:" << endl;
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[0].size(); j++)
		{
			cout << setw(15) << table[i][j] << "|";
		}
		cout << endl;
	}
	if (type)
		cout << "ДНФ после верификации:";
	else
		cout << "КНФ после верификации:";
	cout << expr << endl;
}
inline vector<vector<string>> create_table_form(Logic a, Node* begin, vector<vector<string>> table, string& not_verif_form, string expr, bool type) {
	if (type == true) {
		not_verif_form = make_pdnf_form(begin, a);
		for (int j = 0; j < a.getPDNF().size(); j++)
		{
			if (a.getPDNF()[j] != ')')
				expr += a.getPDNF()[j];
			else {
				expr += ')';
				j++;
				table[0].push_back(expr);
				expr.clear();
			}

		}
	}
	else {
		not_verif_form = make_pcnf_form(begin, a);

		for (int j = 0; j < a.getPCNF().size(); j++)
		{
			if (a.getPCNF()[j] != ')')
				expr += a.getPCNF()[j];
			else {
				expr += ')';
				j++;
				table[0].push_back(expr);
				expr.clear();
			}

		}
	}
	for (int j = 0; j < not_verif_form.size(); j++)
	{
		if (not_verif_form[j] != ')')
			expr += not_verif_form[j];
		else {
			expr += ')';
			j++;
			table.push_back({ expr });
			expr.clear();
		}

	}
	return table;
}
inline string make_table_form(Logic a, Node* begin, bool type) {
	vector<vector<string>> table;
	table.push_back({ " " });
	string expr;
	bool flag;
	string not_verif_form;
	vector<string> vars;
	table = create_table_form(a, begin, table, not_verif_form, expr, type);
	for (int i = 1; i < table.size(); i++)
	{
		vars.push_back("");
		for (int k = 1; k < table[i][0].size(); k++)
		{
			if (isalpha(table[i][0][k])) {
				if (table[i][0][k - 1] == '(' && a.getVars()[0] != table[i][0][k])
				{
					vars[vars.size() - 1] += (type) ? '&' : '|';
					vars[vars.size() - 1] += table[i][0][k];
				}
				else {
					vars[vars.size() - 1] += table[i][0][k - 1];
					vars[vars.size() - 1] += table[i][0][k];
				}
				vars.push_back("");
			}

		}
		if (!vars.empty())
			vars.pop_back();
		for (int j = 1; j < table[0].size(); j++)
		{
			table[i].push_back("");
			flag = true;
			for (int k = 0; k < vars.size(); k++)
				if (table[0][j].find(vars[k]) == std::string::npos)
					flag = false;
			if (flag == true)
				table[i][j] = "X";
			else
				table[i][j] = "O";

		}
		if (!vars.empty())
			vars.clear();
	}
	for (int i = 1, coord = 0, j; i < table[0].size(); i++)
	{
		j = 1;
		for (int k = 0; j < table.size(); j++)
		{
			if (k <= 1) {
				if (table[j][i] == "X")
				{
					k++;
					coord = j;
				}
			}
			else
				break;
		}
		if (j = table.size() && expr.find(table[coord][0]) == std::string::npos) {
			expr += table[coord][0];
			if (type)
				expr += '|';
			else
				expr += '&';
		}
	}
	if (!expr.empty())
		expr.pop_back();
	show_calc_table(table, expr, not_verif_form, type);
	return expr;
}

inline void calculation_method(Logic a) {
	bool operation = true;
	Node* begin = NULL;
	begin = changeForm(a, true);
	while (operation == true)
	{
		operation = false;
		begin = glueStage(begin, a, operation);
	}
	operation = true;
	cout << "Расчетный метод:\n";
	cout << "ДНФ до:" << make_pcnf_form(begin, a) << endl;
	cout << "ДНФ после:" << make_min_form(&begin, a, true) << endl;
	begin = changeForm(a, false);
	while (operation == true)
	{
		operation = false;
		begin = glueStage(begin, a, operation);
	}
	cout << "КНФ до:" << make_pdnf_form(begin, a) << endl;
	cout << "КНФ после:" << make_min_form(&begin, a, false) << endl;
	deleteAll(&begin);
}

inline void calculation_table_method(Logic a) {
	bool operation = true;
	Node* begin = NULL;
	begin = changeForm(a, true);
	while (operation == true)
	{
		operation = false;
		begin = glueStage(begin, a, operation);
	}
	operation = true;
	make_table_form(a, begin, true);
	begin = changeForm(a, false);
	while (operation == true)
	{
		operation = false;
		begin = glueStage(begin, a, operation);
	}
	make_table_form(a, begin, false);
	deleteAll(&begin);
}