#pragma once // 防止头文件重复包含
#include <iostream>
#include <fstream>
#include "worker.h"

using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	// 构造函数
	WorkerManager();

	// 展示菜单
	void showMenu();

	// 退出系统
	void exitSystem();

	// 增加员工
	void addEmp();

	// 保存文件
	void save();

	// 统计人数
	int getEmpNum();

	// 初始化员工
	void initEmp();

	// 显示职工
	void showEmp();

	// 按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	int isExist(int id);

	// 删除职工
	void delEmp();

	// 修改职工
	void modEmp();

	// 查找职工
	void findEmp();

	// 排序职工
	void sortEmp();

	// 清空文件
	void cleanFile();

	// 析构函数
	~WorkerManager();
public:
	// 记录文件中的人数个数
	int empNum;
	// 员工数组的指针
	Worker** empArray;
	// 标志文件是否为空
	bool fileIsEmpty;
};