void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n==0) {
        return;
    }
    
    if(n==1) {
        cout<<source<<" "<<destination<<"\n";
        return;
    }
    
    towerOfHanoi(n-1, source, destination, auxiliary);
    cout<<source<<" "<<destination<<"\n";
    towerOfHanoi(n-1, auxiliary, source, destination);

}