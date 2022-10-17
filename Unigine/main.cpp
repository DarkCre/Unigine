#include <iostream> //���������� ���������� ��� ������ � ������ � ������� (# - �������� ��� ��� ������ ��� ����� � ������������).
#include <conio.h> // ���������� ��� ��������, �� ������� �������
#include <fstream>// ���� � ���� � ����� �� �����
#include <string>
#include <unordered_map>

//��������� �� ��������� ����������� ������������ ��� (std), ��� ����, ��� �� �� ��������� ����� ���������� ������� ������������ ������ ���.
using namespace std;

//��� ���������
struct Pipe //�������� ��������� �����
{
	double PipeLength; // ����� �����
	double PipeDia;   //  ������� �����
	bool PipeStatus; //   ������ ����� (� ������� ��� ���)
};

struct Cs //�������� ��������� ������������� �������
{
	string CsName; //�������� ��
	int CsWorkshop; //���������� ����� ��
	int CsWorkingWorkshops; //���������� ���������� ����� ��
	int CsEffectiveness; //������������� ��
};

//�������� ����� ������ ����� ������
	//�������� �� ������������ ����� ���������� ���� int (� ��� ����� � �������������) � ������������� double
template <typename T>
bool CheckingIntAndPositiveDouble(const T& Variable, const T& beginning = numeric_limits<T>::min(), const T& end = numeric_limits<T>::max(), istream& in=cin)
// ������ ���� ��������, � ��� �� �������� � ������� ��� ������ ����������. ���� �� ����� �������� ��� ���������, �� ��� �������� ����� �����
// ����������� ��� ������� ���� ������ ���������. �.�. � ������ ���� ������ �����, ������� ������ ������, �� ������� ������, ������ ���� �
// ������� ������� ��������, �� ����� ������������ �������� �� ��, ������ �� �������� � ����.
// https://stackoverflow.com/questions/1855459/maximum-value-of-int
// http://studlab.com/news/parameiry_po_umolchaniju_i_peremennoe_chislo_parametrov_v_c/2013-06-22-766
{
	if (in.fail() || in.peek() != '\n' || Variable<beginning || Variable>end)
	{
		in.clear();
		in.ignore(1000, '\n');
		cout << "������� ����������� ������, ����������, ������� ����� �� " << beginning << " �� " << end << endl << endl; 
		return false;
	}

	return true;
}
//���� �� ����� � �������� Int � ������������� double �� �����
template <typename T>
bool ReadingFile_CheckingIntAndDouble(ifstream& fin, T& Variable)
{
	return CheckingIntAndPositiveDouble(Variable, numeric_limits<T>::min(), numeric_limits<T>::max(), fin);	
}
//�������� ������� ������ �� ������
bool CheckingStringInBool(const string& String, bool& Bool, const string& Meaning, bool Mute=true)
{
	char ch;
	cin >> ch;
	CheckingIntAndPositiveDouble(ch, '0', '1');
	if ((String.find_first_not_of("01") == string::npos) == true && String.length() == 1)
	{
		if (String[0] == '1') { Bool = 1; return true; }
		else if (String[0] == '0') { Bool = 0; return true; }
	}
	else
	{
		if (!Mute)
		{ 
			cout << "������� ����������� �����, ����������, ������� 0 ��� 1." << endl; 
		}
		return false;
	}
}

//������������� ��������
bool �onfirmationSaving()
{
	double check = 0;
	cin >> check;////!!!!!!!!!!!!!!!!!CheckingIntAndPositiveDouble
	if (check == 1.)
		return true;
	else
		return false;
}

//���� �����
	//���� ������� �����
void InputPipeStatusCheck(bool& PipeStatus)
{
	string strBool = "";
	do//���������� ������� �����
	{
		cout << "������� ������ ����� (� ������� - 0, � ��������������� ��������� - 1): " << endl;
		cin >> strBool;
	} while (CheckingStringInBool(strBool, PipeStatus, "console") == false);
}
//�������� ������������ ��������� ����� (�� ��������� ���������) ytn
bool PipeInspection(const Pipe& p)
{
	return CheckingIntAndPositiveDouble(p.PipeLength) &&
		CheckingIntAndPositiveDouble(p.PipeDia);

}
//���� �����
void InputPipe(unordered_map<int, Pipe>& MapP)
{
	Pipe p = {};

	cout << "1.�������� �����:" << endl << endl;
	do//���������� ����� �����
	{
		cout << "������� ����� ����� (XX,XX):" << endl;
		cin >> p.PipeLength;
	} while (CheckingIntAndPositiveDouble(p.PipeLength) == false);
	do//���������� �������� �����
	{
		cout << "������� ������� �����:" << endl;
		cin >> p.PipeDia;
	} while (CheckingIntAndPositiveDouble(p.PipeDia) == false);

	InputPipeStatusCheck(p.PipeStatus);

	MapP.emplace(MapP.size() + 1, p);
}

//���� �� ytn
//���� ���������� �� ytn
void InputCsParameters(Cs& cs)
{
	cout << "2.�������� ������������� �������: " << endl << endl;
	//���������� ����� ��
	cout << "������� �������� ������������� ������� (�� ��������� �����):" << endl;
	cin>>ws;
	getline(cin, cs.CsName);
	do//���������� ���������� ����� ��
	{
		cout << "������� ���������� ����� ������������� �������:" << endl;
		cin >> cs.CsWorkshop;
		if (cs.CsWorkshop <= 0)
		{
			cout << "����� ������ ���� �� ������ 1, ����������, ��������� ������� �����." << endl;
		}
	} while (!CheckingIntAndPositiveDouble(cs.CsWorkshop, 0));
	do//���������� ���������� ������� ����� ��
	{
		cout << "������� ���������� ���������� �����:" << endl;
		cin >> cs.CsWorkingWorkshops;
	} while (!CheckingIntAndPositiveDouble(cs.CsWorkingWorkshops, 0, cs.CsWorkshop));
	do//���������� ������������� ��
	{
		cout << "������� ������������� �������:" << endl;
		cin >> cs.CsEffectiveness;
	} while (CheckingIntAndPositiveDouble(cs.CsEffectiveness, -100, 100) == false);
}
//�������� ������������ ��������� �� (�� ��������� ���������) ytn
bool CsInspection(const Cs& cs)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	if ((CheckingIntAndPositiveDouble(cs.CsWorkshop) == false || cs.CsWorkshop <= 0) == true ||
		(CheckingIntAndPositiveDouble(cs.CsWorkingWorkshops, 0, cs.CsWorkshop) == false) == true ||
		(CheckingIntAndPositiveDouble(cs.CsEffectiveness, -100, 100) == false) == true)
	{
		return false;
	}
}
//���� �� ytn
void InputCs(Cs& cs) //������ �� ���������� ���� ������ �� ������������� ������� � ������������������ �� �����
{
	if (cs.CsWorkshop != 0)
	{
		cout << "�� �������, ��� ������ ������������ ������ �� ������������� �������?" << endl
			<< "������� 1 ��� ������������� ��������." << endl;
		if (!�onfirmationSaving())
			return;
	}
	InputCsParameters(cs);
}

//����� ���������� �� ��������� ytn
void InformationOutput(const Pipe& p, const Cs& cs) //����� ���������� �� ����� � ��
{
	cout << "3.���������� �� �����:" << endl;
	if (p.PipeLength != 0)
		cout << endl << "����� �����: " << p.PipeLength << endl
		<< "������� �����: " << p.PipeDia << endl
		<< "������ �����: " << (p.PipeStatus  ? "� ������" : "� �������") << endl;
	else { cout << "������ �� �������. ������� ���������� ������� �����." << endl; }

	cout << endl << "3.���������� �� ������������� �������:" << endl << endl;
	if (cs.CsWorkshop != 0)
	{
		cout << "��������: " << cs.CsName << endl
			<< "���������� �����: " << cs.CsWorkshop << endl
			<< "���������� ����� � ������: " << cs.CsWorkingWorkshops << endl
			<< "�������������: " << cs.CsEffectiveness << endl;
		cout << endl << "������� ����� ������� ��� �����������." << endl;
		_getch();//https://www.youtube.com/watch?v=6tGgasGBgmc - ������� �������� ������� ����� ������� 
	}
	else
	{
		cout << "������ �� �������. ������� ���������� ������� ������������� �������." << endl;
		cout << endl << "������� ����� ������� ��� �����������." << endl;
		_getch();
	}
}

//�������������� ����� ytn
void EditingPipe(Pipe& p) //�������������� �����
{
	if (p.PipeLength != 0)
	{
		cout << endl << "4.�������������� �����:" << endl << endl;
		InputPipeStatusCheck(p.PipeStatus);
		cout << endl << "������ ���������." << endl;
	}
	else
	{
		cout << "������ ���������� ���������������. ������� ���������� ������� �����." << endl;
		cout << endl << "������� ����� ������� ��� �����������." << endl;
		_getch();
	}
}

//�������������� �� (����� � ����) ytn

//�������������� �� (����� � ����) ytn
void EditingCs(const int& CsWorkshop, int& CsWorkingWorkshops) //���������� ����� �������������� ��
{
	if (CsWorkshop == 0)
	{
		cout << "������ ���������� ���������������. ������� ���������� ������� ������������� �������." << endl;
		cout << endl << "������� ����� ������� ��� �����������" << endl;
		_getch();
		return;
	}

	int item;
	cout << endl << "5.�������������� ������������� �������:" << endl
		<< "�� ������ ������ �� " << CsWorkshop << " ����� � ������: " << CsWorkingWorkshops << endl << endl;

	do
	{
		cout << "������� 1 - ��� ���������� ���������� ���������� ����� �� 1." << endl
			<< "������� 0 - ��� �������� � ������� ����." << endl
			<< "������� -1 - ��� ���������� ���������� ���������� ����� �� 1." << endl;
		cin >> item;
	} while (CheckingIntAndPositiveDouble(item, -1, 1) == false);

	switch (item)
	{
	case 1:
		if (CsWorkingWorkshops == CsWorkshop)
			cout << "���������� ��������� � ������ ������ �����, ��� ����������. ����������, ��������� ������� �����." << endl;
		else
			CsWorkingWorkshops++;
	case 0:
		return;
	case -1:
		if (CsWorkingWorkshops == 0)
			cout << "���������� ��������� ���������� ���������� �����, �.�. ��� ���� �� ������ ������ �����������." << endl;
		else
		{
			CsWorkingWorkshops--;
		}
	}

	cout << endl << "������ ���������." << endl;
}

//����� � ���� ytn
void OutputInFile(const Pipe& p, const Cs& cs)
{
	cout << "6.���������� � ����." << endl
		<< "������ �������� ������� � ���������� ����� data.txt." << endl
		<< "������� 1, ����� ����������, ���� ����� ������ �������� ��� ������ ����������." << endl;
	if (�onfirmationSaving())
	{
		ofstream fout;
		fout.exceptions(ofstream::badbit | ofstream::failbit);
		//https://www.youtube.com/watch?v=jCW2wRoRi0U
		try
		{
			fout.open("data.txt", ios::out);

			fout << p.PipeLength << endl << p.PipeDia << endl << p.PipeStatus << endl;
			fout << cs.CsName << endl << cs.CsWorkshop << endl << cs.CsWorkingWorkshops << endl << cs.CsEffectiveness << endl;

			fout.close();
		}
		catch (const  ofstream::failure& ex)
		{
			cout << ex.what() << endl << ex.code() << endl << "������ ��� ��������/�������� �����" << endl;
		}
	}
}

//���������� �� ����� ytn
	//����� ������ ���������� �����
void OutputReadingError()
{
	cout << "������ ��� ������ �����. � ����� ���������� ������������ ��������" << endl;
}
//����������  �������� �� ����� ��������� ����������
void AssigningValuesFromFile(const Pipe& p1, const Cs& cs1, Pipe& p, Cs& cs)
{
	if (CsInspection(cs1) == false || PipeInspection(p1) == false) { OutputReadingError(); }
	else
	{
		cout << "������ �������." << endl;
		cs = cs1;
		p = p1;
	}
}
//���������� �� ����� ytn
void ReadingFromFile(Pipe& p, Cs& cs)
{
	cout << "7.�������� ������ �� �����." << endl
		<< "������ �������� ������� � ���������� ������� ������ (���� ��� ����). ���������, ��� ��� ��� �� �����." << endl
		<< "������� 1, ����� ����������, ���� ����� ������ �������� ��� ������ ��������." << endl;
	if (�onfirmationSaving())
	{
		ifstream fin;
		fin.exceptions(ifstream::badbit | ifstream::failbit);
		string check;
		Pipe p1 = {};
		Cs cs1 = {};

		try
		{
			fin.open("data.txt", ios::in);
			//���������� ������
			if (!ReadingFile_CheckingIntAndDouble(fin, p1.PipeLength) )
			{
				OutputReadingError();
				return;
			}
			if (ReadingFile_CheckingIntAndDouble(fin, p1.PipeDia) == false) { OutputReadingError(); return; }
			fin >> check;
			if (CheckingStringInBool(check, p1.PipeStatus, "file") == false) { OutputReadingError(); return; };
			fin.ignore();
			getline(fin, cs1.CsName);
			if (ReadingFile_CheckingIntAndDouble(fin, cs1.CsWorkshop) == false) { OutputReadingError(); return; }
			if (ReadingFile_CheckingIntAndDouble(fin, cs1.CsWorkingWorkshops) == false) { OutputReadingError(); return; }
			if (ReadingFile_CheckingIntAndDouble(fin, cs1.CsEffectiveness) == false) { OutputReadingError(); return; }
			fin.close();
			p=p1;
			cs = cs1;
		}
		catch (const  ifstream::failure& ex)
		{
			cout << ex.what() << endl << ex.code() << endl << "������ ��� �������� �����" << endl;
		}
	}
}

//������� �������
//����� ������� �������
void TextSharedConsole() //��������� ����� �������
{
	cout << " ������� ����: " << endl
		<< "1. �������� �����" << endl
		<< "2. �������� ��" << endl
		<< "3. �������� ���� ��������" << endl
		<< "4. ������������� �����" << endl
		<< "5. ������������� ��" << endl
		<< "6. ���������" << endl
		<< "7. ���������" << endl
		<< "0. �����" << endl << endl;
}
//�������������� ����� �������
int MainSharedConsole(unordered_map<int, Pipe>& MapP, Pipe& p, Cs& cs)
{
	cin.clear();

	int item = -1;
	do { cin >> item; } while (CheckingIntAndPositiveDouble(item, 0, 7) == false);

	switch (item)
	{
	case 1:
		system("cls");
		InputPipe(MapP);
		return true;
	case 2:
		system("cls");
		InputCs(cs);
		return true;
	case 3:
		system("cls");
		InformationOutput(p, cs);
		return true;
	case 4:
		system("cls");
		EditingPipe(p);
		return true;
	case 5:
		system("cls");
		EditingCs(cs.CsWorkshop, cs.CsWorkingWorkshops);
		return true;
	case 6:
		system("cls");
		OutputInFile(p, cs);
		return true;
	case 7:
		system("cls");
		ReadingFromFile(p, cs);
		return true;
	case 0:
		if ((p.PipeLength != 0) || (cs.CsWorkshop != 0))
		{
			cout << endl << "�� ������ ��������� ������� ���������?" <<
				endl << "������� 1 ��� ���������� ��� ����� ������ ��������, ��� ������ �� ���������." << endl;
			if (�onfirmationSaving() == true)
				OutputInFile(p, cs);
			else
				return false;
		}
		return false;
	}
	cout << endl << "������� ����� ������� ��� �����������" << endl;
	_getch(); 
	cin.ignore(1000, '\n');
}

//����� ����� � ���������
int main()
{
	setlocale(LC_ALL, "rus"); //����������� �������������
	unordered_map<int, Pipe> MapP;

	//�������� ��������
	Pipe p = {};
	Cs cs = {};
	//������ �������
	do { 
		cout << endl; 
		TextSharedConsole(); 
	} while (MainSharedConsole(MapP, p, cs) != 0);
}