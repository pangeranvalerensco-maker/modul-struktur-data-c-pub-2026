#define MAX 10
int queue[MAX];
int rear = -1; // front selalu di indeks 0

int isEmpty(){
    return rear == -1;
}

int isFull(){
    return rear == MAX - 1;
}

void enqueue(int data){
    if (isFull())
    {
        printf("Queue penuh!\n");
        return;
    }
    queue[++rear] = data; // tambahkan di belakang
    printf("Data %d ditambahkan.\n", data);
}

void dequeue(){
    if (isEmpty())
    {
        printf("Queue kosong!\n");
        return;
    }
    printf("Data %d diambil.\n", queue[0]);
    for (int i = 0; i < rear; i++)
    { // geser semua elemen ke kiri
        queue[i] = queue[i + 1];
    }
    rear--; // kurangi rear karena satu elemen hilang
}

int frontElement(){
    if (isEmpty())
        return -1;
    return queue[0];
}

void tampilkanQueue(){
    if (isEmpty())
    {
        printf("Queue kosong.\n");
        return;
    }
    printf("Isi queue (depan->belakang): ");
    for (int i = 0; i <= rear; i++)
        printf("|%d| ", queue[i]);
    printf("\n");
}