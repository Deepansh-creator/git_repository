#include <stdio.h>
#include <unistd.h>
int main (){
pid_t pid = fork();
if(pid== -1){
perror("fork failed");
return 1;
}
else if(pid == 0){
// This is the child process
printf("Hello from the child process! PID:%d\n",getpid());
}
else{
// This is the parent process
printf("Hello from the parent process! PID:%d,child PID:%d\n",getpid(),pid);
}
return 0;
}
