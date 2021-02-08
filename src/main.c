#include "cyclic_dequeue.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

    // Just reporting the examples of the challenge here
    CyclicDequeue* queue = cyclic_dequeue_new(3);
    if (queue == NULL) {
        fprintf(stderr, "Error creating the queue\n");
        return 1;
    }

    // I could use <assert.h>, but I'm pretty sure it won't work in release mode :^)
    // I'll just do these prints instead
    if (cyclic_dequeue_get_size(queue) == 0) {
        printf("Yes, the queue has size zero as expected\n");
    }
    if (cyclic_dequeue_is_empty(queue)) {
        printf("Yes, the queue is empty as expected\n");
    }

    if (!cyclic_dequeue_insert(queue, 1)) {
        fprintf(stderr, "Error inserting 1 in the queue\n");
        goto cleanup_and_error_exit;
    }
    if (!cyclic_dequeue_insert(queue, 2)) {
        fprintf(stderr, "Error inserting 2 in the queue\n");
        goto cleanup_and_error_exit;
    }
    if (!cyclic_dequeue_insert(queue, 3)) {
        fprintf(stderr, "Error inserting 3 in the queue\n");
        goto cleanup_and_error_exit;
    }

    if (!cyclic_dequeue_is_empty(queue)) {
        printf("Yes, the queue is not empty as expected\n");
    }

    size_t curr_size = cyclic_dequeue_get_size(queue);
    printf("Size after inserting 1, 2 and 3 is: %d\n", curr_size);

    int x = 0;
    if (!cyclic_dequeue_pop(queue, &x)) {
        fprintf(stderr, "Error popping from the queue\n");
        goto cleanup_and_error_exit;
    }
    printf("Popped element: %d\n", x);

    int y = 0;
    if (!cyclic_dequeue_dequeue(queue, &y)) {
        fprintf(stderr, "Error dequeueing from the queue\n");
        goto cleanup_and_error_exit;
    }
    printf("Dequeued element: %d\n", y);

    int z = 0;
    if (!cyclic_dequeue_pop(queue, &z)) {
        fprintf(stderr, "Error popping from the queue\n");
        goto cleanup_and_error_exit;
    }
    printf("Popped element: %d\n", z);

    size_t s = cyclic_dequeue_get_size(queue);
    printf("Size is currently: %d\n", s);

    int e = 0;
    if (!cyclic_dequeue_pop(queue, &e)) {
        printf("Could not pop from an empty queue, as expected\n");
    } else {
        fprintf(stderr, "Popped element: %d, even though I shouldn't\n", e);
        goto cleanup_and_error_exit;
    }

    if (!cyclic_dequeue_insert(queue, 7)) {
        fprintf(stderr, "Error inserting 7 in the queue\n");
        goto cleanup_and_error_exit;
    }
    if (!cyclic_dequeue_insert(queue, 8)) {
        fprintf(stderr, "Error inserting 8 in the queue\n");
        goto cleanup_and_error_exit;
    }
    if (!cyclic_dequeue_insert(queue, 9)) {
        fprintf(stderr, "Error inserting 9 in the queue\n");
        goto cleanup_and_error_exit;
    }

    if (!cyclic_dequeue_insert(queue, 10)) {
        printf("Error inserting 10 in the queue, as expected\n");
    } else {
        fprintf(stderr, "Inserting 10 in the queue successfully when it should fail\n");
        goto cleanup_and_error_exit;
    }

    // Cleanup for the good case
    cyclic_dequeue_delete(queue);
    return 0;

 cleanup_and_error_exit:
    cyclic_dequeue_delete(queue);
    return 1;
}
