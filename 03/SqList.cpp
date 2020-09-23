#include "SqList.h"

//线性表是否为空
bool SqList::ListEmpty()
{
	if (this->m_length == 0)
		return true;
	return false;
}

//将线性表清空
int SqList::ClearList()
{
	this->m_length = 0;
	return 0;
}

//将线性表L中的第 i 个位置元素值返回给 e
int SqList::GetElem(int i, int& e) {
	if (this->m_length == 0 || i < 1 || i > this->m_length){
		cout << "[info]: 输入的查找范围有误。" << endl;
		return -1;
	}
	e = this->m_data[i - 1];
	return 0;
}

//在线性表中查找与给定值 e 相等的元素
int SqList::LocateElem(int e)
{
	for (int i = 0; i < this->m_length; i++) {
		if (this->m_data[i] == e)
			return i + 1;
	}
	return -1;
}

//在线性表L中的第 i 个位置插入新元素 e
int SqList::ListInsert(int i, int e)
{
	if (this->m_length == MAXSIZE) {	//线性表已满
		cout << "[info]: 当前线性表已满。" << endl;
		return -1;
	}
	if (i < 1 || i > this->m_length + 1) {	// i 不在范围内
		cout << "[info]: 输入范围有误。" << endl;
		return -1;
	}
	for (int k = this->m_length - 1; k >= i - 1; k--) {		//将要插入位置后数据元素向后移动一位
		this->m_data[k + 1] = this->m_data[k];
	}

	this->m_data[i - 1] = e;	//插入新元素
	this->m_length++;
	return 0;
}

int SqList::ListDelete(int i, int& e) {
	if (this->m_length == 0) {
		cout << "[info]: 线性表为空。" << endl;
		return -1;
	}
	if (i < 1 || i > this->m_length) {
		cout << "[info]: 输入范围有误。" << endl;
		return -1;
	}

	e = this->m_data[i - 1];

	for (int k = i; k < this->m_length; k++) {
		this->m_data[k - 1] = this->m_data[k];
	}
	this->m_length--;
	return 0;
}

//返回线性表L的元素个数
int SqList::ListLength()
{
	return this->m_length;
}

void SqList::ShowList()
{
	cout << "当前线性表共有：" << this->m_length <<" 个元素，分别如下：" << endl;
	for (int i = 0; i < this->m_length; i++) {
		cout << this->m_data[i] << endl;
	}
}