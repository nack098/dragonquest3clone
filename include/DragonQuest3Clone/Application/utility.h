#pragma once

namespace Application {
template <typename T> struct Vector2 {
    T x, y;
    Vector2 normalize();
    void operator+(Vector2<T> &other);
    void operator-(Vector2<T> &other);
    Vector2() : x(0), y(0){};
    Vector2(T x, T y) : x(x), y(y){};
};
} // namespace Application
