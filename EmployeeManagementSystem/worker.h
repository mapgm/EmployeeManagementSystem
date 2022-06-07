#pragma once
#include <iostream>
#include <string>
using namespace std;

// 职工抽象基类
class Worker
{
public:
	// 显示个人信息
	virtual void showInfo() = 0;
	// 获取岗位名称
	virtual string getDeptName() = 0;

	int id; // 职工编号
	string name; // 职工姓名
	int deptId; // 职工所在部门名称编号
};