#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std ;
int main()
{
	const char *s1="atyam" ;
	int n,length ;
	//cin >> s1 ;
	cin >> n ;
	//length = s1.length() ;
	//cout << length << endl ;
	while(n)
	{
	//	int count = 0,k,p=0 ;
		const char *s2 ="at";
	//	cin >>s2 ; 
		const char * p ;
		p = strstr(s1.c_str(),s2.c_str()) ;
		if(p!=NULL)
			cout << "Y" << endl ;
		else
			cout << "N" << endl ;
	//	int length1=s2.length() ;
		//cout << length1 << endl ;
	/*	for(int i=0;i<length-length1;i++)
		{
			k=0,count=0 ;
				for(int j=i;j<i+length1;j++)
				{
					if(s1[j]!=s2[k])
						break ;
					else
					{
						count++ ;
					//	cout << count ;
					}
					k++ ;
				}
				if(count==length1)
				{
					p=1;
					cout<<"Y"<<endl;
					break ;
				}
		}
		if(p==0)
			cout<<"N" <<endl;*/
		n-- ;
	}
	return  0 ;
}