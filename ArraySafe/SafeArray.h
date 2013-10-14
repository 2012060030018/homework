# define ERROR false
# define OK true
# define MAX 100
# include <malloc.h>

class Array {
	private:
	int array[MAX];
	int count;
	public:
	bool ArrayEmpty();
	bool ArrayFull();
	void ArrayInsert(int item);
	int ArrayOut(int pos);
	Array()
	{
	   count=-1;
	}
	~Array()
	{
		free(array);
	}
};
