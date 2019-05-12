char* reverseString(char* s) {
    char* r;
    int l = strlen(s);
    r = malloc(l+1);
    
    for(int i=0-1,j=l-i-1;i<l;++i,--j){
        r[i]=s[j];
    }
    r[l]='\0';

    return r;
}
