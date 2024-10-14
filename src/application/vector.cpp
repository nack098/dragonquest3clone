#include <DragonQuest3Clone/Application/utility.h>
#include <cmath>
namespace Application {

template <typename T> Vector2<T> Vector2<T>::normalize() {
    T denorm = std::sqrt(std::exp2(this->x) + std::exp2(this->y));
    return Vector2<T>(this->x / denorm, this->y / denorm);
}

template <typename T> void Vector2<T>::operator+(Vector2<T> &other) {
    this->x += other.x;
    this->y += other.y;
}
template <typename T> void Vector2<T>::operator-(Vector2<T> &other) {
    this->x -= other.x;
    this->y -= other.y;
}

} // namespace Application
