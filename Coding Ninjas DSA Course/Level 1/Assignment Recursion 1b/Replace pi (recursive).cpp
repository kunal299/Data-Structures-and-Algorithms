int len(char input[]) {
    int size = 0;
    for(int i=0; input[i]!='\0'; i++) {
        size++;
    }
    
    return size;
} 

void helper(char input[], int s) {
    if(input[s]=='\0' || input[s+1]=='\0') {
        return;
    }
    
    helper(input, s+1);
    
    if(input[s]=='p' && input[s+1]=='i') {
        for(int i=len(input); i>=s+2; i--) {
            input[i+2] = input[i];
        }
        
        input[s] = '3';
        input[s+1] = '.';
        input[s+2] = '1';
        input[s+3] = '4';
    }
}

void replacePi(char input[]) {
	
    helper(input,0);

}