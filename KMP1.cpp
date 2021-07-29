#include<iostream>
using namespace std;
// Calculating the failure function & place it in the prefix & suffix table
void findPrefix(char pattern[40], int m, int prefArray[40]) 
{
   int length = 0;
   prefArray[0] = 0;     
   for(int i = 1; i<m; i++) 
   {
      if(pattern[i] == pattern[length]) 
	  {
         length++;
         prefArray[i] = length;    
      }
	  else {
         if(length != 0) 
		 {
            length = prefArray[length - 1];
            i--;     
         }
		 else
            prefArray[i] = 0;
      }
   }
}

void kmp(char mainString[40], char pattern[20]) {
   int n, m, i = 0, j = 0;
   
   for(n=0;mainString[n]!='\0';n++); // to find length of mainstring
   for(m=0;pattern[m]!='\0';m++); // to find the length of the pattern
   
   int prefixArray[m]; // precomputed table with the values to be skipped   
   
   findPrefix(pattern, m, prefixArray); // preparing failure function & table
   
   cout<<"\n The precomputed table is..\n ";
   for(i=0;i<m;i++)
     cout<<prefixArray[i]<<" ";
   
   cout<<"\n";
   
   while(i < n) 
   {
      if(mainString[i] == pattern[j]) 
	  {
         i++; j++;
      }

      if(j == m) 
	  {
             cout<<"Pattern found at "<<i-j<<"\n"; // Here i-j is the starting position of the pattern in the mainstring
			 return;     
      }
	  else 
	  if((i < n) && (pattern[j] != mainString[i])) // if mismatch occurs at jth position
	  {
         if(j != 0)
            j = prefixArray[j-1];// here we consider the number of positions to be skipped
         else
            i++;
      }
   }
   cout<<" Sorry...! Pattern not found...!";
}

int main() {
   char str[50] = "aaaabbaaabaabaabbbaaaab";
   char patt[20] = "aabaa";
   
   kmp(str, patt);
}
