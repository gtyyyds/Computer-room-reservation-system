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

	void addPerson();//添加账号

	void showPerson();//查看账号

	void showComputer();//显示机房信息

	void cleanFile();//清空预约记录

	void initVector();//初始化容器

	void initComputerRoom();//初始化机房

	bool checkRepeat(int id, int type);

	vector<Student>vStu;

	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;
};