#pragma once
#include <iostream>
using namespace std;
/*
* 第3章：线性表
* 顺序存储结构
*/

constexpr auto MAXSIZE = 20;

class SqList {
public:
	
	SqList(int count) : m_length(count)		//构造函数
	{
		for (int i = 0; i < count; i++) {
			this->m_data[i] = i;
		}
		this->m_length = count;
	}		

	bool ListEmpty();				//线性表是否为空，是返回true，否返回false
	int ClearList();				//将线性表清空
	int GetElem(int i, int& e);		//获得元素操作
	int LocateElem(int e);			//在线性表中查找与给定值 e 相等的元素
	int ListInsert(int i, int e);	//插入操作
	int ListDelete(int i, int& e);	//删除操作
	int ListLength();				//返回线性表L的元素个数

	void ShowList();				//调试：打印输出线性表的所有元素

private:
	int m_data[MAXSIZE];	//数组存储数据元素，最大值为 MAXSIZE
	int m_length;			//线性表当前长度
};