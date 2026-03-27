#include <vector>
#include <ranges>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> res;

    for (int i : std::views::iota(1, n+1)) {
        if (((i % 3) == 0) && ((i % 5) == 0)) {
            res.push_back("FizzBuzz");
        } else if ((i % 3) == 0) {
            res.push_back("Fizz");
        } else if ((i % 5) == 0) {
            res.push_back("Buzz");
        } else {
            res.push_back(std::to_string(i));
        }
    }
    
    return res;
}