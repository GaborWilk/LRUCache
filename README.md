# LRUCache

LRUCache (Least Recently Used) implementation using C++17.
It consists a linked list (to store the actual items) and a hashtable of pointers to the linked list nodes.
As a result, this gives O(1) operations (assuming a decent hash function). The multithreaded version can be done easily, just lock the whole structure (granular locking is not needed).

**How does it work:**

- On an access of a value, you move the corresponding node in the linked list to the head.
- When you need to remove a value from the cache, you remove from the tail end.
- When you add a value to cache, you just place it at the head of the linked list.

## Usage

```cpp
/* include necessary resources */
#include <LRUCache.h>

using namespace lru;

/* get LRUCache object with given capacity */
LRUCache<int, int> cache(1u);

/* add element */
lru.add(1, 10);

/* get element */
int element = lru.get(1);

/* check whether the given element is present */
bool isPresent = lru.exist(1);

/* get size */
uint32_t size = lru.size();

/* get capacity (max number of elements) */
uint32_t capacity = lru.capacity();

/* print all elements */
lru.print();

/* clear cache */
lru.clear();
```

For further information see the test.cpp file.

## 3rd party libraries
[Catch2](https://github.com/catchorg/Catch2) for Unit Testing.

## License
[MIT](https://choosealicense.com/licenses/mit/)
