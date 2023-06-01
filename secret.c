#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





int ascii,mascii;
int main()
{
	char key1,key2,pass[100],test[100],encryp[100];
	int ascii,mascii,i,j;
	gets(pass);
	puts(pass);
	strcpy(test,pass);
	for(i=0;test[i]!='\0';i++)
	{
		key1=rand1(0,13);
		key2=rand2(0,16);
		if(test[i]>='A' && test[i]<='Z')
		{
			strcpy((char*)test[i],encryptcalpha(test[i],key1));
		}
		else if(test[i]>='a' && test[i]<='z')
		{
			strcpy((char*)test[i],encryptsalpha(test[i],key1));	}
		else
		{
			strcpy((char*)test[i],encryptsym_num(test[i],key2));
		}
	}
	strcpy(encryp,test);
	puts(encryp);
}
int rand1(int lower,int upper)
{
	int i,num;
	for(i=0;i<1;i++)
	{
		 num=(rand()%(upper-lower))+lower;
	}
	return num;
}
int rand2(int lower,int upper)
{
	int i,num;
	for(i=0;i<1;i++)
	{
		int num=(rand()%(upper-lower))+lower;
	}
	return num;
}
char* encryptcalpha(char ch,int key)
{
	mascii=ch;
	ascii=mascii+key;
	if(ascii>90)
	{
		ascii=ascii-13;
	}
	ch=ascii;
	char ch1=ch;
	return (char*)ch1;
}
char* encryptsalpha(char ch,int key)
{
	mascii=ch;
	ascii=mascii+key;
	if(ascii>122)
	{
		ascii=ascii-13;
	}
	ch=ascii;
	char ch1=ch;
	return (char*) ch1;
}
char* encryptsym_num(char ch,int key)
{
	mascii=ch;
	if(mascii>=33 && mascii<=64)
	{
		ascii=mascii+key;
		if(ascii>64)
		{
			ascii=33+(ascii-mascii);
		}
		ch=ascii;
	}
	char ch1=ch;
	return (char*)ch1;
}