#include "minicrt.h"


int main(long argc,char *argv[])
{
	long i;
	FILE* fp;

	fp	= fopen("test.txt","w");
	
	//
	{
	  char* buf = "hello how are you \n";
	  long len = strlen(buf);
	  fwrite(buf ,1,len,fp);
	  write(0,"c",1);
	  write(0,"\n",1);
	  printf("hello world\n");
	  printf("len = %d, buff =  %s\n",len,buf);
	}
	
	fclose(fp);

	return 0; 
}

