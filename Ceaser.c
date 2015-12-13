#include<stdio.h>
#include<string.h>
void main()
{
    char a[100];
    int g,b[100]={0},i,c,n;
    printf("Input string:");
   /* for(i=0;i<10;i++)
    {
        scanf("%c",&a[i]);
    }*/
    gets(a);
    n=strlen(a);
    printf("Input key:");
    scanf("%d",&g);
    for(i=0;i<n;i++)
    {  
        c=0;   
        b[i]=a[i];     
        if((b[i]>=65)&&(b[i]<=90))
        {
            c=b[i]-64;
            c+=g;
            b[i]=(c%26);
            if(b[i]==0)
            { 
              b[i]+=90;
            }
            else
	    {
                b[i]+=64;           
            }           
            printf("%c",b[i]);
        }
        else if((b[i]>=97)&&(b[i]<=122))
        {
            c=b[i]-96;
            c+=g;
            b[i]=(c%26); 
            if(b[i]==0)
            { 
              b[i]+=122;
            }
            else
	    {
                b[i]+=96;           
            }
            printf("%c",b[i]);
        }      
    }
    printf("\n");
}
