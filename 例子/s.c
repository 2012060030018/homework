#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include"s.h"

int SeqListInitial(SeqList *L,int n)
{
	if(L==NULL){return ERROR;}
	L->elem=NULL;
	L->elem=(ElemType *)malloc(sizeof(ElemType)*n);
	if(L->elem==NULL){return ERROR;}
	else
	{
	     L->size=n;
	     L->last=-1;
	     return OK;
	}
}

int SeqListRelease(SeqList *L)
{
	if(L==NULL||L->elem==NULL){return ERROR;}
	else
	{
	     free(L->elem);
	     L->size=0;
	     L->last=-1;
	     return OK;
	}
}

int SeqListInsert(SeqList *L,int pos,ElemType e)
{
	if(L==NULL||L->elem==NULL||pos<0||pos>L->last+1||pos>L->size){return ERROR;}
    int i;
    if(L->last+1==L->size){printf("表已满");}
    else
    {
    for(i=L->last;i>=pos;i--)
    {
       L->elem[i+1]=L->elem[i];
    }
    L->elem[pos]=e;
    L->last++;
    }
    return OK;
}

int SeqListDelete(SeqList *L,int pos,ElemType *e)
{
	if(L==NULL||L->elem==NULL||pos<0||pos>L->last||pos>L->size){return ERROR;}
	int i;
	*e=L->elem[pos];
	for(i=pos;i<L->last;i++)
    L->elem[i]=L->elem[i+1];
	L->last--;
	return OK;
}

int SeqListSearch(SeqList *L,int pos,ElemType *e)
{
	if(L==NULL||L->elem==NULL||pos<0||pos>L->last||pos>L->size){return ERROR;}
	*e=L->elem[pos];
	return OK;
}

int SeqListLocate(SeqList *L,ElemType e,int *pos)
{
	if(L==NULL||L->elem==NULL){return ERROR;}
	int i;
	for(i=0;i<L->last+1;i++)
	{
	if(L->elem[i]==e)
	{
	     *pos=i;
	     return OK;
	}
	}
	printf("元素不存在");
	return OK;
}

void MakeDot4SeqList(SeqList *L)
{
	int i;
	FILE *fp;
	
	if(L==NULL)
 		return;
	
	fp=fopen("SL.gv","w+");
	fprintf(fp,"digraph SL {\n");
	
	if(L->last>=0 && L->last<L->size)
	{
		fprintf(fp,"SeqList[shape=none,margin=0,label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"4\">\n<TR><TD>Element</TD>");
		for(i=0; i<=L->last; i++)
			fprintf(fp,"<TD>%4d</TD>",L->elem[i]);
		fprintf(fp,"</TR>\n<TR><TD>Inferior</TD>");
		for(i=0; i<=L->last; i++)
			fprintf(fp,"<TD>%d</TD>",i);
		fprintf(fp,"</TR>\n</TABLE>>];");
	}
	fprintf(fp," }\n");
	fclose(fp);
}
