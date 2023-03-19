#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include"globalFile.h"
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
using namespace std;

class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	virtual void operMuen();

	void addPerson();//����˺�

	void showPerson();//�鿴�˺�

	void showComputer();//��ʾ������Ϣ

	void cleanFile();//���ԤԼ��¼

	void initVector();//��ʼ������

	void initComputerRoom();//��ʼ������

	bool checkRepeat(int id, int type);

	vector<Student>vStu;

	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;
};