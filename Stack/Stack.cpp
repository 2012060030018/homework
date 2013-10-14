# include <stdlib.h>
# include <malloc.h>
# include <iostream>
# include"Stack.h"

using namespace std;

int main()
{
	int i=0;
	Stack s;
	s.StackPush(100009);
	s.StackPop(&i);
	cout<<i;
	return 0;
}

void Stack::StackPush(Elemtype item)
{
	NodePtr p;
	p=(NodePtr)malloc(sizeof(StackNode));
	if(p==0){cout<<"error"<<endl;}
	else
	{
		p->elem=item;
	    p->next=top;
	    top=p;
	}
}

void Stack::StackPop(Elemtype *item)
{
	if(StackEmpty()){cout<<"error"<<endl;}
	else
	{
		NodePtr p;
		p=top;
		top=p->next;
		*item=p->elem;
		free(p);
	}
}

bool Stack::StackEmpty()
{
	if(top==NULL) return OK;
	else return ERROR;
}
