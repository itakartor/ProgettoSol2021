#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct _Node {
    void*           data;
    struct _Node*    next;
} Node;

typedef struct _NodoComandi {
  char cmd;
  char* name;
  int n;
} NodoComando;

typedef struct _comandoclient {
  char comando;
  char* parametro;
  long connfd;
} ComandoClient;

typedef struct msg {
    int len;
    char comando;    //lunghezza del messaggio
    char *arg;       //messaggio
} msg_t;
/**
*
*/
typedef struct _Queue {
    Node*             head;
    Node*             tail;
    unsigned long       len;
} Queue;

typedef struct _file {
  char* nome;
  char* buffer; //contenuto
  long length; //per fare la read e la write, meglio se memorizzato
  int is_opened;
  pthread_mutex_t lock;
} fileRam;

Queue* initQueue();
void* pop(Queue **q);
void* pop2(Queue **q);

void printQueueNodoComando(Queue *q);
void printQueueFiles(Queue *q);

int push(Queue **q, void* el);
int pushTesta(Queue **q, void* el);
void insert(Queue **q, char cmd, char* name, int n);

int removeFromQueue(Queue **q, Node* toDelete);
Node* fileExistsServer(Queue *q, char* nomefile);
void* returnFirstEl(Queue *q);

#endif
