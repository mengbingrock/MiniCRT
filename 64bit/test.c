#include "minicrt.h"


int main(long argc,char *argv[])
{
	long i;
	FILE* fp;
	char** v = malloc(argc*sizeof(char*));
        printf("argc is %d\n",argc);
        printf("argv[0] is %s\n",argv[0]);
	for(i = 0; i < argc; ++i)
	{
	  v[i] = malloc(strlen(argv[i])+1);
	  strcpy(v[i],argv[i]);
	}

	fp = fopen("test.txt","w");
	for(i=0; i < argc; ++i){
	  long len = strlen(v[i]);
	  char* buf=malloc(sizeof(long));
	  printf("strlen of v[i] is %d\n",len);
	  itoa(len,buf,10);
	  fwrite(buf,1,sizeof(buf),fp);
	  fwrite(v[i] ,1,len,fp);
	  free(buf);
	}
	fclose(fp);
	fp = fopen("test.txt","r");
	for(i=0;i<argc;++i){
		char* len=malloc(sizeof(long));
		char* buff;
		fread(len, 1,sizeof(long),fp);
		buff = malloc(atoi(len)+1);
		fread(buff,1,atoi(len),fp);
		buff[atoi(len)]='\0';
		printf("len = %d, buf = %s \n",atoi(len),buff);
		free(buff);
		free(v[i]);
		free(len);
	}
	fclose(fp);
	return 0; 
}

