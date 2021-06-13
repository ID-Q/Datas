#!/usr/bin/env python
# coding=utf-8

# 1 2 3 4 5 6
def binary_search1(arr, x):
    head = 0
    tail = len(arr)
    while head <= tail:
        mid = int((head + tail) / 2)
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            tail = mid - 1
        else:
            head = mid + 1
    return -1

# 111111000000
def binary_search2(arr):
    head = -1
    tail = len(arr) - 1
    while head < tail:
        mid = int((head + tail + 1) / 2)
        if arr[mid] == 1:
            head = mid
        else:
            tail = mid - 1
    return head

# 00000111111
def binary_search3(arr):
    head = 0
    tail = len(arr)
    while head < tail:
        mid = int((head + tail) / 2)
        if arr[mid] == 1:
            tail = mid
        else:
            head = mid + 1
    if head == len(arr):
        return -1
    else:
        return head

if __name__ == "__main__":
    arr1 = [1, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    arr2 = [1, 1, 1, 0, 0, 0, 0, 0, 0, 0]
    arr3 = [0, 0, 0, 0, 0, 0, 1, 1, 1, 1]
    print(binary_search1(arr1, 13))
    print(binary_search2(arr2))
    print(binary_search3(arr3))
