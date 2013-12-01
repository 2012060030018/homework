#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linklist.h"

/***************************************************************************
�Ե�������г�ʼ����Ϊ���޸�ָ������ָ���ֵ��������ָ��ָ���ָ�������ݡ� 
***************************************************************************/
void LinkListInitial(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LinkNode));/*������ռ�*/
	(*L)->next = NULL;/*��Ϊ�ձ�*/
}
/***************************************************************************
�Ե�����������١� 
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
�Ե�������а�λ�ò��롣
�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
***************************************************************************/
int LinkListInsert(LinkList L, int pos, ElemType e)

{  
	LinkNode *p;
	LinkNode *q;
	int i = 0;
	p = L;  
	while(p!=NULL && i<pos-1)	/*��δ������δ�鵽��i-1��ʱ�ظ����ҵ�preָ���i-1��*/ 
	{ 
		p = p->next;
		i = i+1; 
	}
	if(p==NULL)     			/*�統ǰλ��pΪ�ձ������껹δ������i����˵������λ�ò�����*/ 
		return ERROR;

	q = (LinkNode*)malloc(sizeof(LinkNode));	/*����һ���µĽ��S */
	q->data = e;                    			/*ֵe����s��������*/
	q->next = p->next;							/*�޸�ָ�룬��ɲ������*/
	p->next = q;
	return OK;
}
/***************************************************************************
�ڴ�ͷ���ĵ�����L��ɾ����pos��Ԫ��.
***************************************************************************/
int LinkListDelete(LinkList L, int pos)
{  
	LinkNode *p = L; 
	LinkNode *q;
	int i = 0;
	if(p==NULL)
		return ERROR;
	while(p->next!=NULL && i<pos-1)	/*Ѱ�ұ�ɾ�����i��ǰ�����i-1ʹpָ����*/
	{ 
		p = p->next; 
		i++;
	}
	if(p->next==NULL)	/* ��whileѭ������Ϊp->next=NULL��i<1��������,��û���ҵ��Ϸ���ǰ��λ�ã�˵��ɾ��λ��i���Ϸ���*/
		return ERROR;

	q = p->next;
	p->next = q->next;	/*�޸�ָ�룬ɾ�����r*/
	free(q);			/*�ͷű�ɾ���Ľ����ռ���ڴ�ռ�*/
	return OK;
}
/***************************************************************************
�ڴ�ͷ���ĵ�����L�в��ҵ�pos����㣬���ҵ�(1��pos ��n)���򷵻ظý��Ĵ洢λ��; ���򷵻�NULL.
***************************************************************************/
LinkNode * LinkListGet (LinkList  L, int pos)
{  
	int i = 0;	/*��ͷ��㿪ʼɨ��*/ 
	LinkNode *p = L;
	while ( p->next!=NULL && i<pos)
	{ 
		p = p->next;    /* ɨ����һ���*/
		i++;   			/* ��ɨ��������� */
	}
	if(i == pos)
		return p;   /* �ҵ��˵�i����� */
	else 
		return NULL;   /* �Ҳ�����i��0��i>n */
}   
/***************************************************************************
�ڴ�ͷ���ĵ�����L�в�������ֵ����key�Ľ�㣬���ҵ��򷵻ظý���λ��p�����򷵻�NULL
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
���ͷ���ĵ�����L�ĳ���
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
����������ĵ�����LA��LB�ϲ���һ����������ĵ�����LC
***************************************************************************/
/*LinkList LinkListMerge(LinkList LA, LinkList LB)
{  
	LinkNode *pa = LA->next;
	LinkNode *pb = LB->next;
	LinkNode *r;
	LinkList LC;
/*��LC��ʼ�ÿձ�pa��pb�ֱ�ָ������������LA��LB�еĵ�һ�����,r��ֵΪLC*/
	/*pa=LA->next;
	pb=LB->next;
	LC=LA;
	LC->next=NULL;
	r=LC;
/*���������о�δ������ʱ���Ƚ�ѡ�񽫽�Сֵ�����뵽�±�LC�С�*/
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
	if(pa) /*����LAδ�꣬����LA�к���Ԫ�������±�LC��β*/
		/*r->next=pa;
	else	 /*���򽫱�LB�к���Ԫ�������±�LC��β*/
	/*	r->next=pb;
	free(LB);
	return(LC);
}
/***************************************************************************
��ͷ�ڵ㵥����L�͵����� 
***************************************************************************/
/*void LinkListReverse(LinkList L)
{ 
	LinkNode *p,*q;
	p = L->next;
	L->next = NULL;
	while(p!=NULL)
	{ 
		q=p->next;     /*qָ�뱣��p->next��ֵ*/
		/*p->next=L->next;
		L->next=p;    /*��p���ͷ���뵽������L��*/
/*/*		p=q;          /*pָ����һ��Ҫ����Ľ��*/
/*	} 
}
/***************************************************************************
����DOT���Խ��д�ͷ�ڵ㵥�������ʽ�ṹ��ͼ 
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
