#include<stdio.h>
#include<stdlib.h>

int main()
{
	char buf[20] = "hello world!";
	
	int size = sizeof(buf);
	
	int len = strlen(buf);
	
	printf("%d\n%d",size,len);
	
	return 0;
	
	
 } 
