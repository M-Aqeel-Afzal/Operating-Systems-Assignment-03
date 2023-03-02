#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
using namespace std;
int main(){

int fd_1[2],fd_2[2],fd_3[0],fd_4[2];
pipe(fd_1);
pipe(fd_2);
pipe(fd_3);
pipe(fd_4);

int pid_1 = fork();                            //CHILD 1 Creation
if(pid_1 > 0){

			int pid_2 = fork();                            //CHILD 2 Creation
		if(pid_2>0)
		{


			int pid_3 = fork();                            //CHILD 3 Creation
			if(pid_3>0)
			{

				int pid_4 = fork();                            //CHILD 4 Creation
				if(pid_4>0)
				{
					wait(0);
					
					cout<<"  WC Execution "<<endl;                  //WC Execution
					close(fd_4[1]);
					dup2(fd_4[0],0);
					execlp("wc","wc",NULL);

				}
				else if(pid_4==0)
				{
					close(fd_4[0]);
					dup2(fd_4[1],1);
					execlp("ls","ls",NULL);
				
				}
				wait(0);
				cout<<"                SUM Execution "<<endl;                  //SUM Execution
				close(fd_3[1]);
				dup2(fd_3[0],0);
				execlp("sort","sort","-r",NULL);
			}
			else if(pid_3==0)
			{
				close(fd_3[0]);
				dup2(fd_3[1],1);
				execlp("ls","ls",NULL);
			
			}

			wait(0);
			cout<<"                sort Execution "<<endl;                  //SORT Execution
			close(fd_2[1]);
			dup2(fd_2[0],0);
			execlp("sum","sum","-r",NULL);

		}
		else if(pid_2==0)
		{
		close(fd_2[0]);
		dup2(fd_2[1],1);
		execlp("ls","ls",NULL);
		
		}	

	close(fd_1[1]);
	dup2(fd_1[0],0);
	cout<<"                grep Execution "<<endl;                  //GREP Execution
	execlp("grep","grep","a *.*",NULL);


}else if(pid_1 == 0){
	
		close(fd_1[0]);
		dup2(fd_1[1],1);
		execlp("ls","ls",NULL);
}


return 0;
}

