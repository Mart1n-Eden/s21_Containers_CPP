#ifndef S21_LIST_H
#define S21_LIST_H

#include "../s21_containers.h"

namespace S21 {

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 private:
  struct Node {
    value_type value_;
    Node* prev_;
    Node* next_;
    Node() : value_(), prev_(nullptr), next_(nullptr) {}
    Node(const value_type& value)
        : value_(value), prev_(nullptr), next_(nullptr) {}
  };

 public:
  list() : head_{nullptr}, tail_{nullptr}, end_{nullptr}, size_{0} {
    end_ = new Node();
    refresh();
  }

  list(size_type n) : head_{nullptr}, tail_{nullptr}, end_{nullptr}, size_{0} {
    if (n >= max_size()) {
      throw std::out_of_range("Limits exceeded");
    }
    end_ = new Node();
    for (size_type i = 0; i < n; ++i) {
      push_back(value_type());
    }
  }

  list(std::initializer_list<value_type> const& items)
      : head_{nullptr}, tail_{nullptr}, end_{nullptr}, size_{0} {
    end_ = new Node();
    for (auto& item : items) {
      push_back(item);
    }
  }

  list(const list& l)
      : head_{nullptr}, tail_{nullptr}, end_{nullptr}, size_{0} {
    end_ = new Node();
    this->copy(l);
  }

  list(list&& l) : head_{nullptr}, tail_{nullptr}, end_{nullptr}, size_{0} {
    swap(l);
  }

  ~list() {
    clear();
    delete end_;
  }

  list& operator=(list&& l) {
    swap(l);
    l.clear();
    return *this;
  }

  list& operator=(list& l) {
    if (this != &l) {
      list tmp(l);
      swap(tmp);
    }
    return *this;
  }

  const_reference front() { return !head_ ? end_->value_ : head_->value_; }

  const_reference back() { return !tail_ ? end_->value_ : tail_->value_; }

  bool empty() { return (size_ == 0); }

  size_type size() { return size_; }

  size_type max_size() {
    return (std::numeric_limits<size_type>::max() / sizeof(Node) / 2);
  }

  void clear() {
    while (!empty()) {
      pop_back();
    }
  }

  void push_back(const_reference value) {
    Node* new_node = new Node(value);
    if (empty()) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->prev_ = tail_;
      tail_->next_ = new_node;
      tail_ = new_node;
    }
    ++size_;
    refresh();
  }

  void pop_back() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    Node* pop_node = tail_;
    if (size_ == 1) {
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      tail_ = pop_node->prev_;
      tail_->next_ = nullptr;
    }
    delete pop_node;
    --size_;
    refresh();
  }

  void push_front(const_reference value) {
    Node* new_node = new Node(value);
    if (empty()) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->next_ = head_;
      head_->prev_ = new_node;
      head_ = new_node;
    }
    ++size_;
    refresh();
  }

  void pop_front() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    Node* pop_node = head_;
    if (size_ == 1) {
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      head_ = pop_node->next_;
      head_->prev_ = nullptr;
    }
    delete pop_node;
    --size_;
    refresh();
  }

  void swap(list& other) {
    using std::swap;
    swap(this->head_, other.head_);
    swap(this->tail_, other.tail_);
    swap(this->end_, other.end_);
    swap(this->size_, other.size_);
  }

  void merge(list& other) {
    if (!empty() && !other.empty()) {
      iterator it_this = begin();
      iterator it_other = other.begin();
      while (it_this != end()) {
        if (it_other != other.end()) {
          if (it_this.ptr_->value_ >= it_other.ptr_->value_) {
            insert(it_this, it_other.ptr_->value_);
            it_other++;
          } else {
            ++it_this;
          }
        } else {
          break;
        }
      }
      while (it_other != other.end()) {
        insert(it_this, it_other.ptr_->value_);
        ++it_other;
      }
    } else if (empty() && !other.empty()) {
      copy(other);
    }
    other.clear();
  }

  void reverse() {
    if (!empty()) {
      size_type ctr{0};
      for (iterator it = begin(); ctr <= size(); ++it) {
        ++ctr;
        std::swap(it.ptr_->prev_, it.ptr_->next_);
      }
      std::swap(head_, tail_);
    }
  }

  void unique() {
    if (!empty()) {
      for (iterator it = begin(); it != end(); ++it) {
        if (it.ptr_->value_ == it.ptr_->prev_->value_) {
          iterator del = (it - 1);
          erase(del);
        }
      }
    }
  }

  void sort() {
    if (size_ > 1) {
      quick_sort(begin(), --end());
    }
  }

  template <typename value_type>
  class ListIterator {
   public:
    ListIterator() { ptr_ = nullptr; }
    ListIterator(Node* ptr) : ptr_(ptr){};
    Node* getPtr() { return ptr_; }

    reference operator*() {
      if (!this->ptr_) {
        throw std::invalid_argument("Value is nullptr");
      }
      return this->ptr_->value_;
    }

    ListIterator operator++(int) {
      ptr_ = ptr_->next_;
      return *this;
    }

    ListIterator operator--(int) {
      ptr_ = ptr_->prev_;
      return *this;
    }

    ListIterator& operator++() {
      ptr_ = ptr_->next_;
      return *this;
    }

    ListIterator& operator--() {
      ptr_ = ptr_->prev_;
      return *this;
    }

    ListIterator operator+(const size_type value) {
      Node* tmp = ptr_;
      for (size_type i = 0; i < value; i++) {
        tmp = tmp->next_;
      }

      ListIterator res(tmp);
      return res;
    }

    ListIterator operator-(const size_type value) {
      Node* tmp = ptr_;
      for (size_type i = 0; i < value; i++) {
        tmp = tmp->prev_;
      }
      ListIterator res(tmp);
      return res;
    }

    bool operator==(ListIterator other) { return this->ptr_ == other.ptr_; }
    bool operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }

   private:
    Node* ptr_ = nullptr;
    friend class list<T>;
  };

  template <typename value_type>
  class ListConstIterator : public ListIterator<T> {
   public:
    ListConstIterator(ListIterator<T> other) : ListIterator<T>(other) {}
    const T& operator*() { return ListIterator<T>::operator*(); }
  };

  //  List Member type
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  iterator begin() const {
    return !head_ ? iterator(end_) : iterator(head_);
  }  // added const

  iterator end() const { return iterator(end_); }  // added const

  const_iterator cbegin() const {
    return !head_ ? const_iterator(end_) : const_iterator(head_);
  }

  const_iterator cend() const { return const_iterator(end_); }

  iterator insert(iterator pos, const_reference value) {
    Node* current = pos.ptr_;
    Node* add = new Node(value);
    if (empty()) {
      add->next_ = end_;
      add->prev_ = end_;
      head_ = add;
      tail_ = add;
    } else {
      if (current == head_) {
        head_ = add;
      } else if (current == end_) {
        tail_ = add;
      }
      add->next_ = current;
      add->prev_ = current->prev_;
      current->prev_->next_ = add;
      current->prev_ = add;
    }
    ++size_;
    refresh();
    return iterator(add);
  }

  void erase(iterator pos) {
    Node* tmp = pos.getPtr();
    Node* del;
    if (tmp == nullptr || tmp == end_)
      throw std::invalid_argument("Invalid arg");
    if (tmp == head_) head_ = tmp->next_;
    if (tmp == tail_) tail_ = tmp->prev_;
    del = tmp;
    tmp->prev_->next_ = tmp->next_;
    tmp->next_->prev_ = tmp->prev_;
    --size_;
    end_->value_ = (int)size_;
    delete del;
    refresh();
  }

  void splice(const_iterator pos, list& other) {
    if (!other.empty()) {
      for (iterator it = other.begin(); it != other.end(); ++it) {
        insert(pos, *it);
      }
      other.clear();
    }
  }

  template <typename... Args>
  void insert_many_front(Args&&... args) {
    (push_back(std::forward<Args>(args)), ...);
  }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    (push_front(std::forward<Args>(args)), ...);
  }

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args) {
    auto iter = (insert(pos, std::forward<Args>(args)), ...);
    return iter;
  }

 private:
  Node* head_;
  Node* tail_;
  Node* end_;
  size_type size_;

  void refresh() {
    if (end_) {
      end_->next_ = head_;
      end_->prev_ = tail_;
      end_->value_ = size();
      if (head_) {
        head_->prev_ = end_;
      }
      if (tail_) {
        tail_->next_ = end_;
      }
    }
  }

  void quick_sort(iterator left, iterator right) {
    if (left == right || left == end_ || right == end_ || left == tail_) {
      return;
    }
    iterator pivot = partition(left, right);
    quick_sort(left, --pivot);
    quick_sort(++pivot, right);
  }

  iterator partition(iterator first, iterator last) {
    value_type val = last.ptr_->value_;
    iterator it = first;

    for (iterator i = first; i != last; ++i) {
      if (i.ptr_->value_ <= val) {
        std::swap(it.ptr_->value_, i.ptr_->value_);
        ++it;
      }
    }
    std::swap(it.ptr_->value_, last.ptr_->value_);
    return it;
  }

  void copy(const list& l) {
    Node* current = l.head_;
    for (size_type i = 0; i != l.size_; ++i) {
      push_back(current->value_);
      current = current->next_;
    }
  }
};

}  // namespace S21

#endif  // S21_LIST_H