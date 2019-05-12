int titleToNumber(char* s) {
    int size = strlen(s);
    int sum =0;
    
    if(size>0){
        for(int i=0;i<size;++i){
            int add = s[i]%64;
            int carry = add * pow(26,size-i-1);
            sum += carry ;
        }
    }
    
    return sum;

}
