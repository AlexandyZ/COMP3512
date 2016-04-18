#include <memory>
unique_ptr<int> p(nullptr), q(new int(5));
- move only semantics; cannot be copied; unique_ptr own the object.

unique_ptr<int> r(q);  // cannot compile
unique_ptr<int> r(move(q));  //ok, move the ownership from q to r, q becomes null.

shared_ptr: uses reference count