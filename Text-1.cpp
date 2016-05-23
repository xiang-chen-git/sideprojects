#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>



using namespace std;


vector<vector<int>> fourSum(vector<int>&num,int target){
    vector<vector<int>> result;
    if(num.size()<4) return result;
    sort(num.begin(),num.end());
    
    auto last = num.end();
    auto first = num.begin();
    for(auto i=first;i<prev(last,3);i++){
        for(auto j=next(i);j<prev(last,2);j++){
            auto k =next(j);
            auto h =prev(last);
            while(k<h){
                auto sum = *i+*j+*k+*h;
                if(sum<target){
                    k++;
                }else if(sum>target){
                    h--;
                }else{
                    result.push_back({*i,*j,*k,*h});
                    k++;h--;
                }
            }
        }
    }
    
    
    
    
    
    
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    
    return result;
}