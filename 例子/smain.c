#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include"s.h"

int main(int argc, char *argv[])
{
	int i;
	SeqList *L;
	L=(SeqList*)malloc(sizeof(SeqList));
	int elemnumber=20;
    ElemType e;
    SeqListInitial(L,elemnumber);
    for(i=0;i<elemnumber;i++)
    SeqListInsert(L,i,rand()%1000);
    MakeDot4SeqList(L);
	system("dot.exe -Tpng SL.gv -o MakeDot4SeqList.png && MakeDot4SeqList.png");
    
	SeqListDelete(L,19,&e);
	SeqListDelete(L,0,&e);
	MakeDot4SeqList(L);
	system("dot.exe -Tpng SL.gv -o MakeDot4SeqList.png && MakeDot4SeqList.png");

    SeqListRelease(L);
    MakeDot4SeqList(L);
	system("dot.exe -Tpng SL.gv -o MakeDot4SeqList.png && MakeDot4SeqList.png");
	return 0;
}
