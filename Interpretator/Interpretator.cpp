#include <iostream>
#include <string>
#define cls system("cls");
using namespace std;
void calc(string& invisible);
int main()
{
	string visible, invisible, element;
	int count = 0, choose = 0;
	while (choose != 10)
	{
		cout << "===================================\n" << visible << "\n===================================\n";
		cout << "1.  Any letter\n2.  !\n3.  +\n4.  *\n5.  (\n6.  )\n7.  0\n8.  1\n9.  Delete last element\n10. Simplify\nChoose what do you want: ";
		while (!(cin >> choose) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Incorrect data" << endl;
		}
		switch (choose)
		{
		case 1:
		{
			cout << "Only the first counts" << endl;
			cout << "Enter the letter: ";
			string a; cin >> a;
			visible += a.substr(0, 1);
			cout << "Enter the value: "; cin >> element;
			while ((element[0] != '0') && (element[0] != '1'))
			{
				cout << "Incorrect data, you must enter only 0 or 1" << endl;
				element.clear(); cin >> element;
			}
			invisible += element.substr(0, 1); count++;
			a.clear(); element.clear(); cls;
		}; break;
		case 2: { visible.push_back('!'); invisible.push_back('!'); cls; }; break;
		case 3: { visible.push_back('+'); invisible.push_back('+'); cls; }; break;
		case 4: { visible.push_back('*'); invisible.push_back('*'); cls; }; break;
		case 5: { visible.push_back('('); invisible.push_back('('); cls; }; break;
		case 6: { visible.push_back(')'); invisible.push_back(')'); cls; }; break;
		case 7: { count++; visible.push_back('0'); invisible += '0'; cls; }; break;
		case 8: { count++; visible.push_back('1'); invisible += '1'; cls; }; break;
		case 9:
		{
			visible.erase(visible.length() - 1, 1); invisible.erase(invisible.length() - 1, 1);
			if ((visible[visible.length() - 1] != '(') || (visible[visible.length() - 1] != ')') || (visible[visible.length() - 1] != '+') || (visible[visible.length() - 1] != '!') || (visible[visible.length() - 1] != '*'))
			{
				count--;
			}
		}; break;
		case 10:
		{
			int temp1 = 0, temp2 = 0;
			while (invisible.find('(') != string::npos)
			{
				for (size_t i = 1; i < strlen(invisible.c_str()); i++)
				{
					for (size_t i = 0; i < invisible.size(); i++)
					{
						if (visible[i] == '(') { temp1 = i; }
						if (visible[i] == ')') { temp2 = i; goto next; }
					}
				}
			next:
				int temp_1 = temp1 + 1, temp_2 = temp2 - temp1 - 1;
				string tempo; tempo.assign(invisible, temp_1, temp_2);
				calc(tempo); temp_2 = temp_2 + 2;
				invisible.replace(temp1, temp_2, tempo);
			}
			calc(invisible); cout << "===================================\n" << visible << "=" << invisible << endl; system("pause"); cls; }; break;
		default:cout << "Inknown command" << endl; break;
		}
	}
}

void calc(string& invisible)
{
no:
	while (invisible.find('!') != string::npos)
	{
		if (invisible[invisible.find('!') + 1] == '1') invisible.replace(invisible.find('!'), 2, "0");
		else invisible.replace(invisible.find('!'), 2, "1"); goto no;
	}
multiply:
	while (invisible.find('*') != string::npos)
	{
		if ((invisible[invisible.find('*') + 1] == '1') && (invisible[invisible.find('*') - 1] == '1'))
			invisible.replace(invisible.find('*') - 1, 3, "1");
		else invisible.replace(invisible.find('*') - 1, 3, "0"); goto multiply;
	}
addition:
	while (invisible.find('+') != string::npos)
	{
		if ((invisible[invisible.find('+') + 1] == '0') && (invisible[invisible.find('+') - 1] == '0'))
			invisible.replace(invisible.find('+') - 1, 3, "0");
		else invisible.replace(invisible.find('+') - 1, 3, "1"); goto addition;
	}
}