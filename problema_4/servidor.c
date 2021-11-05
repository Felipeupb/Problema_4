#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0644


typedef struct Evento Evento;

struct Evento
 {
    char *name;
    int c1;
    int c2;
    int c3;
};

void trigger(Evento e);
void list(Evento e);



void* imprime_x(void *param){
    
    struct Evento e1 = {"evento1",0, 0, 0};
    
    struct Evento e2 = {"evento2",0, 0, 0};
    
    struct Evento e3 = {"evento3",0, 0, 0};
    
    struct Evento e4 = {"evento4",0, 0, 0};
    
    struct Evento e5 = {"evento5",0, 0, 0};
    
    struct Evento e6 = {"evento6",0, 0, 0};
    


    while(1) 
    {
        printf("ingrese un comando \n");
        char comando[40];
    
    if (fgets(comando, 40, stdin) != NULL)
    {
        comando[strlen(comando) -1 ] = 0;
        
        //printf(comando);

        
        if(strcmp(comando,"exit")==0)
        {
            printf("-------------------------\n");
            printf("el servido ha sido finalizado\n");
            printf("-------------------------\n");
            exit(-1);
        }
        if(strcmp(comando,"trigger")==0)
        {
            printf("ingrese Evento \n");
            if(fgets(comando, 40, stdin) != NULL)
            {
                comando[strlen(comando) -1 ] = 0;
                if(strcmp(comando,"e1")==0)
                {
                    trigger(e1);
                } 
                if(strcmp(comando,"e2")==0)
                {
                    trigger(e2);
                } 
                if(strcmp(comando,"e3")==0)
                {
                    trigger(e3);
                } 
                if(strcmp(comando,"e4")==0)
                {
                    trigger(e4);
                } 
                if(strcmp(comando,"e5")==0)
                {
                    trigger(e5);
                } 
                if(strcmp(comando,"e6")==0)
                {
                    trigger(e6);
                } 
            }              
        }
        if(strcmp(comando,"list")==0)
        {
            printf("ingrese Evento \n");
            if(fgets(comando, 40, stdin) != NULL)
            {
                comando[strlen(comando) -1 ] = 0;
                if(strcmp(comando,"e1")==0)
                {
                    list(e1);
                } 
                if(strcmp(comando,"e2")==0)
                {
                    list(e2);
                } 
                if(strcmp(comando,"e3")==0)
                {
                    list(e3);
                } 
                if(strcmp(comando,"e4")==0)
                {
                    list(e4);
                } 
                if(strcmp(comando,"e5")==0)
                {
                    list(e5);
                } 
                if(strcmp(comando,"e6")==0)
                {
                    list(e6);
                } 
            } 

        }
        if(strcmp(comando,"all")==0)
        {
            printf("-------------------------\n");
            printf("Lista de Eventos \n Evento1 \n Evento2 \n Evento3 \n evento4 \n Evento5 \n Evento6 \n");
            printf("-------------------------\n");
            printf("Lista de Cliente \n cliente1 \n cliente2 \n cliente3 \n");
        }
    }

    }

    return NULL;
}

int main(int argc, char *argv[])
{
   
    
    pthread_t threadID;
    pthread_create(&threadID,NULL,&imprime_x,NULL);

    pthread_join(threadID,NULL);
    
    
    exit(EXIT_SUCCESS);
}

void trigger(Evento e)
{
    printf("-------------------------\n");
    printf("el evento %s ha sido generado \n",e.name);

    if (e.c1!=0)
    {
        printf("el cliente 1 esta interesado \n");
        //avisa
    }  
    if (e.c2!=0)
    {
        printf("el cliente 2 esta interesado \n");
        //avisa
    }   
    if (e.c3!=0)
    {
        printf("el cliente 3 esta interesado \n");
        //avisa
    }     
}
void list(Evento e)
{
    printf("-------------------------\n");
    printf("lista de personas suscritas al %s\n",e.name);

    if (e.c1!=0)
    {
        printf("el cliente 1 esta suscrito \n");
        //avisa
    }  
    if (e.c2!=0)
    {
        printf("el cliente 2 esta suscrito \n");
        //avisa
    }   
    if (e.c3!=0)
    {
        printf("el cliente 3 esta suscrito \n");
        //avisa
    }  
    if (e.c1==0&&e.c2==0&&e.c3==0)
    {
        printf("no hay clientes suscritos \n");
    }   
}
