#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
long long int flag1=0;
void printArray(long long int arr[],long long int n);
int AreAll9s(long long int num[],long long int n);
void generateNextPalindromeUtil(long long int num[],long long int n)
{
    long long int mid = n/2;
    bool leftsmaller = false;
    long long int i = mid-1;
    long long int j = (n%2)?mid + 1:mid; 
    while(i>= 0 && num[i]==num[j])
        i--,j++;
    if(i<0||num[i]<num[j])
        leftsmaller = true;
    while(i>= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
    if(leftsmaller == true)
    {
        long long int carry = 1;
        i = mid - 1;
        if(n%2==1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;
        while(i>=0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--]; 
        }
    }
}
void generateNextPalindrome(long long int num[],long long int n)
{
    long long int i;
 //   printf("\nNext palindrome is:\n");
    if(AreAll9s(num,n))
    {
        printf("1");
        for( i = 1;i<n;i++)
            printf("0");
        if(flag1!=1)
        printf("1\n");
        else
            printf("1");

    }
    else
    {
        generateNextPalindromeUtil(num,n);
        printArray(num,n);
    }
}
int AreAll9s(long long int* num, long long int n)
{
   long long int i;
    for(i=0;i<n;++i)
        if(num[i]!=9)
        {
         //   cout << "no 9" ;
            return 0;
        }
    return 1;
}
void printArray(long long int arr[],long long int n)
{
   long long int i;
    for(i=0;i<n;i++)
        printf("%lld",arr[i]);
    if(flag1!=1)
    printf("\n");
}
int main()
{
  long long int test;
  static long long int flag1 = test ;
    scanf("%lld",&test);
    while(test)
    {
        long long int p,m ,count=0,flag;
        scanf("%lld",&p);
        m = p ;
        while(p!=0)
        {
            p = p/10 ;
            count++ ;
        }
        long long int num[count] ;
        flag = count ;
       // cout << count ;
     //   cout << m ;
        while(m!=0)
        {
           // cout << "asdf" ;
            num[count-1] = m%10 ;
      //    cout << num[count-1] ;
            m = m/10 ;
            count-- ;
        }
   //     cout << m ;
      //  cout << flag ;
   //  for(i=0;i<flag;i++)
     //       cout << num[i] ;
       // cout << endl ;
        //cout << flag << endl ;
        //int n = sizeof (num)/ sizeof(num[0]);
        flag1-- ;
       generateNextPalindrome(num,flag);
        test-- ;
    }
    return 0;
}