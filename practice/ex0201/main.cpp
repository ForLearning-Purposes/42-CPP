#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <iomanip>
#include <cctype>
#include <cmath>

template <typename Container>
class PmergeMe {
public:
    typedef typename Container::value_type ValueType;
    typedef typename Container::iterator Iterator;

    // Constructors
    PmergeMe() {}
    PmergeMe(char **av) {
        std::string args_string;
        for (int i = 1; av[i]; i++) {
            args_string += av[i];
            args_string += " ";
        }

        std::istringstream ss(args_string);
        ValueType n;
        while (ss >> n) {
            if (std::find(container.begin(), container.end(), n) != container.end())
                throw std::runtime_error("Duplicate value detected");
            container.push_back(n);
        }
    }

    // Sorting entry point
    void sort() {
        clock_t start = clock();
        recursiveSort(container, 1);
        clock_t end = clock();
        float elapsed = static_cast<float>(end - start) / CLOCKS_PER_SEC;
        std::cout << "Sorted " << container.size() 
                  << " elements with " << container_type()
                  << " in " << std::fixed << std::setprecision(6) 
                  << elapsed << "s" << std::endl;
    }

    // Print container
    void print() const {
        for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

private:
    Container container;

    // Recursive Ford–Johnson sorting
    void recursiveSort(Container &container, int block_of_elements) {
        int unit_size = container.size() / block_of_elements;
        if (unit_size < 2) return; // base case

        bool is_odd = (unit_size % 2 == 1);
        Iterator start = container.begin();
        Iterator end = container.begin() + ((block_of_elements * unit_size) - (is_odd * block_of_elements));

        // Pairwise compare & swap of blocks
        for (Iterator it = start; it < end; it += (block_of_elements * 2)) {
            if (*(it + (block_of_elements - 1)) > *(it + ((block_of_elements * 2) - 1))) {
                for (int i = 0; i < block_of_elements; i++) {
                    std::swap(*(it + i), *(it + i + block_of_elements));
                }
            }
        }

        // Recurse with doubled block_of_elements
        recursiveSort(container, block_of_elements * 2);

        std::cout << "\n\nCheck: " << std::endl;
        print();
        std::cout << std::endl;

        // Split into main and pend
        Container main;
        Container pend;
        ValueType odd = 0;
        Container leftover;

        // First two representatives go into main
        main.push_back(*(start + block_of_elements - 1));
        main.push_back(*(start + block_of_elements * 2 - 1));

        // Alternate filling pend and main
        for (Iterator it = start + block_of_elements * 2; it < end; it += block_of_elements) {
            pend.push_back(*(it + block_of_elements - 1));
            it += block_of_elements;
            if (it < end)
                main.push_back(*(it + block_of_elements - 1));
        }

        if (is_odd) odd = *(end + block_of_elements - 1);

        // Collect any trailing elements not in pairs
        leftover.insert(leftover.end(), end + (block_of_elements * is_odd), container.end());

        // Merge pendants into main
        insertWithJacobsthal(main, pend, odd, leftover, container, is_odd, block_of_elements);
    }

    // Jacobsthal sequence
    int Jacobsthal(int k) {
        return static_cast<int>(round((pow(2, k + 1) + pow(-1, k)) / 3));
    }

    // Insert pendants into main using Jacobsthal schedule
    void insertWithJacobsthal(Container &main, Container &pend, ValueType odd, 
                              Container &leftover, Container &container, bool is_odd, int block_of_elements) {
        Iterator pos;

        if (pend.size() == 1) {
            pos = std::upper_bound(main.begin(), main.end(), *pend.begin());
            main.insert(pos, *pend.begin());
        } else {
            size_t jc = 3;
            size_t count = 0;
            while (!pend.empty()) {
                size_t idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
                if (idx > pend.size()) idx = pend.size();

                size_t decrease = 0;
                while (idx) {
                    size_t limit = Jacobsthal(jc + count) - decrease;
                    if (limit > main.size()) limit = main.size();

                    pos = std::upper_bound(main.begin(), main.begin() + limit, *(pend.begin() + idx - 1));
                    main.insert(pos, *(pend.begin() + idx - 1));
                    pend.erase(pend.begin() + idx - 1);

                    idx--;
                    decrease++;
                    count++;
                }
                jc++;
            }
        }

        // Insert odd representative
        if (is_odd) {
            pos = std::upper_bound(main.begin(), main.end(), odd);
            main.insert(pos, odd);
        }

        // Rebuild container from sorted representatives
        Container rebuilt;
        for (typename Container::iterator it = main.begin(); it != main.end(); ++it) {
            typename Container::iterator found = std::find(container.begin(), container.end(), *it);
            rebuilt.insert(rebuilt.end(), found - (block_of_elements - 1), found + 1);
        }
        rebuilt.insert(rebuilt.end(), leftover.begin(), leftover.end());
        container = rebuilt;
    }

    std::string container_type() {
        if (typeid(container) == typeid(std::vector<ValueType>))
            return "std::vector";
        if (typeid(container) == typeid(std::deque<ValueType>))
            return "std::deque";
        return "unknown";
    }
};


















// -------------------- DEMO MAIN --------------------
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./pmergeme numbers..." << std::endl;
        return 1;
    }

    try {
        // Use vector
        PmergeMe<std::vector<int> > sorter_vec(argv);
        std::cout << "Before: ";
        sorter_vec.print();
        sorter_vec.sort();
        std::cout << "After:  ";
        sorter_vec.print();

        // Use deque (just for demonstration)
        PmergeMe<std::deque<int> > sorter_deq(argv);
        sorter_deq.sort();
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const char *msg) {
        std::cerr << "Error: " << msg << std::endl;
    }
}
