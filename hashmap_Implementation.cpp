#include <bits/stdc++.h>
using namespace std;
// hashtable that will store 
class HashTable{
    int size;
    vector<vector<pair<int,string>>> buckets;
    int hashFunction(int x){
        return x%size;
    }
    public:
    HashTable(int n){
        size = n;
        buckets.resize(n);
    }

    void insertItem(int key,string val){
        int bucketNo = hashFunction(key);
        bool keyIsPresent = false;
        for(auto it : buckets[bucketNo]){
            if(it.first==key){
                keyIsPresent = true;
                it.second = val;
                break;
            }
        }
        if(!keyIsPresent){
            buckets[bucketNo].push_back({key,val});
        }
    }

    void removeItem(int key){
        int bucketNo = hashFunction(key);
        bool keyIsPresent = false;
        auto itr = buckets[bucketNo].begin();
        for(;itr!=buckets[bucketNo].end();itr++){
            if(itr->first==key){
                keyIsPresent = true;
                break;
            }
        }
        if(keyIsPresent) buckets[bucketNo].erase(itr);
    }

    string searchItem(int key){
        int bucketNo = hashFunction(key);
        bool keyIsPresent = false;
        auto itr = buckets[bucketNo].begin();
        for(;itr!=buckets[bucketNo].end();itr++){
            if(itr->first==key){
                return itr->second;
            }
        }
        cout << "Key is not present [returning empty string]" << endl;
        return "";
    }

    ~HashTable(){

    }
};

int main(){
    // Above implementation works in O(k) complexity
    // where k = N/(bucket_size)
    // here N is the max limit of range of numbers that will be used as key
    
    // But we know that hashmap works in O(1) for insert,erase and find
    // To achieve that we need to make buckets of self balancing binary search tree
    // for smaller value of k, log(k) will be very close to const. time complexity
    HashTable mp(500);
    mp.insertItem(8,"This is 8 hehe");
    mp.insertItem(508,"This is 508 hehe");
    mp.insertItem(722,"This is 722 hehe");
    mp.insertItem(2910,"Jay Jay shree Radhe");
    mp.insertItem(555,"Bolo siyavar ramchandra ki jay..");
    cout << mp.searchItem(2910) << endl;
    cout << mp.searchItem(508) << endl;
    cout << mp.searchItem(8) << endl;
    mp.removeItem(508);
    cout << mp.searchItem(508);
    cout << mp.searchItem(722);
    return 0;
}