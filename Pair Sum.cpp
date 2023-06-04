vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>>res;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
      for(int j=i+1;j<arr.size();j++)
      {
         if(arr[i]+arr[j]==s){
            res.push_back({arr[i],arr[j]});
         }
      }
    }
    return res;
    
    
}
