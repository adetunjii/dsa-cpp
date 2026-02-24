#include <queue>
#include <vector>
#include <ranges>

namespace queue {
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        const int N = deck.size();

        if (N == 0) return {};

        sort(deck.begin(), deck.end());
        
        std::queue<int> q;
        std::vector<int> res(N, 0);

        for (int i : std::views::iota(0, N)) q.push(i);

        for (auto& card : deck) {
            res[q.front()] = card;
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return res;
    }

}