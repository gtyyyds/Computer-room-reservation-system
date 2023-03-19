#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Identity.h"
#include"orderFile.h"
using namespace std;

class Teacher : public Identity
{
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMuen();

	void showAllOrder();//查看所有预约

	void vaildOrder();//审核预约

	int m_EmpId;
};