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
	cout<<"------------------------------��ӭ����ѧ������ϵͳ------------------------------"<<endl;
	while(1)
	{
		cout<<"1.ѧ����Ϣ"<<endl<<"2.���ѧ��"<<endl<<"3.ɾ��ѧ��"<<endl<<"4.����ɼ�"<<endl<<"5.�˳�����"<<endl;
		cin>>num;
		if(num==1)
		{
			int a;
			while(1){
			cout<<"��ѡ��鿴��ѧ������"<<endl<<"1.ȫ��ѧ��"<<endl<<"2.һ��ѧ��"<<endl;
			cin>>a;
			if(a==1){print();listAllStudent(L);break;}
			else if(a==2)
			{
				int num;
				cout<<"����ѧ�����"<<endl;
			    cin>>num;
				print();
				listStudent(L,num);
				break;
			}
			else cout<<"����������ָ��"<<endl;
			}
		}
		else if(num==2)
		{
			char a;
			addStudent(L);
			cout<<"�������������һ��"<<endl;
			cin>>a;
			continue;
		}
		else if(num==3)
		{
			char a;
			int num;
			cout<<"ɾ������ѧ��"<<endl;
			cin>>num;
			deleteStudent(L,num);
			cout<<"�������������һ��"<<endl;
			cin>>a;
			continue;
		}
		else if(num==4)
		{
			char a,b;
			int num1,num2;
			cout<<"����ѧ�����"<<endl;
			cin>>num1;
			cout<<"����ѧ���ɼ�"<<endl;
			cin>>num2;
			gradeStudent(L,num1,num2);
			while(1){
			cout<<"�Ƿ����¼����һ��ѧ���ɼ�?(Y/N)"<<endl;
			cin>>a;
			if(a=='N'){break;}
			else if(a=='Y')
			{
            num1++;
			cout<<"����ѧ���ɼ�"<<endl;
			cin>>num2;
			gradeStudent(L,num1,num2);
			}
			else {cout<<"����������"<<endl;continue;}
			}
			cout<<"�������������һ��"<<endl;
			cin>>b;
		}
		else if(num==5){break;}
		else{cout<<"ָ�����"<<endl;}
	}
}
