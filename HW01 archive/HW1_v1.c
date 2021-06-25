#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//static inline char * sub_str(char * dest, char *src, int s_idx, int edix){
  char *sub_str( char *src, int s_idx, int eidx )
{
    char *pstr = src+s_idx;
    char *substr = NULL;
    int index;
      
          
    if( s_idx <0 || eidx >= strlen( src ) )
    {
        printf("Input error\n");
        return NULL;
    }
    substr = (char *) malloc ( (eidx - s_idx + 2) * sizeof( char ) );
    if(!substr)
    {
        perror("sub_str():allocate memeory failed!");
        return NULL;
    }
          
    for( index =0; index <= eidx -s_idx; index ++)
    substr[ index ] = pstr[ index ];
      
    substr[index] = '\n';
    index++;
    substr[index] = '\0';     
      
     return substr;
}

/*static inline char * asm_sub_str(char * dest, char *src, int s_idx, int edix){
    
    return dest;
}*/


int main(int argc,char **argv)
{
    char *resstr = NULL;
    char src[30];
    int sidx, edx;
    printf("Enter your string: ");
    gets(src);
    printf("Enter starting and ending index: ");
    scanf("%d%d", &sidx,&edx);
    resstr = sub_str(src,sidx,edx);
    printf("%s",resstr);
    return 0;
}