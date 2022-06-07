#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"
using namespace std;

void test()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}

int main()
{
	test();
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //添加职工
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}