
#include<iostream>
#include<unistd.h>  
#include<string.h> 
#include<stdlib.h> 
#include<sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
int main()
{
int arr[19];


	cout<<"Enter Total marks for each Assignment "<<endl;
	cin>>arr[0];
	cout<<"Enter Total marks for each Lab "<<endl;
	cin>>arr[1];
	cout<<"Enter Total marks for each project "<<endl;
	cin>>arr[2];
	cout<<"Enter Total marks for each final "<<endl;
	cin>>arr[3];

for(int i=4;i<7;i++)
{
	cout<<"Enter the Obtained Marks for Assignment: "<<i-3<<endl;
	cin>>arr[i];
	while(arr[i]>arr[0]||arr[i]<0)
	{
		cout<<"Wrong input please enter agian"<<endl;
		cin>>arr[i];
	}
}
for(int i=7;i<17;i++)
{
	cout<<"Enter the Obtained Marks for LAB: "<<i-6<<endl;
	cin>>arr[i];
	while(arr[i]>arr[1]||arr[i]<0)
	{
		cout<<"Wrong input please enter agian"<<endl;
		cin>>arr[i];
	}
}
cout<<"Enter the Obtained Marks for Project: "<<endl;
cin>>arr[17];
while(arr[17]>arr[2]||arr[17]<0)
{
	cout<<"Wrong input please enter agian"<<endl;
	cin>>arr[17];
}

cout<<"Enter the Obtained Marks for Final: "<<endl;
cin>>arr[18];
while(arr[18]>arr[3]||arr[18]<0)
{
	cout<<"Wrong input please enter agian"<<endl;
	cin>>arr[18];
}


cout<<endl<<"writing"<<endl;
int file=mkfifo("fifo2",0777);

int fd=open("fifo2",O_WRONLY);
write(fd,arr,19*4);
cout<<"written"<<endl;
close(fd);

return 0;
}


