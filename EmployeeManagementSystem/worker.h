#pragma once
#include <iostream>
#include <string>
using namespace std;

// ְ���������
class Worker
{
public:
	// ��ʾ������Ϣ
	virtual void showInfo() = 0;
	// ��ȡ��λ����
	virtual string getDeptName() = 0;

	int id; // ְ�����
	string name; // ְ������
	int deptId; // ְ�����ڲ������Ʊ��
};