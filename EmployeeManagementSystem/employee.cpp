#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

void Employee::showInfo()
{
	cout << "ְ����ţ� " << this->id << " \tְ�������� " << this->name
		<< " \t��λ��" << this->getDeptName() << " \t��λְ����ɾ�����������" 
		<< endl;
}

string Employee::getDeptName()
{
	return string("Ա��");
}