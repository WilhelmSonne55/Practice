char* reverseString(char* s) {
    int l=strlen(s);
    char* r = malloc(l+1);
    r[l]='\0';

    int i=0;
    while(--l>=0){
        r[l] = s[i++];
    }


    return r;
}
