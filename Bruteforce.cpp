/* Brute force algorithm */
#include<string.h>
#include<iostream>
using namespace std;
class PatternMatcher
{
	public:
			int bruteforce(char text[40], char pattern[10]);
};

int PatternMatcher :: bruteforce(char text[40], char pattern[10])
{
	int m,n,i,j;
	n = strlen(text);
	m = strlen(pattern);
	
	for(i=0;i<n-m;i++)	
	{
		for(j=0;j<m;j++)
		{
			if(text[i+j]!=pattern[j])
				break;
		}
		
		if(j==m)
			return i;
	}
	return -1;
}

int main()
{
	char text[40], pat[10];
	PatternMatcher obj;
	
	cout<<"Enter main text:";
	cin>>text;
	
	cout<<"Enter pattern/substring:";
	cin>>pat; 
	
	int pos = obj.bruteforce(text,pat);
	
	if(pos==-1)
		cout<<"Sorry... No such pattern found";
	else
		cout<<"Pattern found at "<<pos<<" in the main string...";
		
	return 0;
}

