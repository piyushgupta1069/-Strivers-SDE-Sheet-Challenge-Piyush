#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int cnt1=0,cnt2=0,num1=-1,num2=-1;
    for(int i=0;i<arr.size();i++){
        if(cnt1==0&&arr[i]!=num2){
            num1=arr[i];
            cnt1++;
        }else if(cnt2==0&&arr[i]!=num1){
            num2=arr[i];
            cnt2++;
        }
        else{
            if(num1==arr[i])cnt1++;
            else if(num2==arr[i])cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
    }
    cnt1=0;
    cnt2=0;
    int n = arr.size();
    for(int i=0;i<arr.size();i++){
        if(num1==arr[i])cnt1++;
        if(num2==arr[i])cnt2++;
    }
    if(cnt1>n/3&&cnt2>n/3)return {num1,num2};
    if(cnt1>n/3)return {num1};
    if(cnt2>n/3)return {num2};
    return {};

}
