#include<iostream>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sstream>
#include<stdio.h>
#include<sys/wait.h>
#include<iomanip>
using namespace std;
int main(int argc, char **argv)
{
char *file=argv[1];

int fd[2],fd1[2],fd2[2];
int buf1,T_hold1;
double x = 0.0,x1=0.0,T_hold;
string s="",s1="";
string word="",hold="";
pipe(fd);
pipe(fd1);
pipe(fd2);
int pid1=fork();       //child1 creation
if(pid1>0)
	{
	char buf[160];
	char ch[160];


	int stream = open(file, O_RDONLY);
	 read(stream, buf, 160);

	s +=buf[0];
	s +=buf[1];
	s +=buf[2];
	s1 +=buf[4];
	cout<<"\nI AM PARENT "<<endl;
	stringstream degree(s);
	stringstream degree1(s1);
	    degree >> x;
	    degree1 >> x1;
	
	T_hold=x*x1;
	
	close(stream);

	ch[0]=T_hold+48;
	ch[1]='\n';
	int j=2;
		for(int i=0;i<160;i++)
		{
			if(i>5)
			{
				ch[j]=buf[i];
				j++;
			}
		}
cout<<"\nI AM SENDING DATA TO CHILD 1\n\n "<<endl;
	close(fd[0]);
	write(fd[1], ch, strlen(ch)+1); 
	       
	
	close(fd[1]); 
wait(NULL);
	}
else if(pid1==0)
{
	
	
int pid2=fork();       //child2 creation
      if(pid2>0)
	{
        
	 cout<<"            I AM  CHILD 1\n"<<endl;
	close(fd[1]);  
        char str[160]; 
	str[156]='\n';
	int count[6]={0,0,0,0,0,0};
	string str1[6]={"Paratha","Makhan","Anda","Sharbat","Doodh","Dahi"};
	
        read(fd[0], str, 156); 
	
hold +=str[0];
stringstream degree3(hold);
	    degree3 >> T_hold1;
	close(fd[0]);
        for(int i=0;i<157;i++)
	{
	
	if(str[i]=='\n'||str[i]=='\0'||str[i]==',')
	{
	
	if(word==str1[0])
	count[0]++;
	else if(word==str1[1])
	count[1]++;
	else if(word==str1[2])
	count[2]++;
	else if(word==str1[3])
	count[3]++;
	else if(word==str1[4])
	count[4]++;
	else if(word==str1[5])
	count[5]++;
	word="";
	if(str[i]==',')
	i++;
	}
        else
	{
	word +=str[i];
	}
	}
cout<<"<=======>  FREQUENCY TABLE  <=======>\n";
cout<<"___________________________"<<endl;
cout<<"|   "<<"Items         Frequency|"<<endl;
cout<<"|__________________________|"<<endl;
cout<<"|  "<<str1[0]<<"           "<<count[0]<<"     |"<<endl;
cout<<"|  "<<str1[1]<<"            "<<count[1]<<"     |"<<endl;
cout<<"|  "<<str1[2]<<"              "<<count[2]<<"     |"<<endl;
cout<<"|  "<<str1[3]<<"           "<<count[3]<<"     |"<<endl;
cout<<"|  "<<str1[4]<<"             "<<count[4]<<"     |"<<endl;
cout<<"|  "<<str1[5]<<"              "<<count[5]<<"     |"<<endl;
cout<<"|__________________________|"<<endl<<endl<<endl;

cout<<"<=======>  AFTER THRESHOLD  <=======>\n";
cout<<"___________________________"<<endl;
cout<<"|   "<<"Items         Frequency|"<<endl;
cout<<"|__________________________|"<<endl;
int k=0;
for(int i=0;i<6;i++)
{
if(count[i]>=T_hold1)
{
if(count[i]==3)
k=2;
if(count[i]==4)
k=1;
cout<<"|  "<<str1[i]<<right<<setw(k+13)<<count[i]<<setw(5)<<"|"<<endl;
k=0;
}

}
cout<<"|__________________________|"<<endl<<endl<<endl;

k=0;
for(int i=0;i<6;i++)
{
if(count[i]>=3)
{
str[157+k]=(char)count[i]+48;
k++;
}
}



        close(fd1[0]);
	write(fd1[1], str, strlen(str)+1);
	close(fd1[1]); 
	
wait(NULL);
	}
	else if(pid2==0)
	{
		
	int pid3=fork();       //child3 creation
      if(pid3>0)
	{

        cout<<"            I AM  CHILD 2\n"<<endl;
	
	close(fd1[1]);  
        char str[161]; 
	string str2[4],str1[6]={"Paratha","Makhan","Anda","Sharbat","Doodh","Dahi"};
	string str3[6]={"Paratha, Makhan","Paratha, Sharbat","Paratha, Doodh","Makhan, Sharbat","Makhan, Doodh","Sharbat, Doodh"};
	int count[6], count1[6]={0,0,0,0,0,0};
        read(fd1[0], str, 161); 
	close(fd1[0]);

string s3="",word="";
cout<<endl;
for(int i=0;i<4;i++)
{s3 +=str[157+i];
stringstream degree3(s3);
 degree3 >> count[i];
s3="";
}
int temp=0;

for(int i=1;i<157;i++)
	{
	
	if(str[i]=='\n'||str[i]=='\0'||str[i]==',')
	{ 
		str2[temp]=word;
		temp++;
		if(str[i]=='\n')
		{
			if(temp==3)
			{
			if(str2[0][0]=='P'&&str2[1][0]=='M')
			count1[0]++;
			 if(str2[0][0]=='P'&&str2[1][0]=='S')
			count1[1]++;
			 if(str2[0][0]=='P'&&str2[1][0]=='D')
			 count1[2]++;
			 if(str2[0][0]=='P'&&str2[2][0]=='M')
			count1[0]++;
			 if(str2[0][0]=='P'&&str2[2][0]=='S')
			count1[1]++;
			if(str2[0][0]=='P'&&str2[2][1]=='o')
			count1[2]++;
			if(str2[0][0]=='M'&&str2[1][0]=='S')
			count1[3]++;
			if(str2[0][0]=='M'&&str2[2][0]=='D')
			count1[4]++;
			 if(str2[1][0]=='M'&&str2[2][0]=='S')
			count1[3]++;

			if(str2[1][0]=='S'&&str2[2][0]=='D')
			count1[5]++;
			
			
			}
			 else if(temp==4)
			{
			 if(str2[0][0]=='P'&&str2[1][0]=='M')
			count1[0]++;
			 if(str2[0][0]=='P'&&str2[3][0]=='S')
			count1[1]++;
			 if(str2[0][0]=='P'&&str2[2][0]=='M')
			count1[0]++;
			 if(str2[0][0]=='P'&&str2[2][0]=='S')
			count1[1]++;
			 if(str2[1][0]=='M'&&str2[3][0]=='S')
			count1[3]++;
			 if(str2[2][0]=='M'&&str2[3][0]=='S')
			count1[3]++;
			
			}
		temp=0;
		}
		
		word="";
		
	if(str[i]==',')
	i++;
	}

        else
	{
	word +=str[i];
	}
	}

hold +=str[0];
stringstream degree3(hold);
	    degree3 >> T_hold1;
cout<<"<=======>  REVCEVIED FREQUENCY TABLE  <=======>\n";
cout<<"___________________________"<<endl;
cout<<"|   "<<"Items         Frequency|"<<endl;
cout<<"|__________________________|"<<endl;
cout<<"|  "<<str1[0]<<"           "<<count[0]<<"     |"<<endl;
cout<<"|  "<<str1[1]<<"            "<<count[1]<<"     |"<<endl;
cout<<"|  "<<str1[3]<<"           "<<count[2]<<"     |"<<endl;
cout<<"|  "<<str1[4]<<"             "<<count[3]<<"     |"<<endl;
cout<<"|__________________________|"<<endl<<endl<<endl;

cout<<"<=======>  FREQUENCY TABLE  <=======>\n";
cout<<"___________________________"<<endl;
cout<<"|   "<<"Items         Frequency|"<<endl;
cout<<"|__________________________|"<<endl;
cout<<"|  "<<str3[0]<<"     "<<count1[0]<<"   |"<<endl;
cout<<"|  "<<str3[1]<<"    "<<count1[1]<<"   |"<<endl;
cout<<"|  "<<str3[2]<<"      "<<count1[2]<<"   |"<<endl;
cout<<"|  "<<str3[3]<<"     "<<count1[3]<<"   |"<<endl;
cout<<"|  "<<str3[4]<<"       "<<count1[4]<<"   |"<<endl;
cout<<"|  "<<str3[5]<<"      "<<count1[5]<<"   |"<<endl;
cout<<"|__________________________|"<<endl<<endl<<endl;


cout<<"<=======>  AFTER THRESHOLD  <=======>\n";
cout<<"___________________________"<<endl;
cout<<"|   "<<"Items         Frequency|"<<endl;
cout<<"|__________________________|"<<endl;
int k=0;
for(int i=0;i<6;i++)
{
if(count1[i]>=T_hold1)
{
if(count1[i]==3||str3[i][0]=='M')
k=1;
cout<<"|  "<<str3[i]<<right<<setw(k+5)<<count1[i]<<setw(4)<<"|"<<endl;
k=0;
}

}
cout<<"|__________________________|"<<endl<<endl<<endl;


k=0;
for(int i=0;i<6;i++)
{
if(count1[i]>=3)
{
str[161+k]=(char)count1[i]+48;
k++;
}
}



        close(fd2[0]);
	write(fd2[1], str, strlen(str)+1);
	close(fd2[1]); 
	
wait(NULL);
	
	}
	else if(pid3==0)
	{
        
	char str[164]; 
	string str2[6],str3="Paratha, Makhan, Sharbat";
	int count1=0;
	close(fd2[1]);	
        read(fd2[0], str, 164); 
cout<<"            I AM  CHILD 3\n"<<endl;
	
	close(fd2[0]);

int temp=0;

for(int i=1;i<157;i++)
	{
	
	if(str[i]=='\n'||str[i]=='\0'||str[i]==',')
	{ 
		str2[temp]=word;
		temp++;
		if(str[i]=='\n')
		{
			if(temp==3)
			{
			
			if(str2[0][0]=='P'&&str2[1][0]=='M'&&str2[2][0]=='S')
			count1++;

			
			}
			 else if(temp==4)
			{
			
			 if(str2[0][0]=='P'&&str2[1][0]=='M'&&str2[3][0]=='S')
			count1++;
			if(str2[0][0]=='P'&&str2[2][0]=='M'&&str2[3][0]=='S')
			count1++;
			
			}
		temp=0;
		}
		
		word="";
		
	if(str[i]==',')
	i++;
	}

        else
	{
	word +=str[i];
	}
	}
	

hold +=str[0];
stringstream degree3(hold);
	    degree3 >> T_hold1;
cout<<"<=======>  FREQUENCY TABLE  <=======>\n";
cout<<"\n________________________________________"<<endl;
cout<<"|   "<<"        Items              Frequency|"<<endl;
cout<<"|_______________________________________|"<<endl;
cout<<"|  "<<str3<<right<<setw(10)<<count1<<setw(4)<<"|"<<endl;
cout<<"|_______________________________________|"<<endl<<endl<<endl;

cout<<"<=======>  AFTER THRESHOLD  <=======>\n";
if(count1>=T_hold)
{cout<<"\n________________________________________"<<endl;
cout<<"|   "<<"        Items              Frequency|"<<endl;
cout<<"|_______________________________________|"<<endl;
cout<<"|  "<<str3<<right<<setw(10)<<count1<<setw(4)<<"|"<<endl;
cout<<"|_______________________________________|"<<endl<<endl<<endl;
}

char ch[str3.length()+7];
for(int i=0;i<str3.length()+6;i++)
{ch[i]=str3[i];
if(i>=str3.length())
ch[i]=' ';
}
ch[str3.length()+6]=(char)count1+48;
int f=open("output.txt",O_CREAT|O_WRONLY,0777);             //Writing to OUTPUT.txt using dup 
dup2(f,1);                                
write(f,ch,str3.length()+7);                          
close(f);
  exit(0);
        }
	
	
	}

}


return 0;
}


















