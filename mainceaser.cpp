#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int main()
{
	string text;
	char ctext[100],c,ed;
	int key,len,i,b,a;
	cout<<"Enter the message  :";
	getline(cin,text);
	cout<<"\n\nPress 'e' for Encrypting or 'd' for decrypting  :";
	cin>>ed;
	cout<<"\n\n";
	if(ed=='e')
	{
			 cout<<"What is the key to encrypt?\n";
			 cin>>key;
			 len=text.length();
			 for(i=0;i<len;i++)
			 {
			 	 c=text[i];
			 	 if(isspace(c))
			 		 b=32;
		 	 	 else if((text[i]>='a')&&(text[i]<='z'))
			 	 {
			 		 b=text[i];
			 		 a=b-97;
			 		 a=(a+key)%26;
			 		 b=a+97;
				 }
				 else
					b=text[i];
				 ctext[i]=b;
			 }
			 cout<<"The cipher text is  :";
			 for(i=0;i<len;i++)
		 		 cout<<ctext[i];
			 cout<<"\n\n";
	}
	else if(ed=='d')
	{
			 cout<<"What is the key to decrypt?\n";
			 cin>>key;
			 len=text.length();
			 for(i=0;i<len;i++)
			 {
				 c=text[i];
				 if(isspace(c))
					 b=32;
		 		 else if((text[i]>='a')&&(text[i]<='z'))
				 { 
					 b=text[i];
					 a=b-97;
					 a=(a-key)%26;
					 if(a<0)
						a+=26;
					 b=a+97;
				 }
				 else
				      b=text[i];
				 ctext[i]=b;
			 }
			 cout<<"The plain text is  :";
			 for(i=0;i<len;i++)
				 cout<<ctext[i];
			 cout<<"\n\n";
	}
	else
	{
		cout<<"INVALID INPUT.";
	}
	return 0;
}
