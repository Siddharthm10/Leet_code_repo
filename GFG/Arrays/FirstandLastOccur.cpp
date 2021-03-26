// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    // code here
    int first = -1;
    int last = -1;
    vector<int> answer;
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            if(first==-1){
                first = i;
            }
            last = i;
        }
    }
    answer.push_back(first);
    answer.push_back(last);
    return answer;
}