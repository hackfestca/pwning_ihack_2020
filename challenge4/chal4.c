#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX 30

//gcc chal4.c -o chal4 -no-pie

void secret(){
	FILE* flagfile = NULL;
	char flag[MAX] = "";

	printf("Good job! This is your flag:\n");
	flagfile = fopen("flag4.txt", "r");
	fgets(flag,MAX,flagfile);
	puts(flag);
	fclose(flagfile);
}

void challenge(){
	char input[20] = {0};
	char pangolin[] = "pangolin";

	printf("What is your favorite food?\n");
	scanf("%s", input);

	if(strcmp(pangolin,input) == 0 ){
		printf("Hmm I think it is not a good idea to eat this!\n");
	}
	else{
		printf("eerrrrrkkk! How can you eat this?\n");
	}
}

int main()
{
	setvbuf(stdin, NULL, _IONBF, 0); //turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0); //turn off buffering

	challenge();
}
