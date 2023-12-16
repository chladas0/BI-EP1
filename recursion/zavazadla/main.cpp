#include <iostream>
#include <vector>
std::vector<int> dest;

int moves(int idx, int pos) {
    // reached the end of the containers
    if (idx == dest.size())
        return 0;

    // the container in on the right spot
    if (dest[idx] == pos)
        return moves(idx + 1, pos);

    // 2^k - 1 needed moves + move to the next container
    return (1 << (dest.size() - idx - 1)) + moves(idx + 1, 3 - pos - dest[idx]);
}

int min_moves(int cnt){
    return moves(0, cnt == 0 ? 0 : dest[0]);
}

int main() {
    int N; std::cin >> N;

    while(N--)
    {
        int containers;
        std::cin >> containers;

        dest.resize(containers);
        for (int i = 0; i < containers; ++i)
            std::cin >> dest[i];

        std::cout << "Je treba " << min_moves(containers) << " presunu." << std::endl;
    }
    return 0;
}
