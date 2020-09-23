#pragma once
#include <iostream>
using namespace std;
/*
* ��3�£����Ա�
* ˳��洢�ṹ
*/

constexpr auto MAXSIZE = 20;

class SqList {
public:
	
	SqList(int count) : m_length(count)		//���캯��
	{
		for (int i = 0; i < count; i++) {
			this->m_data[i] = i;
		}
		this->m_length = count;
	}		

	bool ListEmpty();				//���Ա��Ƿ�Ϊ�գ��Ƿ���true���񷵻�false
	int ClearList();				//�����Ա����
	int GetElem(int i, int& e);		//���Ԫ�ز���
	int LocateElem(int e);			//�����Ա��в��������ֵ e ��ȵ�Ԫ��
	int ListInsert(int i, int e);	//�������
	int ListDelete(int i, int& e);	//ɾ������
	int ListLength();				//�������Ա�L��Ԫ�ظ���

	void ShowList();				//���ԣ���ӡ������Ա������Ԫ��

private:
	int m_data[MAXSIZE];	//����洢����Ԫ�أ����ֵΪ MAXSIZE
	int m_length;			//���Ա�ǰ����
};