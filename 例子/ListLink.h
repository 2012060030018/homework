# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

typedef int Elemtype;

typedef struct LinkNode{
	Elemtype data;
	struct LinkNode *next;
}LinkNode,*ListLink;
int ListLinkInitial(ListLink *L);
int ListLinkRelease(ListLink L);
int ListLinkInsert(ListLink L,Elemtype e,int pos);
int ListLinkDelete(ListLink L,int pos);
LinkNode* ListLinkGet(ListLink L,int pos);
LinkNode* ListLinkLocate(ListLink L,Elemtype e);
void MakeDot4ListLink(ListLink L);
