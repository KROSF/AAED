#ifndef COLA_HPP
#define COLA_HPP
#include <queue>
template <typename T>
class Cola{
    public:
    Cola() = default;
    bool vacia() const { return C.empty(); }
    const T& frente() const { return C.front(); }
    void pop() { C.pop();}
    void push(const T& x) { C.push(x);}
    private:
    std::queue<T> C;
};
#endif
