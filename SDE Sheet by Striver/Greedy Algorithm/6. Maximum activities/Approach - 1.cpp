/*
    Time Complexity - O(n) + O(nlogn) + O(n) ~ O(nlogn)
    Space Complexity - O(n)
*/

#include <bits/stdc++.h>

struct activity {
    int start;
    int finish;
    int pos;
};

bool comparator(struct activity a1, struct activity a2) {
    if(a1.finish < a2.finish) {
        return true;
    } else if(a1.finish > a2.finish) {
        return false;
    } else if(a1.pos < a2.pos) {
        return true;
    }
    
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    
    int n = start.size();
    struct activity a[n];
    
    for(int i=0; i<n; i++) {
        a[i].start = start[i];
        a[i].finish = finish[i];
        a[i].pos = i+1;
    }
    
    sort(a, a+n, comparator);
        
    int finishTime = a[0].finish;
    
    vector<int> res;
    res.push_back(a[0].pos);
    
    for(int i=1; i<n; i++) {
        if(a[i].start >= finishTime) {
            finishTime = a[i].finish;
            res.push_back(a[i].pos);
        }
    }
    
    return res.size();
    
}