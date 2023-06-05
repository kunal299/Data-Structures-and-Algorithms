int len(char input[]) {
    int size = 0;
    for(int i=0; input[i]!='\0'; i++) {
        size++;
    }
    
    return size;
}

void removeX(char input[]) {
    if(input[0]=='\0') {
        return;
    }
    
    if(input[0]!='x') {
        removeX(input+1);
    } else {
        for(int i=0; i<len(input); i++) {
            input[i] = input[i+1];
        }
        removeX(input);
    }
    

}
