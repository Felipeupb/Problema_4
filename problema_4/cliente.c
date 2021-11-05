#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgget(key_t key, int msgflg);

typedef struct _msgbuf {
    long mtype;
    char mtext[64];
}MsgBuf;


void* imprime_x(void *param){
    
    char name[40];
    printf("cual es tu numero? ");
    if (fgets(name, 40, stdin) != NULL)
    {
        name[strlen(name) -1 ] = 0;
    }

    while(1) 
    {
        printf("ingrese un comando \n");
        char comando[40];
    
    if (fgets(comando, 40, stdin) != NULL)
    {
        comando[strlen(comando) -1 ] = 0;
        
        if(strcmp(comando,"sub")==0)
        {
            printf("ingrese Evento \n");
            if(fgets(comando, 40, stdin) != NULL)
            {
                printf("td");
                
            }
        }
       
    }

    }

    return NULL;
}

int main(int argc, char *argv[])
{
    int len;

   system("touch cola1.txt");

   key_t key;

   if ((key = ftok("msgreq.txt", 'B')) == -1)
    {
        perror("ftok");
        exit(1);
    }

    int reqMsgId;

    if ((reqMsgId = msgget(key, 0644 | IPC_CREAT)) == -1)
    { 
        perror("msgreq msgget fails");
        exit(1);
    }
    MsgBuf resBuf;
    

    len = strlen("Hola") + 1; // por qué + 1?
    strncpy(resBuf.mtext,"Hola",len);
    resBuf.mtype = 1111; //
    if (msgsnd(reqMsgId, &resBuf, len, 0) == -1)
    {
        perror("msgsnd fails: ");
    }



    pthread_t threadID;
    pthread_create(&threadID,NULL,&imprime_x,NULL);

    pthread_join(threadID,NULL);
    
    
    
    exit(EXIT_SUCCESS);
}
