# Pointer-based vectors

`src.hpp` preserves the supplied signatures and implements only the four
function bodies. The pointer table is one-based and zero-initialized. Empty
vectors allocate no element storage. Each nonempty vector stores its size and
capacity in slots 0 and 1, followed by the elements.

When full, a vector doubles its capacity, copies its metadata and elements,
and releases its old allocation. Thus append takes amortized O(1) time and
lookup takes O(1) time. Initialization and cleanup take O(n) time; total space
is O(n + m), where m is the number of appended elements. Each function declares
only O(1) local variables. Cleanup releases all allocations and resets p.

Local validation uses `tests/vector_test.cpp`: comparison with std::vector,
extreme integer values, empty cleanup, one million elements in one vector,
and one element in each of one million vectors.

Run with:

```sh
g++ -std=c++11 -O2 -Wall -Wextra -pedantic tests/vector_test.cpp -o /tmp/vector_test
/tmp/vector_test
```

The supplied submission client was repaired to implement the `submit_code`
method already called by its command-line interface.
