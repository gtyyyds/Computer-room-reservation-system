#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include"globalFile.h"
using namespace std;

class OrderFile
{
public:
	OrderFile();

	void updateOrder();

	int m_Size;

	map<int, map<string, string>>m_orderDate;

};