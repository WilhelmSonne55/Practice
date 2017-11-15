char* reverseString(char* s) {
    char* r;
    int l=0;
    while(*s){
     s++;
     ++l;         
    }
    r=malloc(l*sizeof(char)+1); //for '\0'
    memset(r,0,l);
    
    int i=0;
    while(i<l){
        *(r + i) = *--s;
        ++i;
    }
    *(r+i)='\0';
    
    return r;
}
