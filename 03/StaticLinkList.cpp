#include <iostream>
using namespace std;

/*
* 静态链表
*/

constexpr auto MAXSIZE = 1000;

struct Component {
	int data;
	int cur;		//游标(Cursor),为0时表示无指向
};
typedef Component StaticLinkList[MAXSIZE];

/*
* - 初始化
* 操作结果：将一维数组 space 中各分量链成一备用链表
*/
int InitList(StaticLinkList space)
{
	for (int i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;		//目前静态链表为空，最后一个元素的 cur 为 0
	return 1;
}

/*
* 初始条件: 静态链表 L 已存在
* 操作结果：返回 L 中数据元素个数
*/
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i) {
		i = L[i].cur;
		j++;
	}
	return j;
}

/*
* - 静态链表的插入操作
* 操作结果：若备用空间链表非空，则返回分配的结点下标，否则返回0
*/
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;	//当前数组第一个元素的 cur 存的值，就是要返回的第一个备用空闲的下标
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

/*
* - 静态链表的插入操作
* 操作结果：在 L 中第 i 个元素之前插入新的数据元素 e
*/
int ListInsert(StaticLinkList L, int index, int e)
{
	int j, k, l;
	k = MAXSIZE - 1;					//注意 k 首先是最后一个元素的下标
	if (index <1 || index > ListLength(L) + 1)
		return 0;
	j = Malloc_SLL(L);					//获得空闲分量的下标
	if (j) {
		L[j].data = e;					//将数据赋值给此分量的 data
		for (l = 1; l < index - 1; l++)		//找到第 i 个元素之前的位置
			k = L[k].cur;
		L[j].cur = L[k].cur;			//把第 i 个元素之前的 cur 赋值给新的 cur
		L[k].cur = j;					//将新元素的下标赋值给第 i 个元素之前元素的 cur
		return 1;
	}
	return 0;
}

/*
* 将下标为k的空闲结点回收到备用链表
*/
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;		//把第一个元素 cur 值赋给要删除的分量 cur
	space[0].cur = k;					//把要删除的分量下标赋值给第一个元素的 cur
}

/*
* - 静态链表的删除操作
* 操作结果：删除在 L 中第 i 个数据元素 e
*/
int ListDelete(StaticLinkList L, int index)
{
	int j, k;
	if (index <1 || index > ListLength(L))
		return 0;
	k = MAXSIZE - 1;
	for (j = 1; j < index - 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return 1;
}

int main_st()
{
	StaticLinkList L;
	InitList(L);
	ListInsert(L, 1, 10);
}