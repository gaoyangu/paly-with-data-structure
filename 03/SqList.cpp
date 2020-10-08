#include <iostream>
using namespace std;

/*
* 线性表的顺序存储的结构
*/

constexpr auto MAXSIZE = 20;	//存储空间初始分配量

struct SqList {
	int data[MAXSIZE] = {};		//数组存储数据元素
	int length = 0;					//线性表当前长度
};

int ShowList(SqList L)
{
	if (L.length == 0) {
		cout << "该线性表为空。" << endl;
		return 0;
	}
	cout << "该线性表共有[ " << L.length << " ] 个元素，分别如下: " << endl;
	for (int i = 0; i < L.length; i++)
		cout << "index = " << i << "\t" << L.data[i] << endl;
	return 1;
}
/*
* - 获得元素操作
* 初始条件：顺序线性表 L 已存在，1 <= i <= ListLength(L)
* 操作结果：用 e 返回 L 中第 i 个数据元素的值
*/
int GetElem(SqList L, int index, int& e)
{
	if (L.length == 0 || index < 1 || index > L.length)
		return 0;
	e = L.data[index - 1];
	return 1;
}

/*
* - 插入操作
* 初始条件：顺序线性表 L 已存在，1 <= i <= ListLength(L)
* 操作结果：在 L 中的第 i 个位置插入新的数据元素 e，L 的长度加 1
*/
int ListInsert(SqList& L, int index, int e)
{
	if (L.length == MAXSIZE || index < 1 || index > L.length + 1)
		return 0;
	for (int i = L.length - 1; i >= index - 1; i--) {
		L.data[i + 1] = L.data[i];
	}		
	//将新元素插入
	L.data[index - 1] = e;
	L.length++;
	return 1;
}

/*
* - 删除操作
* 初始条件：顺序线性表 L 已存在，1 <= i <= ListLength(L)
* 操作结果：删除 L 的第 i 个数据元素，并用 e 返回其值，L 的长度减 1
*/
int ListDelete(SqList& L, int index, int& e)
{
	if (L.length == 0 || index < 1 || index > L.length)
		return 0;
	e = L.data[index - 1];
	if (index < L.length){
		for (int i = index; i < L.length; i++)
			L.data[i - 1] = L.data[i];
	}
	L.length--;
	return 1;
}

int main_sqlist()
{
	SqList L;
	int a = 0;

	//初始化
	for (int i = 0; i < 10; i++) {
		L.data[i] = 10 * i + 1;
		L.length++;
	}

	GetElem(L, 2, a);
	cout << a << endl;
	ShowList(L);

	ListInsert(L, 2, 100);
	ShowList(L);

	ListDelete(L, 3, a);
	ShowList(L);

	system("pause");
	return 0;
}