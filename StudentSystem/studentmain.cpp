#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include"student.h"

using namespace std;
int main()
{
	int num;
	StudentLink L;
	Student stu0;
	L=&stu0;
	L->next=NULL;
	cout<<"------------------------------欢迎进入学生管理系统------------------------------"<<endl;
	while(1)
	{
		cout<<"1.学生信息"<<endl<<"2.添加学生"<<endl<<"3.删除学生"<<endl<<"4.输入成绩"<<endl<<"5.退出程序"<<endl;
		cin>>num;
		if(num==1)
		{
			int a;
			while(1){
			cout<<"请选择查看的学生容量"<<endl<<"1.全部学生"<<endl<<"2.一名学生"<<endl;
			cin>>a;
			if(a==1){print();listAllStudent(L);break;}
			else if(a==2)
			{
				int num;
				cout<<"输入学生序号"<<endl;
			    cin>>num;
				print();
				listStudent(L,num);
				break;
			}
			else cout<<"请重新输入指令"<<endl;
			}
		}
		else if(num==2)
		{
			char a;
			addStudent(L);
			cout<<"按任意键返回上一级"<<endl;
			cin>>a;
			continue;
		}
		else if(num==3)
		{
			char a;
			int num;
			cout<<"删除几号学生"<<endl;
			cin>>num;
			deleteStudent(L,num);
			cout<<"按任意键返回上一级"<<endl;
			cin>>a;
			continue;
		}
		else if(num==4)
		{
			char a,b;
			int num1,num2;
			cout<<"输入学生序号"<<endl;
			cin>>num1;
			cout<<"输入学生成绩"<<endl;
			cin>>num2;
			gradeStudent(L,num1,num2);
			while(1){
			cout<<"是否继续录入下一名学生成绩?(Y/N)"<<endl;
			cin>>a;
			if(a=='N'){break;}
			else if(a=='Y')
			{
            num1++;
			cout<<"输入学生成绩"<<endl;
			cin>>num2;
			gradeStudent(L,num1,num2);
			}
			else {cout<<"请重新输入"<<endl;continue;}
			}
			cout<<"按任意键返回上一级"<<endl;
			cin>>b;
		}
		else if(num==5){break;}
		else{cout<<"指令错误！"<<endl;}
	}
}
