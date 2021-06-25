#include <stdio.h>
#include <string.h>

static char * sub_str(char* src, char* dest, int s_idx, int edix)
{
    int cntr, destLen;
    if (s_idx = 0) 
        destLen = edix - s_idx - 1;
    else
        destLen = edix - s_idx;
    for(cntr = 0; cntr < destLen; cntr++)
	{
		dest[cntr] = src[s_idx++];
    }
    dest[cntr] = '\0';
    return dest;
}

int main(){
    char inputStr[100], destStr[100];
    int s_idx, edix, instrLen;
	printf("Enter a String \n");
    gets(inputStr);
    printf("Enter starting index and ending index \n");
	instrLen = strlen(inputStr);
    scanf("%d %d", &s_idx, &edix);
	if(s_idx < 0 || s_idx > strlen(inputStr) || edix > strlen(inputStr))
	{
		printf("Invalid Input");
    }
	else
	{
		//*destStr = sub_str(inputStr, destStr, s_idx, edix);
        //printf("%d",strlen(destStr));
		//printf("Extracted string is : %s \n", destStr);
        printf("Extracted string is : %s \n", sub_str(inputStr, destStr, s_idx, edix));
	}
    return 0;
}
 

