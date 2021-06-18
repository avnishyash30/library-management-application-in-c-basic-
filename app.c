#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct books
{int an;char bn[20],ath[20],pub[20];float price;int
year,no,flag;}book;
typedef struct members
{int id;char name[20],add[30];int issued;}mem;
typedef struct history
{int an,id;char name[20];int days;char take[12],ret[12];float
sum;}his;
book b[100];
mem men[100];
his h[100];
FILE *fp1,*fp2,*fp3;
void dispbook();
void addbook();
void dispauth();
void disptitle();
void total();
void dispmembers();
void issue();
void rec();
float dues(int d);
void memberbook();
void addmember();
int main()
{
printf("**Fullscreen the window for better viewing**\n");
printf("**Private Library Management Application version
1.0**\n\n");
int d,a,i=0;float s;
for(;a!=0;i++)
{ printf("\nEnter Operation no. you want to perform:\n");
printf("1) Display the book information\n2) Add a new book\n3)
Display all the books in the library of a particular author\n4)
Display the number of books of a particular title\n");
printf("5) Display the total number of books in the
library\n6) Display details of library members\n7) Issue a book\n8)
Return a book\n9) Total dues to be paid by a member\n");
printf("10) Display details of member whom a particular book
issued\n11) Add Members\n0) Exit\n");
printf("Operation no.:");scanf("%d",&a);
switch(a)
{
case 1:dispbook();break;
case 2:addbook();break;
case 3:dispauth();break;
case 4:disptitle();break;
case 5:total();break;break;
case 6:dispmembers();break;
case 7:issue();break;
case 8:rec();break;
case 9:printf("Enter No. of Days:");scanf("%d",&d);
s=dues(d);printf("Total
Dues:%.2f\n\n",s);break;
case 10:memberbook();break;
case 11:addmember();break;
case 0:printf("Program Exited");break;
default:printf("Error in input");
}
}
return 0;
}
void dispbook()
{
int i,k;
fp1=fopen("f1.dat","rb");
if ( fp1== NULL)
{ printf("Error opening file f1");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&b[i],sizeof(book),1,fp1);
}
printf("enter Accession No.:");scanf("%d",&k);
for(i=0;i<100;i++)
{ if (b[i].an==k)
 {
 printf("Accession Number:%-10d Book Name:%-23s Author:%-23s
Publisher:%-23s Price:%-10.2f Year:%-6d Total Copies:%-4d
Available:%-4d\n",b[i].an,b[i].bn,b[i].ath,b[i].pub,b[i].price,b[i].ye
ar,b[i].no,b[i].flag);
 }
 }
 fclose(fp1);
 printf("\n******************\n\n");
}
void addbook()
{
int i,k,n,l;
fp1=fopen("f1.dat","r+b");
if ( fp1== NULL)
{ printf("Error opening file f1");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&b[i],sizeof(book),1,fp1);
}
for(i=0;i<100;i++)
{
if(b[i].an==0)
{k=i;break;}
}
printf("How many books do u want to add?\n");
scanf("%d",&n);
l=k+n;
for(k=i;k<l;k++)
{
printf("Book will be added on index no %d\n",k);
printf("Enter Accession no,Book
Name,Author,Publisher,Price,Year,Total Copies:\n");
scanf("%d",&b[k].an);getchar();
scanf("%[^\n]s",b[k].bn);getchar();
scanf("%[^\n]s",b[k].ath);getchar();
scanf("%[^\n]s",b[k].pub);
scanf("%f",&b[k].price);
scanf("%d",&b[k].year);
scanf("%d",&b[k].no);
b[k].flag=b[k].no;
}
printf("Books written successsfully\n");
fseek(fp1, 0, SEEK_SET);
for(i=0;i<100;i++)
{fwrite (&b[i],sizeof(book),1,fp1); }
printf("Books updated successsfully\n");
fclose(fp1);
printf("\n******************\n\n");
}
void dispauth()
{
int i,j,k,m,n,len,times;char s2[20],s1[20];
fp1=fopen("f1.dat","rb");
if ( fp1== NULL)
{ printf("Error opening file f1");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&b[i],sizeof(book),1,fp1);
}
for(i=0;i<100;i++)
{
if(b[i].an==0)
{k=i;break;}
}
printf("enter author name:");getchar();
scanf("%[^\n]s",s2);
len=strlen(s2);
for(i=0;i<k;i++)
{
m=0;n=0,times=0;
for(j=0;j<20;j++)
s1[j]=b[i].ath[j];
while(s1[n] != '\0')
{
 if(s1[n] == s2[m])
 {
 while(s1[n] == s2[m] && s1[n] !='\0')
 {
 n++;
 m++;
 }
 if(m == len && (s1[n] == ' ' || s1[n] == '\0'))
 {
 times=1;
 break;
 }
 }
 else
 {
 while(s1[n] != ' ')
 {
 n++;
 if(s1[n] == '\0')
 break;
 }
 }
 n++;
 m=0;
 }
 if(times ==1)
 {
 printf("Accession Number:%-10d Book Name:%-23s Author:%-23s
Publisher:%-23s Price:%-10.2f Year:%-6d Total Copies:%-4d
Available:%-4d\n",b[i].an,b[i].bn,b[i].ath,b[i].pub,b[i].price,b[i].ye
ar,b[i].no,b[i].flag);
 }
 }
 fclose(fp1);
 printf("\n******************\n\n");
}
void disptitle()
{
int i,j,k,m,n,len,times;char s2[20],s1[20];
fp1=fopen("f1.dat","rb");
if ( fp1== NULL)
{ printf("Error opening file f1");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&b[i],sizeof(book),1,fp1);
}
for(i=0;i<100;i++)
{
if(b[i].an==0)
{k=i;break;}
}
printf("enter book name:");getchar();scanf("%[^\n]s",s2);
len=strlen(s2);
for(i=0;i<k;i++)
{
m=0,n=0,times=0;
for(j=0;j<20;j++)
s1[j]=b[i].bn[j];
while(s1[n] != '\0')
{
 if(s1[n] == s2[m])
 {
 while(s1[n] == s2[m] && s1[n] !='\0') 
 {
 n++;
 m++;
 }
 if(m == len && (s1[n] == ' ' || s1[n] == '\0'))
 {
 times=1;
 break;
 }
 }
 else
 {
 while(s1[n] != ' ')
 {
 n++;
 if(s1[n] == '\0')
 break;
 }
 }
 n++;
 }
 if(times ==1)
 {
 printf("Accession Number:%-10d Book Name:%-23s Author:%-23s
Publisher:%-23s Price:%-10.2f Year:%-6d Total Copies:%-4d
Available:%-4d\n",b[i].an,b[i].bn,b[i].ath,b[i].pub,b[i].price,b[i].ye
ar,b[i].no,b[i].flag);
 }
 }
 fclose(fp1);
}
void total()
{
int i;
fp1=fopen("f1.dat","rb");
if ( fp1== NULL)
{ printf("Error opening file f1");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&b[i],sizeof(book),1,fp1);
}
printf("\n\n\nTotal Book Details:\n");
printf("______________________________________________________
______________________________________________________________________
______________________________\n");
printf("Acession No\tBook
Name\t\t\tAuthor\t\t\tPublisher\t\t\t Price\t Year\ttotal
copies\tavailable\n");
printf("______________________________________________________
______________________________________________________________________
______________________________\n");
for(i=0;i<100;i++)
{
if(b[i].year==0) break;
printf("%-14d %-27s %-25s %-29s \t%10.2f\t %-6d\t
%4d\t\t
%4d\n",b[i].an,b[i].bn,b[i].ath,b[i].pub,b[i].price,b[i].year,b[i].no,
b[i].flag);
}
fclose(fp1);
printf("\n******************\n\n");
}
void dispmembers()
{
int i;
fp2=fopen("f2.dat","rb");
if ( fp2== NULL)
{ printf("Error opening file f2");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&men[i],sizeof(mem),1,fp2);
}
printf("\n\n\nTotal Member Details:\n");
printf("______________________________________________________
__________________________________________\n");
printf("id\t\tMember Name\t\t\tAddress\t\t\tNo.of books
issued\n");
printf("______________________________________________________
__________________________________________\n");
for(i=0;i<100;i++)
{
if(men[i].id==0) break;
printf("%-14d %-27s %-25s
%8d\n",men[i].id,men[i].name,men[i].add,men[i].issued);
}
fclose(fp2);
printf("\n******************\n\n");
}
void issue()
{
int i,p,q,k,l,w;char s1[12],s2[12];
fp1=fopen("f1.dat","r+b");
if ( fp1== NULL)
{ printf("Error opening file f1");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&b[i],sizeof(book),1,fp1);
}
fp2=fopen("f2.dat","r+b");
if ( fp2== NULL)
{ printf("Error opening file f2");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&men[i],sizeof(mem),1,fp2);
}
fp3=fopen("f3.dat","r+b");
if ( fp3== NULL)
{ printf("Error opening file f3");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&h[i],sizeof(his),1,fp3);
}
printf("Enter Accession No.:");scanf("%d",&p);
for(i=0;i<100;i++)
{
if(p==b[i].an)
{printf("match found-%s\nauthor:%s\ncopies avaliable-
%d\n",b[i].bn,b[i].ath,b[i].flag);k=i;break;}
}
printf("Enter ID:");scanf("%d",&q);
for(i=0;i<100;i++)
{
if(q==men[i].id)
{printf("match found-%s\n\n",men[i].name);l=i;break;}
}
printf("borrow date:");getchar();scanf("%
[^\n]s",s1);getchar();
printf("return date:");scanf("%[^\n]s",s2);
--b[k].flag;
++men[l].issued;
for(i=0;i<100;i++)
{
if(h[i].an==0)
{w=i;break;}
}
h[w].an=b[k].an;
h[w].id=men[l].id;
for(i=0;i<20;i++)
{h[w].name[i]=men[l].name[i];}
for(i=0;i<12;i++)
{h[w].take[i]=s1[i];}
for(i=0;i<12;i++)
{h[w].ret[i]=s2[i];}
printf("Book Issued Successfully\n");
fseek(fp1, 0, SEEK_SET);
for(i=0;i<100;i++)
{
fwrite(&b[i],sizeof(book),1,fp1);
}
fclose(fp1);
fseek(fp2, 0, SEEK_SET);
for(i=0;i<100;i++)
{
fwrite(&men[i],sizeof(mem),1,fp2);
}
fclose(fp2);
fseek(fp3, 0, SEEK_SET);
for(i=0;i<100;i++)
{
fwrite(&h[i],sizeof(his),1,fp3);
}
fclose(fp3);
printf("\n******************\n\n");
}
void rec()
{
int i,p,q,k,l,w,d;
fp1=fopen("f1.dat","r+b");
if ( fp1== NULL)
{ printf("Error opening file f1");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&b[i],sizeof(book),1,fp1);
}
fp2=fopen("f2.dat","r+b");
if ( fp2== NULL)
{ printf("Error opening file f2");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&men[i],sizeof(mem),1,fp2);
}
fp3=fopen("f3.dat","r+b");
if ( fp3== NULL)
{ printf("Error opening file f3");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&h[i],sizeof(his),1,fp3);
}
printf("Enter ID:");scanf("%d",&q);
for(i=0;i<100;i++)
{
if((q==h[i].id)&&(h[i].sum==0))
{printf("match found-%s\naccession
no:%d\n",h[i].name,h[i].an);l=i;break;}
}
for(i=0;i<100;i++)
{
if(h[l].an==b[i].an)
{k=i;break;}
}
for(i=0;i<100;i++)
{
if(h[l].id==men[i].id)
{w=i;break;}
}
++b[k].flag;
--men[w].issued;
printf("borrow date:%s\n",h[l].take);
printf("return date:%s\n",h[l].ret);
printf("extra no of days:");scanf("%d",&p);
if(p!=0)
{getchar();printf("new return date:");scanf("%
[^\n]s",h[l].ret);}
printf("total days:");scanf("%d",&d);
h[l].days=d;
h[l].sum=dues(d);
printf("Dues:%.2f\n",h[l].sum);
printf("Book Returned Successfully\n");
fseek(fp1, 0, SEEK_SET);
for(i=0;i<100;i++)
{
fwrite(&b[i],sizeof(book),1,fp1);
}
fclose(fp1);
fseek(fp2, 0, SEEK_SET);
for(i=0;i<100;i++)
{
fwrite(&men[i],sizeof(mem),1,fp2);
}
fclose(fp2);
fseek(fp3, 0, SEEK_SET);
for(i=0;i<100;i++)
{
fwrite(&h[i],sizeof(his),1,fp3);
}
fclose(fp3);
printf("\n******************\n\n");
}
float dues(int d)
{
float k;
k=1.50*d;
return (k);
}
void memberbook()
{
int i,t;
fp3=fopen("f3.dat","rb");
if ( fp3== NULL)
{ printf("Error opening file f3");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&h[i],sizeof(his),1,fp3);
}
printf("enter accession no:");scanf("%d",&t);
printf("\n____________________________________________________
______________________________________________________________________
______\n");
printf("Accession No\tID\t\tName\t\t days\t taken\t
return\t sum\n");
printf("______________________________________________________
______________________________________________________________________
____\n");
for(i=0;i<100;i++)
{
if(h[i].an==t)
{
printf("%-14d %-10d %-27s %6d %15s %15s\t
%10.2f\n",h[i].an,h[i].id,h[i].name,h[i].days,h[i].take,h[i].ret,h[i].
sum);
}
if(h[i].id==0)break;
}
fclose(fp3);
printf("\n******************\n\n");
}
void addmember()
{
int i,k,n,l;
fp2=fopen("f2.dat","r+b");
if ( fp2== NULL)
{ printf("Error opening file f2");
exit(-1) ;
}
for(i=0;i<100;i++)
{
fread(&men[i],sizeof(mem),1,fp2);
}
for(i=0;i<100;i++)
{
if(men[i].id==0)
{k=i;break;}
}
printf("How many members do u want to add?\n");
scanf("%d",&n);
l=k+n;
for(k=i;k<l;k++)
{
printf("Member will be added on index no %d\n",k);
printf("Enter id,name,address:\n");
scanf("%d",&men[k].id);getchar();
scanf("%[^\n]s",men[k].name);getchar();
scanf("%[^\n]s",men[k].add);
men[k].issued=0;
}
printf("Members written successsfully\n");
fseek(fp2, 0, SEEK_SET);
for(i=0;i<100;i++)
{fwrite (&men[i],sizeof(mem),1,fp2); }
printf("Members updated successsfully\n");
fclose(fp2);
printf("\n******************\n\n");
}
