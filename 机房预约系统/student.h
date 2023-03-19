#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Identity.h"
#include"computerRoom.h"
#include"globalFile.h"
#include"orderFile.h"
using namespace std;

class Student :public Identity
{
public:
	Student();

	Student(int id, string name, string pwd);

	virtual void operMuen();

	void applyOrder();//����ԤԼ

	void showMyOrder();//�鿴����ԤԼ

	void showAllOrder();//�鿴����ԤԼ

	void cancelOrder();//ȡ��ԤԼ

	void initComputerRoom();//��ʼ������

	int m_Id;

	vector<ComputerRoom>vCom;

};
