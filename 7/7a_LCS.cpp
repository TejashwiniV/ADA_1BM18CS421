/*Program under Dynamic Programming:
7a. Printing Longest Common Subsequence*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s1,s2;
	cout<<"Enter the first string: ";
	cin>>s1;
	cout<<"Enter the second string: ";
	cin>>s2;
	const size_t l1=s1.length(),l2=s2.length();
	string subsequence="";
	for(size_t start=0;start<l1 && (l1-start) > subsequence.length();++start)
	{
		string temp="";
		size_t x,pos=0;
		for(size_t i=start;i<l1;++i)
		{
			x=s2.find(s1[i],pos);
			if(x!=-1)
			{
				temp+=s1[i];
				pos=x;
			}
		}
		if(temp.length() > subsequence.length())
			subsequence=temp;
	}
	cout<<"Longest comman subsequence: "<<subsequence<<"\nLength:"<<subsequence.length()<<"\n";
	cin.ignore();
}
/*
OUTPUT
Enter the first string: ABCDAF
Enter the second string: ACBCF 
Longest comman subsequence: ABCF
Length:4
*/
