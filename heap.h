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
  std::vector<T> data; 
  int m_ary; 
  PComparator comp; 
  void heapUp(size_t indx);
  void heapDown(size_t indx);




};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_ary(m), comp(c) {
    if (m < 2) {
      throw std::invalid_argument("Heap arity must be at least 2.");
    }
}


template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
    
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    data.push_back(item);
    heapUp(data.size() - 1);
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
    throw std::underflow_error("Heap is empty.");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();



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
    throw std::underflow_error("Heap is empty.");


  }
  data[0] = data.back();
  data.pop_back();
  if (!empty()){
    heapDown(0);
  } 



}
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return data.size();
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::heapUp(size_t indx) {
    while (indx > 0) {
        size_t parentInd = (indx - 1) / m_ary;
        if (comp(data[indx], data[parentInd])) {
            std::swap(data[indx], data[parentInd]);
            indx = parentInd;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapDown(size_t indx) {
    size_t childInd = indx * m_ary + 1;
    while (childInd < data.size()) {
        size_t minMaxChild = childInd;
        for (int i = 1; i < m_ary && (childInd + i) < data.size(); ++i) {
            if (comp(data[childInd + i], data[minMaxChild])) {
                minMaxChild = childInd + i;
            }
        }
        if (comp(data[minMaxChild], data[indx])) {
            std::swap(data[indx], data[minMaxChild]);
            indx = minMaxChild;
            childInd = indx * m_ary + 1;
        } else {
            break;
        }
    }
}



#endif

