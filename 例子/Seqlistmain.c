#include <stdio.h>
#include"seqlist.h"
int main(int argc, char *argv[])
{
	int		i;
	int		elemnumber = 20;
	Seqlist *sSeqList;
	ElemType element;
	sSeqList = (Seqlist *)malloc(sizeof(Seqlist));
	
	SeqlistInitial(sSeqList, elemnumber);
	
	for(i=0; i<elemnumber; i++)
	SeqlistInsert(sSeqList, i, rand()%1000);
	MakeDot4SeqList(sSeqList);
	system("dot.exe -Tpng SL.gv -o MakeDot4SeqList.png && MakeDot4SeqList.png");
	
	SeqlistDelete(sSeqList,19,&element);
	SeqlistDelete(sSeqList,0,&element);
	MakeDot4SeqList(sSeqList);
	system("dot.exe -Tpng SL.gv -o SeqListDelete.png && SeqListDelete.png");

	SeqlistRelease(sSeqList);
	MakeDot4SeqList(sSeqList);
	system("dot.exe -Tpng SL.gv -o SeqListRelease.png && SeqListRelease.png");
	
	return 0;
}
