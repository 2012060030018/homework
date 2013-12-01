#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

int JonesMathe(int N, int M) // 这是低复杂度的实现 
{
	int winner=0;
	for(int i=2; i<=N; i++)
		winner=(winner+M)%i;
	winner+=1;
	return winner;
}

int main(int argc, char *argv[])
{
	if(argc<3)
		exit(400);
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	double C1 = clock();
	int winner = JonesMathe(N,M);
	double C2 = clock();
	cout<<"\n\n";
	cout<<"JonesMathe() winner is "<<winner<<".\tCompute Time is "<<(C2-C1)<<"\n\n";
	return 0;	
}

