#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct LinkNode	/*������Ͷ���*/ 
{ 
	ElemType			data;
	struct LinkNode		*next;
}LinkNode, *LinkList;	/* LinkListΪָ������*/
