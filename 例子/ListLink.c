#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include"ListLink.h"

int ListLinkInitial(ListLink *Lpoint)
{
	(*Lpoint)=(LinkNode *)malloc(sizeof(LinkNode));
	if((*Lpoint)==NULL) return ERROR;
	(*Lpoint)->next=NULL;
}


int ListLinkRelease(ListLink L)
{
	LinkNode *p;
	if(L==NULL) return ERROR;
	while(L->next!=NULL)
	{
	    p=L->next;
	    L->next=p->next;
	    free(p);
	}
	return OK;
}

int ListLinkInsert(ListLink L,Elemtype e,int pos)
{
    int i=0;
	LinkNode *p;
	LinkNode *q;
	p=L;
	if(p==NULL) return ERROR;
	while(p!=NULL&&i<pos-1)
	{
	      i++;
	      p=p->next;
	}
	if (p==NULL)  return ERROR;
	q=(LinkNode *)malloc(sizeof(LinkNode));
	if(q==NULL) return ERROR;
	q->data=e;
	q->next=p->next;
	p->next=q;
	return OK;
}

int ListLinkDelete(ListLink L,int pos)
{
	int i=0;
	LinkNode *p;
	LinkNode *q;
	p=L;
	if(p==NULL) return ERROR;
	while(p->next!=NULL&&i<pos-1)
	{
	    i++;
	    p=p->next;
	}
	if(p->next==NULL)  return ERROR;
	q=p->next;
	p->next=q->next;
	free(q);
	return OK;
}

LinkNode* ListLinkGet(ListLink L,int pos)
{
	int i=0;
	LinkNode *p;
	p=L;
	if(p==NULL)  return ERROR;
	while(p!=NULL&&i<pos)
	{
	   i++;
	   p=p->next;
	}
	if(p==NULL)  return ERROR;
	return p;
}

LinkNode* ListLinkLocate(ListLink L,Elemtype e)
{
	LinkNode *p;
	p=L;
	while(p!=NULL&&p->data!=e)
	{
	    p=p->next;
	}
	return p;
}


void MakeDot4ListLink(ListLink L)
{
	int i = 0;
	FILE *fp;
	LinkNode* p = L;
	
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

