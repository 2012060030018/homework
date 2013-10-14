# include <stdlib.h>
# include <malloc.h>
# define ERROR false
# define OK true
# define Elemtype int

typedef struct node{
	Elemtype elem;
	struct node* next;
}StackNode,*NodePtr;

class Stack{
    private:
		NodePtr top;
    public:
		void StackPush(Elemtype item);
		void StackPop(Elemtype *item);
		bool StackEmpty();
		Stack()
		{
			top=0;
		}
		~Stack()
		{
			NodePtr p;
			while(top!=0)
			{
				p=top;
				top=p->next;
				free(p);
			}
			free(top);
		}
};
