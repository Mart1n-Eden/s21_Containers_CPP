#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include "../s21_containers.h"

namespace S21 {

template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 private:
  struct Node {
    T info_;
    Node* value_;
    Node() : info_(), value_(nullptr) {}
    Node(const value_type& value) : info_(value), value_(nullptr) {}
  };

 public:
  queue() : size_{0}, queueFront_{nullptr}, queueRear_{nullptr} {}

  queue(std::initializer_list<value_type> const& items)
      : size_{0}, queueFront_{nullptr}, queueRear_{nullptr} {
    for (const auto& i : items) push(i);
  }

  queue(const queue<T>& q)
      : size_{0}, queueFront_{nullptr}, queueRear_{nullptr} {
    Node* current = q.queueFront_;
    while (current != nullptr) {
      push(current->info_);
      current = current->value_;
    }
  }

  queue(queue<T>&& q)
      : size_{q.size_}, queueFront_{q.queueFront_}, queueRear_{q.queueRear_} {
    q.size_ = 0;
    q.queueFront_ = nullptr;
    q.queueRear_ = nullptr;
  }

  ~queue() { clear(); }

  queue& operator=(const queue& q) {
    if (this != &q) {
      clear();
      queue tmp(q);
      swap(tmp);
    }
    return *this;
  }

  queue& operator=(queue&& q) {
    if (this != &q) {
      clear();
      queue tmp(std::move(q));
      swap(tmp);
    }
    return *this;
  }

  void clear() {
    while (!empty()) {
      pop();
    }
    //    size_ = 0;
  }

  const_reference front() const {
    if (empty()) {
      throw "Queue is empty";
    }
    return queueFront_->info_;
  }

  const_reference back() const {
    if (empty()) {
      throw "Queue is empty";
    }
    return queueRear_->info_;
  }

  bool empty() const { return queueFront_ == nullptr; }

  size_type size() { return size_; }

  void push(const_reference value) {
    Node* newNode;
    newNode = new Node;
    newNode->info_ = value;
    newNode->value_ = nullptr;
    if (queueRear_ == nullptr) {
      queueRear_ = newNode;
      queueFront_ = newNode;
    } else {
      queueRear_->value_ = newNode;
      queueRear_ = newNode;
    }
    ++size_;
  }

  void pop() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    Node* tmp = queueFront_;
    queueFront_ = queueFront_->value_;
    delete tmp;
    --size_;
  }

  void swap(queue& q) {
    std::swap(size_, q.size_);
    std::swap(queueFront_, q.queueFront_);
    std::swap(queueRear_, q.queueRear_);
  }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    for (auto i : {std::forward<Args>(args)...}) {
      push(i);
    }
  }

 private:
  size_t size_;
  Node* queueFront_;
  Node* queueRear_;
};
}  // namespace S21

#endif  // S21_QUEUE_H