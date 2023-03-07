#include <iostream>
#include <tuple>

template <typename... T>
void print(const std::tuple<T...>& tu) {
    constexpr size_t N = std::tuple_size_v<std::tuple<T...>>;
    [&]<size_t... I>(std::index_sequence<I...>) {
        (..., (std::cout << std::get<I>(tu) << ",\n"[I == N - 1]));
    }(std::make_index_sequence<N>());
}

int main() {
    std::tuple a(1, 2, 3, 4.5, "6");
    print(a);
    return 0;
}