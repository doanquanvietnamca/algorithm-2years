#include<stdio.h>
#include <cstring>
#include <vector>
const int N = 320005;
int query[N], ans[N];
int main()
{
    int n;
    //FILE* op = freopen("1028.txt", "r", stdin); 
	scanf("%d", &n) ;
    std::vector<int> x;
    int y;
    int tmp;
    int mid=0;
    std::vector<int>::iterator it = x.begin();
	for( int register i =0;i<n;++i){
        scanf("%d%d", &tmp,&y);
        int l=0, r=x.size();
        while(l<=r&& !x.empty()){
         mid = l+(r-l)/2;
        if(x[mid]==tmp)break;
        if(x[mid]>tmp)r=mid-1;
        else l = mid+1;
        }
        ++query[mid];
        x.insert(it+ mid,tmp);
    }
    
    for(int i = 0; i < n; ++i) printf("%d\n", query[i]);
    return 0;
}