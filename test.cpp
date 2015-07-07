#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Utility function to print a vector
void printVector(vector< pair<int,int> > v1)
{
	vector< pair<int,int> >::iterator it;
	for(it=v1.begin();it!=v1.end();it++)
	{
		cout<<it->first<<","<<it->second<<endl;
	}
}

//Compare Function for Sorting
bool compare(pair<int,int> p1, pair<int,int> p2)
{
	if((p1.second)<(p2.second))
		return true;
	return false;
}

// Prints a maximum set of activities that can be done by a single person, one at a time.
int selectMaxActivities(vector< pair<int,int> > v1)
{
	int count = 1 ;
	cout<<"The following Activities are Selected:"<<endl;
	//First Activity will always be selected
	pair<int,int> prev_task=v1[0];
	cout<<prev_task.first<<","<<prev_task.second<<endl;
	
	// Consider rest of the activities
	for(int j=1;j<v1.size();j++)
	{
		pair<int,int> curr_task=v1[j];
		// If this activity has start time greater than or equal to the finish
        // time of previously selected activity, then select it
		if((curr_task.first) >= (prev_task.second))
		{
//			cout<<curr_task.first<<","<<curr_task.second<<endl;
			//cout << "asd" ;
			count++ ;
			prev_task=curr_task;
		}
	}
	return count ;
}

// Driver program to test above function
int main()
{
	int s[] =  {4, 3, 2, 1, 0};//An array that contains start time of all activities
    int f[] =  {14,13,12,11,10};//An array that contains finish time of all activities
	int n = sizeof(s)/sizeof(s[0]);
	vector< pair<int,int> > tasks;
	int p ;
	
	for(int i=0;i<n;i++)
	{
		tasks.push_back(make_pair(s[i],f[i]));
	}
	
	cout<<"Before Sorting by finish times"<<endl;
	printVector(tasks);
	
	cout<<"After Sorting by finish times"<<endl;
	sort(tasks.begin(),tasks.end(),compare);
//	printVector(tasks);
	
	p=selectMaxActivities(tasks);
	cout << p ;
	
	return 0;
}