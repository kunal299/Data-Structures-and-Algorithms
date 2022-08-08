/*
    Time Complexity - O(1)
    Space Complexity - O(1)
*/

int findMinimumCoins(int amount) 
{
    vector<int> v{1, 2, 5, 10, 20, 50, 100, 500, 1000};
    
    int coins = 0;
    for(int i=8; i>=0 && amount>0; i--) {
        int store = floor((double)amount/(double)v[i]);
        coins += store;
        amount -= (v[i]*store);
    }

    return coins;
}
