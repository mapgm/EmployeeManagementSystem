#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"
using namespace std;

int main()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //���ְ��
			wm.addEmp();
			break;
		case 2: //��ʾְ��
			wm.showEmp();
			break;
		case 3: //ɾ��ְ��
			wm.delEmp();
			break;
		case 4: //�޸�ְ��
			wm.modEmp();
			break;
		case 5: //����ְ��
			wm.findEmp();
			break;
		case 6: //����ְ��
			wm.sortEmp();
			break;
		case 7: //����ļ�
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}