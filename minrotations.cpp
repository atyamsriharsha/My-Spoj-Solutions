#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std ;
int main()
{
	string s ;
	string min ,rotate,ref;
	cin >> s ;
	min = s ;
	ref = s ;
	int length,count=0;
	length = s.length() ;
	//cout << length << endl ;
	std::rotate(s.begin(),s.begin()+1,s.end()) ;
	while(length>1)
	{
	//	cout << s << "--this is the rotated string" <<endl  ;
	//	cout << min << "--this is the min string" <<endl  ;
		if(string(min)>string(s))
		{
			 min = s ;
	//		 std::rotate(s.begin(),s.begin()+1,s.end()) ;
		}
		std::rotate(s.begin(),s.begin()+1,s.end()) ;
		length-- ;
	}
	//cout << min << "--this is the min string" <<endl  ;
	//cout << ref << "--this is the ref string" <<endl  ;
	while(string(ref)!=string(min))
	{
		std::rotate(ref.begin(),ref.begin()+1,ref.end()) ;
		count++ ;
	}
	cout << count ;
	return 0 ;
}
