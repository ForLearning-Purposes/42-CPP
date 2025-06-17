#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "../inc/easyfind.hpp"

template <typename T>
void easyfind(T &container, const int value_to_find) {
    typename T::iterator is_found = std::find(container.begin(), container.end(), value_to_find);

    if (is_found == container.end()) {
        std::cout << "Value NOT found, but what is in *is_found iterator? -> | " << *is_found << " |"<< std::endl;
        throw std::runtime_error("Value not found in the container");
    } else {
        std::cout << "Value found: | " << *is_found << " |" << std::endl;
    }
    return;
}


/*
### Why use `iterator`?

- `std::find` returns an **iterator** pointing to the found element, or to `container.end()` if not found.
- An iterator is like a pointer that lets you access elements in a container without knowing the container's internal structure.
- You need an iterator to:
  - Check if the value was found (`is_found != container.end()`)
  - Access or modify the found element (`*is_found`)

### Can you use something else?

- You **must** use an iterator here because:
  - `std::find` returns an iterator, not an index or the value itself.
  - Not all containers (like `std::list`) support indexing (`[]`), so iterators are the generic way to access elements.
*/


#endif