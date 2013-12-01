#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linklist.h"

/***************************************************************************
对单链表进行初始化。为了修改指向链表指针的值，所以用指向指针的指针做传递。 
***************************************************************************/
void LinkListInitial(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LinkNode));/*申请结点空间*/
	(*L)->next = NULL;/*置为空表*/
}
/***************************************************************************
对单链表进行销毁。 
***************************************************************************/
int LinkListRelease(LinkList L)
{
	LinkNode *p = L->next;
	while(L->next!=NULL)
	{
		L->next = p->next;
		free(p);
		p = L->next;
	}
}
/***************************************************************************
对单链表进行按位置插入。
在带头结点的单链表L中第i个位置插入值为e的新结点
***************************************************************************/
int LinkListInsert(LinkList L, int pos, ElemType e)

{  
	LinkNode *p;
	LinkNode *q;
	int i = 0;
	p = L;  
	while(p!=NULL && i<pos-1)	/*表未查完且未查到第i-1个时重复，找到pre指向第i-1个*/ 
	{ 
		p = p->next;
		i = i+1; 
	}
	if(p==NULL)     			/*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
		return ERROR;

	q = (LinkNode*)malloc(sizeof(LinkNode));	/*申请一个新的结点S */
	q->data = e;                    			/*值e置入s的数据域*/
	q->next = p->next;							/*修改指针，完成插入操作*/
	p->next = q;
	return OK;
}
/***************************************************************************
在带头结点的单链表L中删除第pos个元素.
***************************************************************************/
int LinkListDelete(LinkList L, int pos)
{  
	LinkNode *p = L; 
	LinkNode *q;
	int i = 0;
	if(p==NULL)
		return ERROR;
	while(p->next!=NULL && i<pos-1)	/*寻找被删除结点i的前驱结点i-1使p指向它*/
	{ 
		p = p->next; 
		i++;
	}
	if(p->next==NULL)	/* 即while循环是因为p->next=NULL或i<1而跳出的,即没有找到合法的前驱位置，说明删除位置i不合法。*/
		return ERROR;

	q = p->next;
	p->next = q->next;	/*修改指针，删除结点r*/
	free(q);			/*释放被删除的结点所占的内存空间*/
	return OK;
}
/***************************************************************************
在带头结点的单链表L中查找第pos个结点，若找到(1≤pos ≤n)，则返回该结点的存储位置; 否则返回NULL.
***************************************************************************/
LinkNode * LinkListGet (LinkList  L, int pos)
{  
	int i = 0;	/*从头结点开始扫描*/ 
	LinkNode *p = L;
	while ( p->next!=NULL && i<pos)
	{ 
		p = p->next;    /* 扫描下一结点*/
		i++;   			/* 已扫描结点计数器 */
	}
	if(i == pos)
		return p;   /* 找到了第i个结点 */
	else 
		return NULL;   /* 找不到，i≤0或i>n */
}   
/***************************************************************************
在带头结点的单链表L中查找其结点值等于key的结点，若找到则返回该结点的位置p，否则返回NULL
***************************************************************************/
LinkNode * LinkListLocate( LinkList L, ElemType key)
{ 
	LinkNode *p = L->next;
	while (p!=NULL)
	{
		if (p->data!=key)
			p=p->next; 
		else  
			break;
	}
	return p;
} 
/***************************************************************************
求带头结点的单链表L的长度
***************************************************************************/
/*int	LinkListLength(LinkList L)
{   
	LinkNode *p = L->next;
	int length = 0;
	while(p!=NULL)
	{	  
		p=p->next;
		length++;
	}
	return length;
}  
/***************************************************************************
将递增有序的单链表LA和LB合并成一个递增有序的单链表LC
***************************************************************************/
/*LinkList LinkListMerge(LinkList LA, LinkList LB)
{  
	LinkNode *pa = LA->next;
	LinkNode *pb = LB->next;
	LinkNode *r;
	LinkList LC;
/*将LC初始置空表。pa和pb分别指向两个单链表LA和LB中的第一个结点,r初值为LC*/
	/*pa=LA->next;
	pb=LB->next;
	LC=LA;
	LC->next=NULL;
	r=LC;
/*当两个表中均未处理完时，比较选择将较小值结点插入到新表LC中。*/
	/*while(pa!=NULL && pb!=NULL)
	{
		if(pa->data <= pb->data)
		{
			r->next=pa;
			r=pa;
			pa=pa->next;
		}
		else
		{
			r->next=pb;
			r=pb;
			pb=pb->next;
		}
	}
	if(pa) /*若表LA未完，将表LA中后续元素链到新表LC表尾*/
		/*r->next=pa;
	else	 /*否则将表LB中后续元素链到新表LC表尾*/
	/*	r->next=pb;
	free(LB);
	return(LC);
}
/***************************************************************************
带头节点单链表L就地逆置 
***************************************************************************/
/*void LinkListReverse(LinkList L)
{ 
	LinkNode *p,*q;
	p = L->next;
	L->next = NULL;
	while(p!=NULL)
	{ 
		q=p->next;     /*q指针保留p->next得值*/
		/*p->next=L->next;
		L->next=p;    /*将p结点头插入到单链表L中*/
/*/*		p=q;          /*p指向下一个要插入的结点*/
/*	} 
}
/***************************************************************************
利用DOT语言进行带头节点单链表的链式结构绘图 
***************************************************************************/
void MakeDot4LinkList(LinkList L)
{
	int i = 0;
	FILE *fp;
	LinkList p = L;
	
	if(p==NULL)
 		return;
	
	fp=fopen("LL.gv","w+");
	fprintf(fp,"digraph LL {\nrankdir=LR;\nnode [shape=record,width=.05,height=0.05];\n");
	fprintf(fp,"node%d [label = \"{<D> H | <L>}\"];\n",i++);
	p = p->next;
	while(p!=NULL)
	{
		fprintf(fp,"node%d [label = \"{<D> %d | <L>}\"];\n",i,p->data);
		fprintf(fp,"node%d:L -> node%d:D;\n",i-1,i);
		p = p->next;
		i++;
	}
	fprintf(fp,"node [shape=plaintext, style=filled, color = white];\n");
	fprintf(fp,"node%d:L -> NULL;\nL -> node%d:D;\n",i-1,0);
	fprintf(fp,"}\n");
	fclose(fp);
}

int main(int argc, char *argv[])
{
	int i;
	int key;
	LinkList ListA,ListB;
	LinkListInitial(&ListA);
	LinkListInitial(&ListB);
	for(i=1; i<=10; i++)
	{
		LinkListInsert(ListA,1,i*10);
	}
		
	MakeDot4LinkList(ListA);
	system("dot.exe -Tpng LL.gv -o LinkListInsertA.png && LinkListInsertA.png");
		
	LinkListRelease(ListA);
	MakeDot4LinkList(ListA);
	system("dot.exe -Tpng LL.gv -o LinkListRelease.png && LinkListRelease.png");
	return 0;
}
