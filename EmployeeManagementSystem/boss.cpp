#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

void Boss::showInfo()
{
	cout << "ְ����ţ� " << this->id << " \tְ�������� " << this->name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName()
{
	return string("�ܲ�");
}