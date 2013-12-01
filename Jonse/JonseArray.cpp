#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;
 
int JonesArray(int N, int M) 
{
    int winner;
	int * jones = (int *)malloc(N*sizeof(int));
    int i,j,t; 
    for(i=0;i<N;i++) 
        jones[i]=i+1; 
    t=0; 
    for(i=N;i>=1;i--) 
    { 
        t=(t+M-1)%i; 
//        cout<<jones[t]<<" "; 
        for(j=t+1;j<=i-1;j++) 
        { 
            jones[j-1]=jones[j]; 
        } 
    } 
    winner=jones[0];
	free(jones);
	return winner;
}

int main(int argc, char *argv[])
{
	if(argc<3)
		exit(400);
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	double C1 = clock();
	int winner = JonesArray(N,M);
	double C2 = clock();
	cout<<"\n\n";
	cout<<"JonesArray() winner is "<<winner<<".\tCompute Time is "<<(C2-C1)<<"\n\n";
	return 0;	
}

