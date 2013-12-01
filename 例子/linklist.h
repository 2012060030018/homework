#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct LinkNode	/*结点类型定义*/ 
{ 
	ElemType			data;
	struct LinkNode		*next;
}LinkNode, *LinkList;	/* LinkList为指针类型*/
