#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define ElemType int

typedef struct Seqlist
{
	ElemType *elem;
	int size;
	int last;
}Seqlist;
int SeqlistInitial(Seqlist *L,int n);
int SeqlistRelease(Seqlist *L);
int SeqlistInsert(Seqlist *L,int pos,ElemType e);
int SeqlistSearch(Seqlist *L,int pos,ElemType *e);
int SeqlistLocate(Seqlist *L,ElemType e,int *pos);
int SeqliseDelete(Seqlist *L,int pos,ElemType *e);
void	MakeDot4SeqList(Seqlist *L);