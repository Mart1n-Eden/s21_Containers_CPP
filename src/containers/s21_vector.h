#ifndef CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_VECTOR_H_

#include "../s21_containers.h"

namespace S21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  vector() : arr_(nullptr), size_(0), capacity_(0) {}

  explicit vector(size_type n) : size_(n), capacity_(n) {
    arr_ = new value_type[capacity_];
    if (arr_ == nullptr) {
      throw std::bad_alloc();
    }
    for (size_type i = 0; i < capacity_; ++i) {
      arr_[i] = value_type();
    }
  }

  vector(std::initializer_list<value_type> const &items)
      : vector(items.size()) {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = *(items.begin() + i);
    }
  }

  vector(const vector<value_type> &v) : vector(v.size_) {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = v.arr_[i];
    }
  }

  vector(vector<value_type> &&v) noexcept
      : arr_(v.arr_), size_(v.size_), capacity_(v.capacity_) {
    v.arr_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }

  ~vector() {
    delete[] arr_;
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  vector<T> &operator=(const vector<value_type> &v) noexcept {
    if (this != &v) {
      vector<T> copy(v);
      swap_(copy);
    }
    return *this;
  }

  vector<T> &operator=(vector<value_type> &&v) noexcept {
    if (this != &v) {
      vector<T> copy(std::move(v));
      swap_(copy);
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= size_ || size_ == 0) {
      throw std::out_of_range("Index out of array range");
    }
    return arr_[pos];
  }

  reference operator[](size_type pos) { return arr_[pos]; }

  const_reference front() const { return arr_[0]; }

  const_reference back() const { return arr_[size_ - 1]; }

  iterator data() noexcept { return arr_; }

  iterator begin() noexcept { return arr_; }

  iterator end() noexcept { return (arr_ + size_); }

  bool empty() const noexcept { return size_ == 0; }

  size_type size() const noexcept { return size_; }

  size_type max_size() const noexcept {
    return std::numeric_limits<std::size_t>::max() / sizeof(value_type) / 2;
  }

  void reserve(size_type size) {
    if (size > max_size()) {
      throw std::length_error("Can't allocate memory of this size");
    }
    if (size >= size_) {
      vector<value_type> tmp(size);
      for (size_type i = 0; i < size_; ++i) {
        tmp.arr_[i] = arr_[i];
      }
      tmp.size_ = size_;
      *this = std::move(tmp);
    }
  }

  size_type capacity() const noexcept { return capacity_; }

  void shrink_to_fit() {
    if (capacity_ > size_) {
      vector<value_type> tmp(size_);
      for (size_type i = 0; i < size_; ++i) {
        tmp.arr_[i] = arr_[i];
      }
      *this = std::move(tmp);
    }
  }

  void clear() noexcept {
    delete[] arr_;
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  iterator insert(const_iterator pos, const_reference value) {
    size_type j = 0;
    size_type index = pos - (*this).begin();
    vector<value_type> tmp(size_ + 1);
    for (size_type i = 0; i < tmp.size_; ++i) {
      if (i == index) {
        tmp.arr_[i] = value;
      } else {
        tmp.arr_[i] = arr_[j];
        ++j;
      }
    }
    *this = std::move(tmp);
    return arr_ + index;
  }

  void erase(const_iterator pos) {
    size_type j = 0;
    size_type index = pos - (*this).begin();
    vector<value_type> tmp(size_ - 1);
    for (size_type i = 0; i < tmp.size_; ++i) {
      if (i == index) {
        ++j;
        tmp.arr_[i] = arr_[j];
        ++j;
      } else {
        tmp.arr_[i] = arr_[j];
        ++j;
      }
    }
    *this = std::move(tmp);
  }

  void push_back(const_reference value) {
    if (size_ == capacity_) {
      this->reserve(capacity_ * 2);
      arr_[size_] = value;
      ++size_;
    } else {
      arr_[size_] = value;
      ++size_;
    }
  }

  void pop_back() { --size_; }

  void swap_(vector &other) noexcept {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(arr_, other.arr_);
  }

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    vector<value_type> tmp{args...};
    iterator current_pos = begin() + (pos - begin());
    for (size_t i = 0; i < tmp.size(); ++i) {
      current_pos = insert(current_pos, tmp[i]);
      ++current_pos;
    }

    return current_pos;
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    insert_many(end(), args...);
  }

 private:
  value_type *arr_;
  size_type size_;
  size_type capacity_;
};

}  // namespace S21

#endif  // CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_VECTOR_H_
