#include <iostream>
#include <time.h>
using namespace std;

/*
* 线性表的链式存储的结构
*/

struct Node {
	int data = 0;
	Node* next = NULL;
};
typedef struct Node* LinkList;

/*
* - 单链表的读取
* 初始条件：顺序线性表 L 已存在，1 <= i <= ListLength(L)
* 操作结果：用 e 返回 L 中第 i 个数据元素的值
*/
int GetElem(LinkList L, int index, int& e)
{
	LinkList p;
	p = L->next;			// p 指向链表 L 的第一个结点
	int i = 1;				//i 为计数器
	while (p && i < index) {
		p = p->next;		//让 p 指向下一个结点
		++i;
	}
	if (!p || i > index)	// 第 i 个元素不存在
		return 0;
	e = p->data;			//取第 i 个元素的数据
	return 1;
}

/*
* - 单链表的插入
* 初始条件：顺序线性表 L 已存在，1 <= i <= ListLength(L)
* 操作结果：在 L 中的第 i 个位置插入新的数据元素 e
*/
int ListInsert(LinkList& L, int index, int e)
{
	LinkList p, s;
	p = L;
	int i = 1;
	while (p && i < index) {	//寻找第 i 个结点
		p = p->next;
		++i;
	}
	if (!p || i > index)
		return 0;
	s = new Node;
	s->data = e;
	s->next = p->next;			//将 p 的后继结点赋值给 s 的后继
	p->next = s;				//将 s 赋值给 p 的后继
	//delete s;
	return 1;
}

/*
* - 单链表的删除
* 初始条件：顺序线性表 L 已存在，1 <= i <= ListLength(L)
* 操作结果：删除 L 的第 i 个数据元素，并用 e 返回其值
*/
int ListDelete(LinkList& L, int index, int& e)
{
	LinkList p, q;
	p = L;
	int i = 1;
	while (p->next && i < index) {		//遍历寻找第 i 个元素
		p = p->next;
		++i;
	}
	if ((!p->next) || i > index) 
		return 0;
	q = p->next;
	p->next = q->next;
	e = q->data;
	//delete q;
	return 1;
}

/*
* - 单链表的整表创建
* 操作结果：随机产生 n 个元素的值，建立带表头结点的单链线性表L（头插法）
*/
void CreatListHead(LinkList& L, int n)
{
	LinkList p;
	srand(time(0));		//初始化随机数种子
	L = new Node;
	L->next = NULL;		//先建立一个带头结点的单链表
	for (int i = 0; i < n; i++) {
		p = new Node;	//生成新结点
		p->data = rand() % 100 + 1;
		p->next = L->next;
		L->next = p;
		//delete p;
	}
}

/*
* - 单链表的整表创建
* 操作结果：随机产生 n 个元素的值，建立带表头结点的单链线性表L（尾插法）
*/
void CreatListTail(LinkList& L, int n)
{
	LinkList p, r;
	srand(time(0));		//初始化随机数种子
	L = new Node;
	r = L;				// r 指向尾部的结点
	for (int i = 0; i < n; i++) {
		p = new Node;	//生成新节点
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;		//表示当前链表结束
}

/*
* - 单链表的整表删除
* 初始条件：顺序线性表 L 已存在
* 操作结果：将 L 重置为空表
*/
int ClearList(LinkList& L)
{
	LinkList p, q;
	p = L->next;		//p指向第一个结点
	while (p) {			//没到表尾
		q = p->next;
		//free(p);
		delete p;		
		p = q;
	}
	L->next = NULL;		//头结点指针域为空
	return 1;
}

int main_LinkList()
{
	LinkList L;
	int a = 1;
	int tmp = 0;

	CreatListHead(L, 5);
	//CreatListTail(L, 5);
	for (int i = 0; i < 5; i++) {
		GetElem(L, i+1, a);
		cout << "index = " << i+1 << "\t" << a << endl;
	}	

	cout << "------------------------------------------" << endl;
	if (ListInsert(L, 1, 10)) {
		for (int i = 0; i < 6; i++) {
			GetElem(L, i + 1, a);
			cout << "index = " << i + 1 << "\t" << a << endl;
		}
	}
	else {
		cout << "插入元素失败!" << endl;
	}

	cout << "------------------------------------------" << endl;
	if (ListDelete(L, 2, a)) {
		for (int i = 0; i < 5; i++) {
			GetElem(L, i + 1, a);
			cout << "index = " << i + 1 << "\t" << a << endl;
		}
	}
	else {
		cout << "删除元素失败!" << endl;
	}

	cout << "------------------------------------------" << endl;
	if (ClearList(L)) {
		cout << "整表删除成功！" << endl;
	}

	if (GetElem(L, 1, a)) {
		cout << a << endl;
	}
	else {
		cout << "获取元素失败！" << endl;
	}

	system("pause");
	return 0;
}