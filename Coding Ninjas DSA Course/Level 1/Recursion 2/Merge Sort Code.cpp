void merge(int input[], int si, int ei) {
    int mid = (si+ei)/2;
    int arr[1001];
    int i=si, j=mid+1, k=si;
    
    while(i<=mid && j<=ei) {
        if(input[i]<input[j]) {
            arr[k] = input[i];
            i++;
        } else {
            arr[k] = input[j];
            j++;
        }
        k++;
    }
    
    while(i<=mid) {
        arr[k] = input[i];
        i++;
        k++;
    }
    
    while(j<=ei) {
        arr[k] = input[j];
        j++;
        k++;
    }
    
    for(int i=si; i<=ei; i++) {
        input[i] = arr[i];
    }
}

void mergeSortHelper(int input[], int si, int ei) {
    if(si>=ei) {
        return;
    }
    
    int mid = (si+ei)/2;
    
    mergeSortHelper(input, si, mid);
    mergeSortHelper(input, mid+1, ei);
    
    merge(input, si, ei);
}

void mergeSort(int input[], int size){
	mergeSortHelper(input, 0, size-1);
        
}
