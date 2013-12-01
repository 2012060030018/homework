#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define ElemType int

typedef struct SeqList
{
	ElemType *elem;
    int size;
    int last;
}SeqList;

int SeqListInitial(SeqList *L,int n);
int SeqListRelease(SeqList *L);
int SeqListInsert(SeqList *L,int pos,ElemType e);
int SeqListDelete(SeqList *L,int pos,ElemType *e);
int SeqListSearch(SeqList *L,int pos,ElemType *e);
int SeqListLocate(SeqList *L,ElemType e,int *pos);
void MakeDot4SeqList(SeqList *L);
