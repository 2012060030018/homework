#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include"Seqlist.h"

int SeqlistInitial(Seqlist *L,int n)
{
	if(L==NULL){return ERROR;}
    L->elem=NULL;
	L->elem=(ElemType*)malloc(sizeof(ElemType)*n);
    if(L->elem==NULL){return ERROR;}
    else 
    {
    L->size=n;
    L->last=-1;
    return OK;
    }
}
int SeqlistRelease(Seqlist *L)
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
int SeqlistSearch(Seqlist *L,int pos,ElemType *e)
{
	if(L==NULL||pos<0||pos>L->last-1){return ERROR;}
	*e=L->elem[pos];
	return OK;
}
int SeqlistLocate(Seqlist *L,ElemType e,int *pos)
{
	int i;
    *pos=-1;
	if(L==NULL)return ERROR;
	for(i=0;i<L->last;i++)
	{
	if(e==L->elem[i])
	{
	*pos=i+1;
	}
	}
    if(pos==-1)return ERROR;
    else return OK;
}
int SeqlistInsert(Seqlist *L,int pos,ElemType e)
{
	int i;
	if(L==NULL||pos<0||pos>L->last+1||pos>L->size-1) 
	{
	printf("插入不合法");
	return ERROR;
	}
	if(L->last==L->size-1){printf("表已满");}
	else
	{
	for(i=L->last;i>=pos;i--)
	{
	L->elem[i+1]=L->elem[i];
	}
	L->elem[pos]=e;
	L->last++;
	return OK;
	}
}
int SeqlistDelete(Seqlist *L,int pos,ElemType *e)
{
	int i;
	if(L==NULL||pos<0||pos>L->last) return ERROR;
	*e=L->elem[pos];
	for(i=pos;i<=L->last;i++)
	{
	L->elem[i]=L->elem[i+1];
	}
	L->last--;
	return OK; 
}
void SeqlistMerge(Seqlist *LA,Seqlist *LB,Seqlist *LC)
{
	int i=0;j=0;k=0;
	while(i<LA->last&&j<LB->last)
	{
	   if(LA->elem[i]<=LB->elem[j])
	   {
	        LC->elem[k]=LA->elem[i];
	        i++;
	        k++;
	   }
	   else
	   {
	        LC->elem[k]=LB->elem[j];
	        j++;
	        k++;
	   }
	}
	while(i==LA->last&&j<LB->last)
	{
	       LC->elem[k]=LB->elem[j];
	       j++;
	       k++;
	}
	while(j==LB->last&&i<LA->last)
	{
	      LC->elem[k]=LA->elem[i];
	      i++;
	      j++;
	}
	LC->last=LA->last+LB->last+1;
}
void MakeDot4SeqList(Seqlist *L)
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