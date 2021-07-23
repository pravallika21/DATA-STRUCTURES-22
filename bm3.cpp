 #include <bits/stdc++.h>
 using namespace std;
 #define TOTAL_CHARS 256 

 void badMatchTable(string STR, int size, int badcharacter[TOTAL_CHARS])
 {
     for (int i = 0; i < TOTAL_CHARS; i++) // Initialize all occurrences as -1
         badcharacter[i] = 0;
     // Put the value of last occurrence of the character
     for (int i = 0; i < size; i++)
	   badcharacter[(int)STR[i]] = i;
 }
 
 void BoyerMoore_Search(string text, string pattern)
 {
     int m = pattern.size();
     int n = text.size();
     int badcharacter[TOTAL_CHARS];

     badMatchTable(pattern, m, badcharacter); // Preprocess by filling bad character
     int shift = 0;

     while (shift <= (n - m)) // Shift until end of text
     {
         int j = m - 1;

         while (j >= 0 && pattern[j] == text[shift + j]) /* j  decreases until characters of pattern and text are match at the current shift */
             j--;

         if (j < 0) // It indicates pattern is there at current shift position
         {
	        cout << "pattern occurs at position = " << shift << endl;
	        return;
	     }
         else
             /* maximum function gives a positive shift . There are possible cases
                to get a negative shift value if last occurrence of bad character is on right of current one */
             shift += max(1, j - badcharacter[text[shift + j]]);
     }
 }
 

 
 int main()
 {
     string text = "aabaabbbbcabbbacbabba";
     string pattern = "abbba";
     BoyerMoore_Search(text, pattern);
     return 0;
 } 
