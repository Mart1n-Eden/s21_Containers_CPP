#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include "../s21_containersplus.h"

namespace S21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  array() noexcept : arr_() {}

  array(std::initializer_list<value_type> const &items) : array() {
    for (size_type i = 0; i < items.size(); ++i) {
      arr_[i] = *(items.begin() + i);
    }
  }

  reference operator[](size_type pos) { return arr_[pos]; }

  reference at(size_type pos) {
    if (pos >= size_ || size_ == 0) {
      throw std::out_of_range("Index out of array range");
    }
    return arr_[pos];
  }

  const_reference front() const { return arr_[0]; }

  const_reference back() const { return arr_[size_ - 1]; }

  iterator data() noexcept { return arr_; }

  iterator begin() noexcept { return arr_; }
  iterator end() noexcept { return arr_ + size_; }

  size_type size() const noexcept { return size_; }

  size_type max_size() const noexcept { return size_; }

  bool empty() const noexcept { return size_ == 0; }

  void swap(array &other) noexcept {
    value_type tmp;
    for (size_type i = 0; i < size_; ++i) {
      tmp = other.arr_[i];
      other.arr_[i] = arr_[i];
      arr_[i] = tmp;
    }
  }

  void fill(const_reference value) {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = value;
    }
  }

 private:
  size_type size_ = N;
  value_type arr_[N];
};

template <typename T>
class array<T, 0u> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  reference operator[](size_type) {
    throw std::out_of_range("Index out of array range");
  }

  reference at(size_type) {
    throw std::out_of_range("Index out of array range");
  }

  const_reference front() const { return *static_cast<T *>(nullptr); }

  const_reference back() const { return *static_cast<T *>(nullptr); }

  iterator data() noexcept { return nullptr; }

  iterator begin() noexcept { return nullptr; }

  iterator end() noexcept { return nullptr; }

  size_type size() const noexcept { return 0; }

  size_type max_size() const noexcept { return 0; }

  bool empty() const noexcept { return true; }

  void swap(array &) noexcept {}

  void fill(const_reference) {}
};

}  // namespace S21

#endif  // S21_ARRAY_H
