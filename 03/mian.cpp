#include <iostream>
#include "SqList.h"

using namespace std;

int main()
{
	int a = 0;

	SqList sqL(10);

	int tmp = sqL.GetElem(1, a);
	if (tmp == -1)
		cout << "未找到该元素" << endl;
	else {
		cout << "第1个元素为：" << a << endl;
	}
	
	sqL.ListInsert(10, 100);
	sqL.ShowList();

	tmp = sqL.LocateElem(100);
	if (tmp == -1)
		cout << "未找到该元素" << endl;
	else {
		cout << "要查找的元素 100 在线性表的第 " << tmp << " 个位置。" << endl;
	}

	sqL.ListDelete(3, a);
	sqL.ShowList();

	tmp = sqL.ListLength();
	cout << "当前线性表的元素个数为：" << tmp << endl;

	bool flag = sqL.ListEmpty();
	if (flag) {
		cout << "当前线性表为空。" << endl;
	}
	else {
		cout << "当前线性表不为空。" << endl;
	}

	sqL.ClearList();
	flag = sqL.ListEmpty();
	if (flag) {
		cout << "当前线性表为空。" << endl;
	}
	else {
		cout << "当前线性表不为空。" << endl;
	}

	system("pause");
	return 0;
}