#!/usr/bin/env python
# coding=utf-8

# 选择排序
def select_sort(arr):
    new_arr = arr
    for i in range(len(new_arr)):
        ind = i
        for j in range(i + 1, len(new_arr)):
            if new_arr[ind] > new_arr[j]:
                ind = j
        new_arr[i], new_arr[ind] = new_arr[ind], new_arr[i]
    return new_arr

# 快速排序
def quick_sort(arr, low, high):
    def partition(arr, low, high):
        i = (low - 1)
        pivot = arr[high]     
    
        for j in range(low , high): 
            if arr[j] <= pivot: 
                i = i + 1 
                arr[i], arr[j] = arr[j], arr[i] 
    
        arr[i + 1], arr[high] = arr[high], arr[i + 1] 
        return (i + 1) 

    new_arr = arr
    if low < high:
        pi = partition(new_arr, low, high)
        quick_sort(new_arr, low, pi - 1) 
        quick_sort(new_arr, pi + 1, high) 
    return new_arr

if __name__ == "__main__":
    arr = [5, 3, 6, 2, 10]
    # 选择排序
    print(select_sort(arr))
    # 快速排序
    print(quick_sort(arr, 0, len(arr) - 1))