# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include"ListLink.h"

int main(int argc, char *argv[])
{
	int i;
	ListLink ListA;
	ListLinkInitial(&ListA);
    for(i=1; i<=10; i++)
	{
		ListLinkInsert(ListA,i*10,1);
	}
		
	MakeDot4ListLink(ListA);
	system("dot.exe -Tpng LL.gv -o LinkListInsertA.png && LinkListInsertA.png");
	ListLinkRelease(ListA);
	MakeDot4ListLink(ListA);
	system("dot.exe -Tpng LL.gv -o LinkListRelease.png && LinkListRelease.png");
	return 0;
}
