#include<iostream>
#include<unistd.h>  
#include<string.h> 
#include <sstream>
#include<stdlib.h> 
#include<sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
int main()
{
int fd=open("fifo2",O_RDONLY);


cout<<"read"<<endl;


string word="";
int weigthage[4]={15,30,15,40};
double abs[4]={0,0,0,0};
double total=0.0,temp=0.0;
string grade;
int arr[19],j=0;
read(fd,arr,19*4);

for(int i=0;i<19;i++)    
   cout<<arr[i]<<"   ";
close(fd);
j=1;
cout<<endl;
for(int i=4;i<7;i++,j++)     //4,5,6                //absolute finding for assignments
{

	temp=(float)(arr[i]*weigthage[0]/3)/arr[0];
	abs[0] +=temp;
	cout<<"Assignment: "<<j<<" absolutes: "<<temp<<endl;
}
j=1;
for(int i=7;i<17;i++,j++)     //7,8,9,10,11,12,13,14,15,16                //absolute finding for labs
{

	temp=(float)(arr[i]*weigthage[1]/10)/arr[1];
	abs[1] +=temp;
	cout<<"lab: "<<j<<" absolutes: "<<temp<<endl;
}

abs[2] =(float)(arr[17]*weigthage[2])/arr[2];                          //absolute finding for project
cout<<"porject absolutes: "<<abs[2]<<endl;
abs[3] =(float)(arr[18]*weigthage[3])/arr[3];
cout<<"final Exam absolutes: "<<abs[3]<<endl;                          //absolute finding for final
for(int i=0;i<4;i++) 
	total +=abs[i];


cout<<"Overall Absolute: "<<total<<endl;
	if(total>=90)
	grade="A+";
	else if(total<=89&&total>=86)
	grade="A";
	else if(total<=85&&total>=82)
	grade="A-";
	else if(total<=81&&total>=78)
	grade="B+";
	else if(total<=77&&total>=74)
	grade="B";
	else if(total<=73&&total>=70)
	grade="B-";
	else if(total<=69&&total>=66)
	grade="C+";
	else if(total<=65&&total>=62)
	grade="C";
	else if(total<=61&&total>=58)
	grade="C-";
	else if(total<=57&&total>=54)
	grade="D+";
	else if(total<=53&&total>=50)
	grade="D";
	else if(total<50)
	grade="F";
cout<<"<=====================>    GRADE: "<<grade<<"     <=======================>"<<endl;
return 0;
}


