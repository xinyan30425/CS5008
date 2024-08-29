#include <stdio.h>
#include "priority_queue.h"


int main() {
    PRIORITY_QUEUE hQueue = priority_queue_init_default();

    if (priority_queue_insert(hQueue, 10,20) == SUCCESS) {
        printf("Successfully Inserted (10)\n");
    }
    if (priority_queue_insert(hQueue, 5, 10) == SUCCESS) {
        printf("Successfully Inserted (5)\n");
    }
    if (priority_queue_insert(hQueue, 15, 30) == SUCCESS) {
        printf("Successfully Inserted (15)\n");
    }
    if (priority_queue_insert(hQueue, 1, 5) == SUCCESS) {
        printf("Successfully Inserted (1)\n");
    }

    Status status;
    while (!priority_queue_is_empty(hQueue)) {
        int front_value = priority_queue_front(hQueue, &status);
        if (status == SUCCESS) {
            printf("Highest priority item: %d\n", front_value);
        }
        if (priority_queue_service(hQueue) == SUCCESS) {
            printf("Removed highest priority item\n");
        }
    }

    priority_queue_destroy(&hQueue);
    return 0;
}
