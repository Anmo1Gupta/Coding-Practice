// catalan number
#include <iostream>
using namespace std;

int cat(int n){
    if(n<=1) return 1;
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=cat(i)*cat(n-i-1);
    }
    return ans;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<cat(n)<<endl;
	}
	
	return 0;
}
