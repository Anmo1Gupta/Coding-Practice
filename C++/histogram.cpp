// program to find the max area rectangle in a given histogram

#include<iostream>
#include<stack>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int lb[n];
        lb[0] = -1;
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            while(s.size()>0 && arr[i]<arr[s.top()]){
                s.pop();
            }
            if(s.empty()){
                lb[i] =-1;
            }
            else{
                lb[i] = s.top();
            }
            s.push(i);
        }
        int rb[n];
        rb[n-1] = n;
        stack<int> s1;
        s1.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(s1.size()>0 && arr[i]<arr[s1.top()]){
                s1.pop();
            }
            if(s1.empty()){
                rb[i] =n;
            }
            else{
                rb[i] = s1.top();
            }
            s1.push(i);
        }
         int ans = 0;
        for(int i=0;i<n;i++){
            int temp = arr[i]*(rb[i]-lb[i]-1);
            if(temp>ans)
               ans = temp;
        }

        cout<<ans<<endl;
    }
    return 0;
}
