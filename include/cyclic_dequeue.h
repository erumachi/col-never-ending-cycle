#ifndef CYCLIC_DEQUEUE_H
#define CYCLIC_DEQUEUE_H

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct CyclicDequeue CyclicDequeue;

    // Create a new queue
    CyclicDequeue* cyclic_dequeue_new(size_t max_size);

    // Delete a queue
    void cyclic_dequeue_delete(CyclicDequeue* queue);

    // Returns the amount of items in the CyclicDeque
    size_t cyclic_dequeue_get_size(const CyclicDequeue* queue);

    // Returns a boolean stating whether or not the CyclicDeque is empty
    bool cyclic_dequeue_is_empty(const CyclicDequeue* queue);

    // Removes the last inserted element from the CyclicDeque, and returns it into elem.
    // Returns true if it popped something, false if the queue was empty.
    bool cyclic_dequeue_pop(CyclicDequeue* queue, int* elem);

    // Remove the first inserted element from the CyclicDeque, and returns it.
    // Returns true if it popped something, false if the queue was empty.
    bool cyclic_dequeue_dequeue(CyclicDequeue* queue, int* elem);

    // Inserts integer i into the CyclicDeque.
    // Returns false if the CyclicDeque is full, true otherwise.
    bool cyclic_dequeue_insert(CyclicDequeue* queue, int elem);

#ifdef __cplusplus
}
#endif

#endif
