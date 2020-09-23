#include <iostream>
#include "SqList.h"

using namespace std;

int main()
{
	int a = 0;

	SqList sqL(10);

	int tmp = sqL.GetElem(1, a);
	if (tmp == -1)
		cout << "δ�ҵ���Ԫ��" << endl;
	else {
		cout << "��1��Ԫ��Ϊ��" << a << endl;
	}
	
	sqL.ListInsert(10, 100);
	sqL.ShowList();

	tmp = sqL.LocateElem(100);
	if (tmp == -1)
		cout << "δ�ҵ���Ԫ��" << endl;
	else {
		cout << "Ҫ���ҵ�Ԫ�� 100 �����Ա�ĵ� " << tmp << " ��λ�á�" << endl;
	}

	sqL.ListDelete(3, a);
	sqL.ShowList();

	tmp = sqL.ListLength();
	cout << "��ǰ���Ա��Ԫ�ظ���Ϊ��" << tmp << endl;

	bool flag = sqL.ListEmpty();
	if (flag) {
		cout << "��ǰ���Ա�Ϊ�ա�" << endl;
	}
	else {
		cout << "��ǰ���Ա�Ϊ�ա�" << endl;
	}

	sqL.ClearList();
	flag = sqL.ListEmpty();
	if (flag) {
		cout << "��ǰ���Ա�Ϊ�ա�" << endl;
	}
	else {
		cout << "��ǰ���Ա�Ϊ�ա�" << endl;
	}

	system("pause");
	return 0;
}