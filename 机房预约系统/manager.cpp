#include"manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector(); 
	this->initComputerRoom();
}

void Manager::operMuen()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        1.����˺�               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        2.�鿴�˺�               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        3.�鿴����               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        4.���ԤԼ               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        0.ע����¼               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;//������ʾ

	ofstream ofs;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ�";
			errorTip = "ѧ���ظ������������룡";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "������ְ���ţ�";
			errorTip = "ְ�����ظ������������룡";
			break;
		}
		else
		{
			cout << "��������!����������" << endl;
		}
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	ofs.close();
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	this->initVector();
}

class printStudent
{
public:
	void operator()(const Student& s)
	{
		cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
	}
};

class printTeacher
{
public:
	void operator()(const Teacher& t)
	{
		cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
	}
};

void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			cout << "����ѧ����Ϣ���£�" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent());
			break;
		}
		else if (select == 2)
		{
			cout << "������ʦ��Ϣ���£�" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher());
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "��������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�����ı�ţ�" << it->m_ComId << " ���������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
	
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ����������" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ��������" << vTea.size() << endl;
	ifs.close();
}

void Manager::initComputerRoom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "������������" << vCom.size() << endl;
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}