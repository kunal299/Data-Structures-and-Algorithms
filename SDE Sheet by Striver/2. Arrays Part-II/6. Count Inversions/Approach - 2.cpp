/*
    Time Complexity - O(nlogn)
    Space Complexity - O(n)

*/

#include <bits/stdc++.h> 

long long merge(long long *arr, long long *tmp, int left, int mid, int right) {
    int i=left, j=mid, k=left;
    long long inv_cnt = 0;
    
    while((i<mid) && (j<=right)) {
        if(arr[i]>arr[j]) {
            tmp[k++] = arr[j++];
            inv_cnt += (mid-i);
        } else {
            tmp[k++] = arr[i++];
        }
    }
    
    while(i<mid) {
        tmp[k++] = arr[i++];
    }
    
    while(j<=right) {
        tmp[k++] = arr[j++];
    }
    
    for(i=left; i<=right; i++) {
        arr[i] = tmp[i];
    }
    
    return inv_cnt;
}

long long mergeSort(long long *arr, long long *tmp, int left, int right) {
    long long inv_cnt = 0;
    if(right>left) {
        int mid = (left+right)/2;
        inv_cnt += mergeSort(arr, tmp, left, mid);
        inv_cnt += mergeSort(arr, tmp, mid+1, right);
        inv_cnt += merge(arr, tmp, left, mid+1, right);
    }
    
    return inv_cnt;
}

long long getInversions(long long *arr, int n){
    
    long long tmp[n];
    return mergeSort(arr, tmp, 0, n-1);
}