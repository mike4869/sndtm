#ifndef MYSORT_H
#define MYSORT_H
#include <chrono>
#include <stack>
using std::swap;
template <typename T>
/*---------------------------------------------------------------------*/
/*Ordenamiento por insercion*/
double InsertionSort(T *a, int n)
 {
    auto start = std::chrono::high_resolution_clock::now();
    T c;
    int k;
    for (int i = 1; i < n; i++) {
        c = a[i];
        k = i - 1;
        while (k >= 0 && a[k] > c) {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = c;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_elapsed = end - start;
    std::chrono::microseconds microsec = std::chrono::duration_cast<std::chrono::microseconds>(time_elapsed);
    return microsec.count();

}
/*-----------------------------------------------------------------------*/
template <typename T>
bool is_sorted(T *array, int n ){
    for(int i=0; i<n-1;i++){
        if(array[i]>array[i+1]) return false;
    }
    return true;
}
/*-----------------------------------------------------------------------*/
/*Quick Sort de forma recursiva*/
template <typename T>
int partition (T* arr, int low, int high)
{
    int pivot = (high+low)/2;
  swap(arr[pivot], arr[high]);
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < arr[high]) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

template <typename T>
void quicksort(T* arr, int low, int high)
{
     if (low >= high) {
    return;
  }
  int pivot = partition(arr, low, high);
  quicksort(arr, low, pivot - 1);
  quicksort(arr, pivot + 1, high);
}

template<typename T>
double quicksort_R_time(T* arr, int low, int high){
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(arr, low, high);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_elapsed = end - start;
    std::chrono::microseconds microsec = std::chrono::duration_cast<std::chrono::microseconds>(time_elapsed);
    return microsec.count();
}

/*-----------------------------------------------------------------------*/
/*Quick Sort de forma iterativa */
template <typename T>
double quickSortIterative(T* arr, int left, int right) 
{ 
     auto start = std::chrono::high_resolution_clock::now();
   
    std::stack<int> stack;
    stack.push(left);
    stack.push(right);

    while (!stack.empty()) {
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();

        T pivot = arr[(left + right) / 2];
        int i = left;
        int j = right;

        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j) {
            stack.push(left);
            stack.push(j);
        }
        if (i < right) {
            stack.push(i);
            stack.push(right);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_elapsed = end - start;
    std::chrono::microseconds microsec = std::chrono::duration_cast<std::chrono::microseconds>(time_elapsed);
    return microsec.count();
}
#endif