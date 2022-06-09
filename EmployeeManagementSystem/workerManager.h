#pragma once // ��ֹͷ�ļ��ظ�����
#include <iostream>
#include <fstream>
#include "worker.h"

using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	// ���캯��
	WorkerManager();

	// չʾ�˵�
	void showMenu();

	// �˳�ϵͳ
	void exitSystem();

	// ����Ա��
	void addEmp();

	// �����ļ�
	void save();

	// ͳ������
	int getEmpNum();

	// ��ʼ��Ա��
	void initEmp();

	// ��ʾְ��
	void showEmp();

	// ����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
	int isExist(int id);

	// ɾ��ְ��
	void delEmp();

	// �޸�ְ��
	void modEmp();

	// ����ְ��
	void findEmp();

	// ����ְ��
	void sortEmp();

	// ����ļ�
	void cleanFile();

	// ��������
	~WorkerManager();
public:
	// ��¼�ļ��е���������
	int empNum;
	// Ա�������ָ��
	Worker** empArray;
	// ��־�ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
};