#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ� " << this->id << " \tְ�������� " << this->name
		<< " \t��λ��" << this->getDeptName() 
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}

string Manager::getDeptName()
{
	return string("����");
}