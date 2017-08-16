int cmpstr(void const * a, void const * b){
    char const *aa = *(char const**)a;
    char const *bb = *(char const**)b;

    return strcmp(aa,bb);
}

char **inArray(char *array1[], int sz1, char *array2[], int sz2, int *lg)
{
    *lg = 0; //initialize
    int rows = sz1;
    char **r;                          //return array of char
    r = malloc(rows * sizeof(char *)); //allocate the possible rows(max: sz1)

    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            if (strlen(array1[i]) > strlen(array2[j]) > 0) continue;

            int cs1 = strlen(array1[i]);
            int cs2 = strlen(array2[j]);
            char *a1 = *(array1 + i);
            char *a2 = *(array2 + j);
            char *tmp = malloc( (cs1+1) * sizeof(char)); //substring of a2 used to compare with the a1
            int k = 0;

            while (cs1 + k <= cs2)
            {
                memcpy(tmp, a2 + k, cs1);    //move the a2's position and copy to tmp
                tmp[cs1]='\0';

                if (strcmp(tmp, a1) == 0)
                {
                    int q=0;
                    while(q < *lg){        //in case duplicate
                        if(strcmp(tmp,*(r+q) )==0) break;
                        ++q;
                    }
                    
                    if(q != *lg) break;     //find the duplicate

                    int lsize = (*lg)++;
                    *(r + lsize) = malloc(sizeof(tmp));
                    strcpy(*(r + lsize), tmp);
                }

                ++k;
            }

            free(tmp);
        }
    }

    //qsort
    qsort(r,*lg,sizeof(char*),cmpstr);
    return r;
}
