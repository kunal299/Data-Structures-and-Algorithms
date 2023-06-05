int len(char input[]) {
    int size = 0;
    for(int i=0; input[i]!='\0'; i++) {
        size++;
    }
    
    return size;
}

int pow(int n) {
    if(n==0) {
        return 1;
    }

    return 10 * pow(n-1);
}

int stringToNumber(char input[]) {
    if(len(input)==0) {
        return 0;
    } 
    
    int a = stringToNumber(input+1);
    int b = input[0]-'0';
    
    return b*pow(len(input)-1) + a;
}