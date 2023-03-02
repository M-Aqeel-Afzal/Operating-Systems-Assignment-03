#include<iostream>
#include<unistd.h>  
#include<string.h> 
#include<stdlib.h> 
#include<sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

int main(){
	int fd_1[2],fd_2[2],fd_3[2];
	pipe(fd_1),pipe(fd_2),pipe(fd_3);
	int id_0=fork();                          //CHILD one creation
	if(id_0 > 0)
	{
	 close(fd_1[1]);
	 int id_1=fork();                          //CHILD Two creation	  
	   if(id_1>0)
	      {
		close(fd_1[0]);
	        close(fd_2[1]);
	        int id_2=fork();                          //CHILD Three creation
	        if(id_2>0)
	           {
 	             close(fd_2[0]);
	             close(fd_3[1]);	                  
	             int id_3=fork();                          //CHILD Four creation
	             if(id_3>0)
	               {
			 close(fd_3[0]);
			 wait(0);
			 wait(0);
			 wait(0);
			 wait(0);
                       }
	               else 
			if(id_3==0)
	                 {                                                  //closing all pipe which are not need
			   dup2(fd_3[0],0);
			   execlp("/usr/bin/wc","wc",NULL);
	                 }
	 
	           }
	            else 
		     if(id_2==0)
	               {                                                //closing all pipe which are not need
			close(fd_3[0]);
			dup2(fd_2[0],0);
			dup2(fd_3[1],1);
			execlp("sum", "sum", NULL);  		
	               }
	               
	                
	      }
	      else 
		if(id_1==0)
	         {                                   //closing all pipe which are not need
		  close(fd_2[0]);
		  close(fd_3[0]);
		  close(fd_3[1]);
		  dup2(fd_1[0],0);
	          dup2(fd_2[1],1);     
		  execlp("/usr/bin/sort","sort","-r",NULL);
	         }
	
	}
	else
	 if(id_0==0)
	{                                             //closing all pipe which are not need
	  close(fd_1[0]);
	  close(fd_2[0]);
	  close(fd_2[1]);
	  close(fd_3[0]);
	  close(fd_3[1]);
	  dup2(fd_1[1],1);
	  execl("grep","grep",  "a .",NULL);
	}
	
	
	
		
}
