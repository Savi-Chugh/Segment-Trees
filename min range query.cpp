#include<iostream>
#include<climits>
using namespace std;

void constructmin(int arr[],int segment[],int low,int high,int pos)
{
	if(low==high)
	{
		segment[pos]=arr[low];
		return;
	}
	int mid=(low+high)/2;
	constructmin(arr,segment,low,mid,2*pos+1);  //create left subtree with root at 2*pos +1 of segment tree
	constructmin(arr,segment,mid+1,high,2*pos+2); //create right subtree with root at 2*pos +2 of segment tree
	segment[pos]=min(segment[2*pos+1],segment[2*pos+2]); //root data will be minimum of root of leftsubtree and root of right subtree
}
int rangemin(int segment[],int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow<=low && qhigh>=high)
	{
		return segment[pos];		//total overlap
	}
	if(qlow>high || qhigh<low)    //no overlap
	{
		return INT_MAX;				//a very big value
	}
	//otherwise do this
	int mid=(low+high)/2;
	int left=rangemin(segment,qlow,qhigh,low,mid,2*pos+1);
	int right=rangemin(segment,qlow,qhigh,mid+1,high,2*pos+2);
	return min(left,right);
}

int main()
{
	int arr[4]={-1,2,4,0};
	int segmenttree[7];
	int i;
	for(i=0;i<7;i++)
	{
		segmenttree[i]=1000;
	}
	constructmin(arr,segmenttree,0,3,0);
	cout << rangemin(segmenttree,0,3,0,3,0)<< endl;
	
	

	return 0;
}
