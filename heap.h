#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

std::vector<T> data_;
PComparator comp_;
int ary_; // number of children (from d-ary)

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int ary, PComparator comp) : ary_(ary), comp_(comp) {} 

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {} 

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data_.push_back(item);

  std::size_t index = data_.size() - 1;
  while (index != 0) {
        std::size_t parent_index = (index - 1) / 2;
        T& current = data_[index];
        T& parent = data_[parent_index];

        if (comp_(current, parent)) {
          std::swap(current, parent);
          index = parent_index;
        }
        else {
          break;
        }
    }
} 

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("No items in heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("No items in heap");
  }

  data_[0] = data_.back();
  data_.pop_back();

  if(!empty()) {
    std::size_t index = 0;
      while(true) {
          std::size_t max = 1;
          
          for(size_t i = 1; i < ary_; ++i) {
            std::size_t child = (ary_ * index) + 1 + i;

            if ((child < data_.size()) && comp_(data_[max], data_[child])) {
              max = child;

            }
          }

          if (comp_(data_[index], data_[max])) {
              std::swap(data_[index], data_[max]);
              index = max;
          }
          else {
              break;
          }
      }
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data_.empty();

}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size();

}

#endif

