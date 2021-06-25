#include <stdio.h>
#include <string.h>

static inline char * sub_str(char* src, char* dest, int s_idx, int edix)
{
    int cntr, destLen = edix - s_idx + 1;
    for(cntr = 0; cntr < destLen; cntr++)
	{
		dest[cntr] = src[s_idx++];
	}
    dest[cntr] = '\0';
    return dest;
}

static inline char * asm_sub_str(char *src, char *dest, int s_idx, int edix)
{
	int cntr = edix - s_idx + 1;
	__asm__ __volatile__("cld\n"
                         "rep\n"
                         "movsb\n"
                         "xor %%al,%%al\n"
                         "stosb\n"
                         :
                         :"S"(src + s_idx), "D"(dest), "c"(cntr)
						 : "memory"
                         );
	return dest;
}

int main(){
    char inputStr[100], destStr[100];
    int s_idx, edix, compare;
	printf("Enter a String \n");
    gets(inputStr);
    printf("Enter starting index and ending index \n");
    scanf("%d %d", &s_idx, &edix);
	if(s_idx < 0 || s_idx > strlen(inputStr) || edix > strlen(inputStr))
	{
		printf("Invalid Input");
    }
	else
	{
	printf("Extracted string is : %s \n", sub_str(inputStr, destStr, s_idx, edix));
	printf("Extracted string is (asm): %s \n", asm_sub_str(inputStr, destStr, s_idx, edix));	
	}
	compare = strcmp (sub_str(inputStr, destStr, s_idx, edix), asm_sub_str(inputStr, destStr, s_idx, edix));
	if(compare == 0)
		printf("\nThe 2 strings are same\n");
	else
		printf("\nThe 2 strings are not the same\n");
    return 0;
}
 