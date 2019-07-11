int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child (new process)
    char * const arg[] = {"ls", NULL};
    char * const envp[] = {NULL};
    
    execvp("ls", arg);
    execl("/bin/ls", "ls", NULL);
    execlp("ls","ls",NULL);
    execle("/bin/ls","ls",NULL,arg);
    execv("/bin/ls",arg);

  } else { // parent goes down this path (main)
   int rc_wait = wait(NULL);
   printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
}
return 0;
}
