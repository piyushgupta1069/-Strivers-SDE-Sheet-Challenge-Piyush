#include <bits/stdc++.h> 
class LFUCache
{
public:
    set<vector<int>>s;// {freq,counter,key}
    map<int,vector<int>>m;// {key,{value,counter,freq}}
    int sz;
    int cnt;
    LFUCache(int capacity)
    {
        // Write your code here.
        sz=capacity;
        cnt=0;
    }

    int get(int key)
    {
        // Write your code here.
        cnt++;
        if(m.count(key)==0)return -1;
        int freq = m[key][2];
        int val = m[key][0];
        int count = m[key][1];
        s.erase({freq,count,key});
        s.insert({freq+1,cnt,key});
        m[key]={val,cnt,freq+1};
        return val;
    }

    void put(int key, int value)
    {
        // Write your code here.
        cnt++;
        if(m.count(key)){
            int freq = m[key][2];
            int val = m[key][0];
            int count = m[key][1];
            s.erase({freq,count,key});
            s.insert({freq+1,cnt,key});
            m[key]={value,cnt,freq+1};
        }else{
            if(s.size()==sz){
                auto it = *s.begin();
                s.erase(s.begin());
                m.erase(it[2]);
            }
            s.insert({1,cnt,key});
            m[key]={value,cnt,1};
        }
    }
};
