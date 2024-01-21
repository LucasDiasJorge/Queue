#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int array[MAX_SIZE];
    int front, rear;
} Queue;

// Função para inicializar a fila
void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Função para verificar se a fila está cheia
int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Função para enfileirar um elemento
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Erro: Fila cheia, não é possível enfileirar.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->array[queue->rear] = value;
}

// Função para desenfileirar um elemento
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Erro: Fila vazia, não é possível desenfileirar.\n");
        return;
    }

    if (queue->front == queue->rear) {
        // Último elemento na fila
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

// Função para obter o elemento na frente da fila sem removê-lo
int front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Erro: Fila vazia, não há elemento na frente.\n");
        return -1;  // Valor sentinela indicando erro
    }

    return queue->array[queue->front];
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Elemento na frente da fila: %d\n", front(&myQueue));

    dequeue(&myQueue);
    printf("Elemento na frente da fila após desenfileirar: %d\n", front(&myQueue));

    return 0;
}
