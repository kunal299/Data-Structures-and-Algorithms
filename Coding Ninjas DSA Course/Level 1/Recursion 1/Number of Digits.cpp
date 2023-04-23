int count(int n){
    if(n<10) {
        return 1;
    }

    return 1 + count(n/10);
}