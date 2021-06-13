#!/usr/bin/env python
# coding=utf-8

# 插入排序
def insert_sort(arr):
    new_arr = arr
    for i in range(1, len(new_arr)):
        key = new_arr[i]
        for j in range(i - 1, 0, -1):
            if new_arr[j] < new_arr[j - 1]:
                new_arr[j], new_arr[j - 1] = new_arr[j - 1], new_arr[j]
    return new_arr

# 冒泡排序
def bubble_sort(arr):
    new_arr = arr
    times = 1
    while times:
        for i in range(1, len(new_arr)):
            times = 0
            for j in range(len(new_arr) - i):
                if new_arr[j] <= new_arr[j + 1]:
                    continue
                new_arr[j], new_arr[j + 1] = new_arr[j + 1], new_arr[j]
                times += 1
    
    return new_arr

# 归并排序
def merge_sort(arr, low, high):
    new_arr = arr
    if high - low <= 1:
        if high - low == 1 and new_arr[low] > new_arr[high]:
            new_arr[low], new_arr[high] = new_arr[high], new_arr[low]
        return new_arr

    mid = int((low + high) / 2)
    merge_sort(new_arr, low, mid)
    merge_sort(new_arr, mid + 1, high)
    p1 = low
    p2 = mid + 1
    k = 0
    while p1 <= mid or p2 <= high:
        if p2 > high or (p1 <= mid and new_arr[p1] <= new_arr[p2]):
            new_arr[k] = arr[p1]
            p1 += 1
        else:
            new_arr[k] = arr[p2]
            p2 += 1
        k += 1
    return new_arr

# 桶排序
def bucket_sort(arr):
    bucket = [0] * 100
    new_arr = []
    for i in arr:
        bucket[i] = 1
    for j in range(len(bucket)):
        if bucket[j]:
            new_arr.append(j)
    return new_arr

if __name__ == "__main__":
    arr = [5, 3, 6, 2, 10]
    # 插入排序
    print(insert_sort(arr))
    # 冒泡排序
    print(bubble_sort(arr))
    # 归并排序
    print(merge_sort(arr, 0, len(arr) - 1))
    # 桶排序
    print(bubble_sort(arr))
