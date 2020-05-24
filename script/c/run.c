/*
#include <string.h>
#include<stdio.h>

void main(){
  char sttr[10];
  char *hi = "hello";
	memcpy(sttr,hi,strlen(hi)+1);
	printf("%s,%s\n",hi,sttr);

}
*/
#include <stdio.h>
 
int main(){
	FILE *fp = NULL;
  fp = fopen("./test.txt", "w+");
  fprintf(fp, "This is testing for fprintf...\n");
  fputs("This is testing for fputs...\n", fp);
	fputc('s',fp);
	fclose(fp);
}
