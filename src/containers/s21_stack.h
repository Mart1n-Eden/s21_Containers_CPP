#ifndef S21_STACK_H
#define S21_STACK_H

#include "../s21_containers.h"

namespace S21 {

template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 private:
  struct Node {
    T info_;
    Node *value_;
    Node() : info_(), value_(nullptr) {}
    Node(const value_type &value) : info_(value), value_(nullptr) {}
  };

 public:
  stack() : size_{0}, head_{nullptr} {}

  stack(std::initializer_list<value_type> const &items)
      : size_{0}, head_{nullptr} {
    for (const auto &i : items) push(i);
  }

  stack(const stack<T> &s) : size_{0}, head_{nullptr} { copy_stack(s); }

  stack(stack<T> &&s) : size_{s.size_}, head_{s.head_} {
    s.head_ = nullptr;
    s.size_ = 0;
  }

  ~stack() { clear(); }

  stack &operator=(const stack<T> &s) {
    if (this != &s) {
      clear();
      copy_stack(s);
    }
    return *this;
  }

  stack &operator=(stack<T> &&s) {
    if (this != &s) {
      clear();
      stack<T> tmp(std::move(s));
      swap(tmp);
    }
    return *this;
  }

  void clear() {
    while (!empty()) {
      pop();
    }
    size_ = 0;
  }

  bool empty() { return head_ == nullptr; }

  size_type size() { return size_; }

  void push(const_reference value) {
    Node *newNode;
    newNode = new Node;
    newNode->info_ = value;
    newNode->value_ = head_;
    head_ = newNode;
    ++size_;
  }

  const_reference top() const {
    if (head_ == nullptr) {
      throw std::out_of_range("Stack is empty");
    }
    return head_->info_;
  }

  void pop() {
    Node *temp;
    if (!empty()) {
      temp = head_;
      head_ = head_->value_;
      delete temp;
      --size_;
    }
  }

  void swap(stack<T> &s) {
    std::swap(size_, s.size_);
    std::swap(head_, s.head_);
  }

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    for (auto i : {std::forward<Args>(args)...}) {
      push(i);
    }
  }

 private:
  size_t size_;
  Node *head_;

  void copy_stack(const stack<T> &s) {
    Node *newNode, *current, *last;
    if (!empty()) {
      clear();
    }
    if (s.head_ == nullptr) {
      size_ = 0;
      head_ = nullptr;
    } else {
      current = s.head_;
      head_ = new Node;
      head_->info_ = current->info_;
      head_->value_ = nullptr;
      last = head_;
      current = current->value_;
      ++size_;
      while (current != nullptr) {
        newNode = new Node;
        newNode->info_ = current->info_;
        newNode->value_ = nullptr;
        last->value_ = newNode;
        last = newNode;
        current = current->value_;
        ++size_;
      }
    }
  }
};
}  // namespace S21

#endif  // S21_STACK_H