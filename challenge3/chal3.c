#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MAX 30

//gcc chal3.c -o chal3 -no-pie
int main()
{

	setvbuf(stdin, NULL, _IONBF, 0); //turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0); //turn off buffering

	uint64_t password1 = 0;
	uint64_t password2 = 0;
	char* username[20] = {0};

	FILE* flagfile = NULL;
	char flag[MAX] = "";

	printf("What is your name?\n");
	scanf("%s", username);

	if( (password1 & password2) == 0xFACEDEEFFEEFCACA ){
		printf("This is your flag:\n");
		flagfile = fopen("flag3.txt", "r");
		fgets(flag,MAX,flagfile);
		printf("%s", flag);
		fclose(flagfile);
	}
	else{
		printf("You're not admin sorry!\n");
	}
}
