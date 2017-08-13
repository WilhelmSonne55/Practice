#include <stddef.h>


char *find_needle(const char **haystack, size_t count){
  int i=0;
  char c[]="found the needle at position";
  char* answer = malloc(sizeof(c)+1);
  
  while(i != count){
     if(strcmp(haystack[i],"needle") == 0) break;
	++i;
  }

  sprintf(answer,"%s %d",c,i);
  return answer;
}
