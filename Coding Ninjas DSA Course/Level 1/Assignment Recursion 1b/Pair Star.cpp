int len(char input[]) {
    int size = 0;
    for(int i=0; input[i]!='\0'; i++) {
        size++;
    }
    
    return size;
}

void pairStar(char input[]) {
    if(len(input)<2 || input[1]=='\0') {
        return;
    }
    
    if(input[0]==input[1]) {
        input[len(input)+1] = '\0';
        for(int i=len(input); i>=2; i--) {
            input[i] = input[i-1];
        }
        input[1] = '*';
    } 
        
    pairStar(input+1);
    
}