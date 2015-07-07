#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long
typedef pair< string, int > psi;
const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;

int main() 
{	
	int t, n, i, subtime, teamid, probid;
	int attempt[10], timing[10], accepted[10], temp[64][10];
	map< string, int > M;
	map< string, int > :: iterator itm;
	char team[8], prob[2], ver[2], solved[64][10];
	double avrtime, avrsub, acsub;
	scanf("%d", &t);
	while(t--) 
	{
		M.clear();
		CLR(solved);
		CLR(temp);
		CLR(timing);
		CLR(attempt);
		CLR(accepted);
		i = 0;	
		scanf("%d", &n);
		while(n--) 
		{
			scanf("%d%s%s%s", &subtime, team, prob, ver);		
			itm = M.find(team);
			if(itm==M.end())
			 M.insert(psi(team, teamid = i++));
			else 
				teamid = itm->second;
			probid = prob[0]-'A';
			if(!solved[teamid][probid])
			 {
				temp[teamid][probid]++;
				if(ver[0]=='A')
				{
					solved[teamid][probid] = 1;
					accepted[probid]++;
					timing[probid] += subtime;
				}
			}
		}
		
		for(teamid = 0; teamid < i; teamid++)
			for(probid = 0; probid < 9; probid++)
				if(solved[teamid][probid])
					attempt[probid] += temp[teamid][probid];
		
		for(i = 0; i < 9; i++) 
		{
			if(accepted[i]) 
			{
				acsub = accepted[i];
				avrtime = timing[i]; avrtime /= acsub;
				avrsub = attempt[i]; avrsub /= acsub;
				printf("%c %d %.2lf %.2lf\n", i+'A', accepted[i], avrsub, avrtime);
			}
			else printf("%c 0\n", i+'A');
		}
	}
	return 0;
}