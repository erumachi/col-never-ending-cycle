# NeverEndingCycle

Your task is to design a class, or data structure, called CyclicDeque. This Deque has a few requirements, listed here:

The class should have the following attributes:

- maxSize: an integer describing the maximum size of the CyclicDeque.
- arr: A fixed-size array containing the contents of the CyclicDeque. You can assume the contents will always be integers.

You are only allowed to add integers as attributes.
You cannot create extra arrays anywhere.

The class should have the following methods:

- `getSize()`: returns the amount of items in the CyclicDeque.
- `isEmpty()`: returns a boolean stating whether or not the CyclicDeque is empty.
- `pop()`: removes the last inserted element from the CyclicDeque, and returns it. Returns null, NaN, or None if the CyclicDeque is empty.
- `dequeue()`: remove the first inserted element from the CyclicDeque, and returns it. Returns null, NaN, or None if the CyclicDeque is empty.
- `insert(i)`: Inserts integer i into the CyclicDeque. throws or prints an error if the CyclicDeque is full.

Some example usage:

```
CQ = CyclicDeque(3) # CyclicDeque of max size 5

assert CQ.getSize() == 0
assert CQ.isEmpty()

CQ.insert(1)
CQ.insert(2)
CQ.insert(3)

assert !CQ.isEmpty()

s = CQ.getSize() # s = 3

x = CQ.pop() # x = 3
y = CQ.dequeue() # y = 1
z = CQ.pop() # z = 2

s = CQ.getSize() # s = 0

e = CQ.pop()  # e = null, NaN, or None

CQ.insert(7)
CQ.insert(8)
CQ.insert(9)
# CQ.insert(10) - throws an error
```
