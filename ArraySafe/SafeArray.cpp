# include <malloc.h>
# include <iostream>
# include"SafeArray.h"

using namespace std;

int main()
{
	Array array;
	array.ArrayInsert(1);
	array.ArrayOut(100);
	return 0;
}


bool Array::ArrayEmpty()
{
	if(count==-1) return OK;
	else return ERROR;
}

bool Array::ArrayFull()
{
	if(count>=(MAX-1)) return OK;
	else return ERROR;
}

void Array::ArrayInsert(int item)
{
	if(ArrayFull())
	{
	    cout<<"the array is full"<<endl;
	}
	else
	{
	    count++;
	    array[count]=item;
	}
}

int Array::ArrayOut(int pos)
{
    int number=0;
	if(ArrayEmpty()) return 0;
	if(pos>=MAX-1||pos>count) {cout<<"Stack Array Bounds"<<endl;return 0;}
    number=array[pos];
    for(int i=pos;i<count;i++)
    {
        array[i]=array[i+1];
    }
    count--;
    return number;
}

