#include<iostream>
#include<string>

using namespace std;

int main()
{
	string text;
	char ctext[100],c;
	int key,len,i,b,a;
	cout<<"Enter the message  :";
	getline(cin,text);
	len=text.length();
	cout<<"\n\nThe possibilities are shown below.\n\n";
	for(key=0;key<26;key++)
	{
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
		cout<<key+1<<" :";
		for(i=0;i<len;i++)
			cout<<ctext[i];
		cout<<"\n\n";
	}
	return 0;
}
