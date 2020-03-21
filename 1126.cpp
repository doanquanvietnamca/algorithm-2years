#include <deque>
#include <cstdio>

 struct Node {
    int index;
     int value;
};
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    Node node;
    deque<Node> dq;
    int tmp;
    int num=0;
    while(scanf("%d", &node.value) && node.value!=-1){
        node.index= num++;
        while(!dq.empty() && dq.front().index < num-n )dq.pop_front();
        while(!dq.empty()&& dq.back().value < node.value)dq.pop_back();
        dq.push_back(node);
        if(num>=n)printf("%d\n", dq.front().value);
    }
    return 0;

}

//using namespace std;
// int main()
// {
//     vector<int> slt;
//     int n;
//     scanf("%d",&n);

//         int sque = 0 ;
//         while(1){
//                 scanf("%d",&sque);
//                 if(sque==-1){break;}
//                 slt.push_back(sque);
//         }
//         if(slt.size()<n)return 0;
//         vector<int> ans;
//          for(int i = 0; i <= slt.size()-n; i++)
//         {
//             ans.push_back(*max_element(slt.begin()+i, slt.begin()+i+n));
//         }
        
//         for(int i = 0; i <ans.size(); i++)
//         {
//             printf("%d\n",ans[i]);
//         }

//     return 0;
// }