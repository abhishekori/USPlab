// VTUCS

/* Write a C program to implement the syntax-directed definition of �if
E then S1� and �if E then S1 else S2�. */

#include<stdio.h>

#include<stdlib.h>


#include<string.h>

int parsecondition(char [],int,char *,int);

void gen(char [],char [], char [],int);


int main()

{

int co=0,stlen=0,elseflag=0;

char stmt[60];

char strB[54];

char strs1[50];
char strs2[45];

printf("format of 'if' statement\nExample\n");

printf("if(a<b) then (s=a);\n");

printf("if(a<b) then (s=a) else (s=b)\n");

printf("Enter the statement\n");

gets(stmt);

stlen=strlen(stmt);

co=co+2;

co=parsecondition(stmt,co,strB,stlen);

if(stmt[co]==')')

co++;

co=co+3;

co=parsecondition(stmt,co,strs1,stlen);


if(stmt[co+1]==';')

{
printf("\n hi");

printf("\nParsing the input statement...");

gen(strB,strs1,strs2,elseflag);

return 0;

}

if(stmt[co]==')')

co++;

co+=3;

co=parsecondition(stmt,co,strs2,stlen);
	co+=2;
if(co==stlen)

{

elseflag=1;

printf("\n Parsing the input statement....");
gen(strB,strs1,strs2,elseflag);

return 0;

}

}



int parsecondition(char input[],int cntr,char * dest,int totallen)

{

int index=0,pos=0;

while(input[cntr]!='('&&cntr<=totallen)

cntr++;
	if(cntr>=totallen)

return 0;

index=cntr;

while(input[cntr]!=')')
cntr++;
	if(cntr>=totallen)
return 0;

while(index<=cntr)

dest[pos++]=input[index++];

dest[pos]='\0';
	return cntr;

}


void gen(char B[],char s1[],char s2[],int elsepart)

{

int bt=101,bf=102,sn=103;

printf("\n if%s goto %d",B,bt);

printf("\n goto %d",bf);
printf("\n %d:%s",bt,s1);

//printf("%s",s1);

if(!elsepart)

printf("\n%d:",bf);

else

{

printf("\ngoto %d",sn);

printf("\n %d:%s",bf,s2);

printf("\n %d:",sn);
}

}
