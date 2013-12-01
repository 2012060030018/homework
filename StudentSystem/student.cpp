# include <iostream>
# include <stdlib.h>
# include <malloc.h>
# include"student.h"

int StudentCount = 1;
using namespace std;

void listStudent(StudentLink L, int pos) {
	int i = 0;
	student stu;
	StudentLink p;
	p = L;
	if (pos >= StudentCount) {
		cout << "对不起，有错误" << endl;
	} else {
		while (i < pos) {
			i++;
			p = p->next;
		}
		stu = p->stu;
		printStudent(stu);
	}
}

void addStudent(StudentLink L) {
	StudentLink p;
	p = L;
	if (p == NULL) {
		cout << "对不起，有错误" << endl;
	} else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = (Student *) malloc(sizeof(Student));
		if (p->next == NULL) {
			cout << "对不起，有错误" << endl;
		} else {
			p = p->next;
			p->next = NULL;
			p->stu.grade = 0;
			p->stu.sq = StudentCount;
			cout << "请输入学生姓名：" << endl;
			cin >> p->stu.name;
			cout << "请输入学生姓别：" << endl;
			cin >> p->stu.sex;
			cout << "请输入学生学号：" << endl;
			cin >> p->stu.num;
			StudentCount++;
			cout << "添加成功" << endl;
		}
	}
}

void deleteStudent(StudentLink L, int pos) {
	StudentLink p, q;
	p = L;
	int i = 0, j = 0;
	if (pos >= StudentCount) {
		cout << "对不起，有错误" << endl;
	} else {
		while (i < pos - 1) {
			i++;
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		free(q);
		StudentCount--;
		p = L;
		while (p->next) {
			j++;
			p = p->next;
			p->stu.sq = j;
		}
		cout << "已删除" << endl;
	}
}

void gradeStudent(StudentLink L, int pos, int grade) {
	StudentLink p;
	p = L;
	int i = 0;
	if (pos >= StudentCount) {
		cout << "对不起，有错误" << endl;
	} else {
		while (p != NULL && i < pos) {
			i++;
			p = p->next;
		}
		if (p == NULL) {
			cout << "对不起，有错误" << endl;
		} else {
			p->stu.grade = grade;
			cout << "输入成功" << endl;
		}
	}
}

void printStudent(student stu) {
	cout << stu.sq << '\t' << stu.name << '\t' << stu.sex << '\t' << stu.num
			<< '\t' << stu.grade << endl;
}

void listAllStudent(StudentLink L) {
	StudentLink p;
	p = L;
	if (p == NULL) {
		cout << "对不起，有错误" << endl;
	}
	p = p->next;
	if (p == NULL) {
		cout << "对不起，有错误" << endl;
	} else {
		while (p != NULL) {
			printStudent(p->stu);
			p = p->next;
		}
	}
}

void print() {
	cout << "学生序号" << '\t' << "学生姓名" << '\t' << "学生性别" << '\t' << "学生学号" << '\t'
			<< "学生成绩" << endl;
}
