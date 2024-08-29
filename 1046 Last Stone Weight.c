typedef struct {
    int *data;
    int size;
    int capacity;
} PriorityQueue;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (int *)realloc(pq->data, pq->capacity * sizeof(int));
    }
    pq->data[pq->size++] = value;

    int index = pq->size - 1;
    while (index > 0 && pq->data[index] > pq->data[(index - 1) / 2]) {
        swap(&pq->data[index], &pq->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int pop(PriorityQueue *pq) {
    int value = pq->data[0];
    pq->data[0] = pq->data[--pq->size];

    int index = 0;
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < pq->size && pq->data[left] > pq->data[largest]) {
            largest = left;
        }
        if (right < pq->size && pq->data[right] > pq->data[largest]) {
            largest = right;
        }
        if (largest == index) {
            break;
        }
        swap(&pq->data[index], &pq->data[largest]);
        index = largest;
    }
    return value;
}

int lastStoneWeight(int *stones, int stonesSize) {
    PriorityQueue pq;
    pq.data = (int *)malloc(stonesSize * sizeof(int));
    pq.size = 0;
    pq.capacity = stonesSize;

    for (int i = 0; i < stonesSize; i++) {
        push(&pq, stones[i]);
    }

    while (pq.size > 1) {
        int stone1 = pop(&pq);
        int stone2 = pop(&pq);
        if (stone1 != stone2) {
            push(&pq, stone1 - stone2);
        }
    }

    int result = pq.size == 0 ? 0 : pq.data[0];
    free(pq.data);
    return result;
}