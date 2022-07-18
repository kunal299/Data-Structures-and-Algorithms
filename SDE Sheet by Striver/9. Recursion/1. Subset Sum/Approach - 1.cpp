/*
    Time Complexity - O(2^n) + O((2^n)log(2^n))
    Space Complexity - O(2^n)
*/

void helper(int idx, int sum, vector<int> &num, int N, vector<int> &res) {
    if(idx > N-1) {
        res.push_back(sum);
        return;
    }
    
    helper(idx+1, sum+num[idx], num, N, res);
    helper(idx+1, sum, num, N, res);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> res;
    helper(0, 0, num, num.size(), res);
    sort(res.begin(), res.end());
    
    return res;
}