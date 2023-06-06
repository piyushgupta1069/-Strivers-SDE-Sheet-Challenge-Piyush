void solve(int i, vector<int>&temp, vector<vector<int>>&res, vector<int>&arr, int k)
{
    if(i==arr.size())
    {
        int sum = accumulate(temp.begin(),temp.end(),0);
        if(sum==k){
            res.push_back(temp);
        }
        return;
    }
    solve(i+1,temp,res,arr,k);
    temp.push_back(arr[i]);
    solve(i+1,temp,res,arr,k);
    temp.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>res;
    vector<int>temp;
    solve(0,temp,res,arr,k);
    return res;
}
