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

	void showAllOrder();//�鿴����ԤԼ

	void vaildOrder();//���ԤԼ

	int m_EmpId;
};