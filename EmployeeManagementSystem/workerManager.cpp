#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
	ifstream ifs(FILENAME, ios::in);

	// �ļ�������
	if (!ifs.is_open())
	{
		this->empNum = 0;
		this->empArray = nullptr;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	// �ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) // �ļ�Ϊ��
	{
		this->empNum = 0;
		this->fileIsEmpty = true;
		this->empArray = nullptr;
		ifs.close();
		return;
	}

	int num = this->getEmpNum();
	this->empNum = num;  // ���³�Ա���� 
	// ����ְ������������
	this->empArray = new Worker* [this->empNum];
	// ��ʼ��ְ��
	this->initEmp();
}

void WorkerManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp()
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		// �����¿ռ��С
		int newSize = this->empNum + addNum;

		// �����¿ռ�
		Worker** newSpace = new Worker* [newSize];

		// ��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->empArray != nullptr)
		{
			for (int i = 0;i < this->empNum;i ++)
			{
				newSpace[i] = this->empArray[i];
			}
		}

		// ����������
		for (int i = 0;i < addNum;i ++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = nullptr;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->empNum + i] = worker;
		}

		// �ͷ�ԭ�пռ�
		delete[] this->empArray;
		// �����¿ռ��ָ��
		this->empArray = newSpace;
		// �����µĸ���
		this->empNum = newSize;
		// ����ְ����Ϊ�ձ�־
		this->fileIsEmpty = false;
		// ��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		// ���浽�ļ���
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < empNum; i++)
	{
		ofs << this->empArray[i]->id << " " << this->empArray[i]->name << " "
			<< this->empArray[i]->deptId << endl;
	}

	ofs.close();
}

int WorkerManager::getEmpNum()
{
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		// ��¼����
		num ++;
	}
	ifs.close();

	return num;
}

void WorkerManager::initEmp()
{
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = nullptr;
		// ���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //2����
		{
			worker = new Manager(id, name, dId);
		}
		else //�ܲ�
		{
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->empArray[index ++] = worker;
	}
}

void WorkerManager::showEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < empNum; i++)
		{
			//���ö�̬���ýӿ�
			this->empArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->empNum; i++)
	{
		if (this->empArray[i]->id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::delEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		// ��ְ�����ɾ��
		cout << "��������Ҫɾ����ְ���ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)  // ˵��index��λ��������Ҫɾ��
		{
			for (int i = index; i < this->empNum - 1; i++)
			{
				this->empArray[i] = this->empArray[i + 1];
			}
			this->empNum--;

			this->save(); // ɾ��������ͬ�����ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::modEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			// ���ҵ���ŵ�ְ��

			delete this->empArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			// �������� ��������
			this->empArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			// ���浽�ļ���
			save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	// ������� ����
	system("pause");
	system("cls");
}

void WorkerManager::findEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) // ��ְ���Ų���
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->empArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) // ����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  // ���ҵ��ı�־
			for (int i = 0; i < empNum; i++)
			{
				if (empArray[i]->name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��" << empArray[i]->id 
						<< " �ŵ���Ϣ���£�" << endl;

					flag = true;

					this->empArray[i]->showInfo();
				}
			}
			if (!flag)
			{
				// ���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < empNum; i ++) // ð������
		{
			int minOrMax = i;
			for (int j = i + 1; j < empNum; j ++)
			{
				if (select == 1) // ����
				{
					if (empArray[minOrMax]->id > empArray[j]->id)
					{
						minOrMax = j;
					}
				}
				else // ����
				{
					if (empArray[minOrMax]->id < empArray[j]->id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = empArray[i];
				empArray[i] = empArray[minOrMax];
				empArray[minOrMax] = temp;
			}

		}
		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->showEmp();
	}
}

void WorkerManager::cleanFile()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// ��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->empArray != nullptr)
		{
			for (int i = 0; i < this->empNum; i++)
			{
				if (this->empArray[i] != nullptr)
				{
					delete this->empArray[i];
				}
			}
			this->empNum = 0;
			delete[] this->empArray;
			this->empArray = nullptr;
			this->fileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->empArray != nullptr)
	{
		for (int i = 0; i < this->empNum; i++)
		{
			if (this->empArray[i] != nullptr)
			{
				delete this->empArray[i];
				empArray[i] = nullptr;
			}
		}
		delete[] this->empArray;
		this->empArray = nullptr;
	}
}