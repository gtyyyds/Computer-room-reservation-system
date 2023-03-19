#include"teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMuen()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|           1.�鿴����ԤԼ         |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|           2.���ԤԼ             |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|           0.ע����¼             |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼʱ�ڣ���" << of.m_orderDate[i]["date"];
		cout << "\tʱ��Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����");
		cout << "\tѧ�ţ�" << of.m_orderDate[i]["stuId"];
		cout << "\t������" << of.m_orderDate[i]["stuName"];
		cout << "\t������ţ�" << of.m_orderDate[i]["roomId"] << "\t";
		string status = "״̬��";
		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::vaildOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
	}
	vector<int>v;
	int index = 0;
	cout << "����˵�ԤԼ��¼���£�" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼʱ�ڣ���" << of.m_orderDate[i]["date"];
			cout << "\tʱ��Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����");
			cout << "\tѧ�ţ�" << of.m_orderDate[i]["stuId"];
			cout << "\t������" << of.m_orderDate[i]["stuName"];
			cout << "\t������ţ�" << of.m_orderDate[i]["roomId"] << "\t";
			string status = "״̬�������";
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select > 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˵Ľ��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderDate[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderDate[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "������ϣ�" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls"); 
}