#include "cyclic_dequeue.h"
#include <stdlib.h>

struct CyclicDequeue {
    size_t max_size;   // Max number of elements
    size_t idx_first;  // Index of the first element
    size_t idx_last;   // Index of the last element
    bool full_flag;    // Flag to differentiate empty from full
    int* queue;        // Array of elements
};


CyclicDequeue* cyclic_dequeue_new(size_t max_size) {
    if (max_size == 0) {
        return NULL;
    }
    CyclicDequeue* ret = malloc(sizeof(CyclicDequeue));
    if (ret == NULL) {
        return NULL;
    }
    ret->idx_first = 0;
    ret->idx_last = 0;
    ret->full_flag = false;
    ret->queue = malloc(sizeof(int) * max_size);
    if (ret->queue == NULL) {
        free(ret);
        return NULL;
    }
    ret->max_size = max_size;
    return ret;
}

void cyclic_dequeue_delete(CyclicDequeue* queue) {
    if (queue == NULL) {
        return;
    }
    free(queue->queue);
    free(queue);
}

size_t cyclic_dequeue_get_size(const CyclicDequeue* queue) {
    if (queue == NULL) {
        return 0;
    }
    if (queue->full_flag) {
        return queue->max_size;
    }
    if (queue->idx_first == queue->idx_last) {
        return 0;
    }
    if (queue->idx_first < queue->idx_last) {
        return queue->idx_last - queue->idx_first;
    } else {
        return (queue->max_size - queue->idx_first) + queue->idx_last;
    }
}

bool cyclic_dequeue_is_empty(const CyclicDequeue* queue) {
    return cyclic_dequeue_get_size(queue) == 0;
}

bool cyclic_dequeue_pop(CyclicDequeue* queue, int* elem) {
    if (elem == NULL || cyclic_dequeue_is_empty(queue)) {
        return false;
    }
    if (queue->idx_last > 0) {
        queue->idx_last--;
    } else {
        queue->idx_last = queue->max_size - 1;
    }
    if (queue->full_flag) {
        queue->full_flag = false;
    }
    *elem = queue->queue[queue->idx_last];
    return true;
}

bool cyclic_dequeue_dequeue(CyclicDequeue* queue, int* elem) {
    if (elem == NULL || cyclic_dequeue_is_empty(queue)) {
        return false;
    }
    *elem = queue->queue[queue->idx_first];
    if (queue->idx_first < (queue->max_size - 1)) {
        queue->idx_first++;
    } else {
        queue->idx_first = 0;
    }
    if (queue->full_flag) {
        queue->full_flag = false;
    }
    return true;
}

static bool cyclic_dequeue_is_full(const CyclicDequeue* queue) {
    if (queue == NULL) {
        return false;
    }
    return cyclic_dequeue_get_size(queue) == queue->max_size;
}

bool cyclic_dequeue_insert(CyclicDequeue* queue, int elem) {
    if (cyclic_dequeue_is_full(queue)) {
        return false;
    }
    queue->queue[queue->idx_last] = elem;
    if (queue->idx_last < (queue->max_size - 1)) {
        queue->idx_last++;
    } else {
        queue->idx_last = 0;
    }
    if (queue->idx_first == queue->idx_last) {
        queue->full_flag = true;
    }
    return true;
}
