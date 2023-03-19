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

	void applyOrder();//申请预约

	void showMyOrder();//查看自身预约

	void showAllOrder();//查看所有预约

	void cancelOrder();//取消预约

	void initComputerRoom();//初始化机房

	int m_Id;

	vector<ComputerRoom>vCom;

};
