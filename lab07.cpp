#include <iostream>
#include <vector>
using namespace std;

//precondition: v.size() > 0 && 1 <= k && k <=v.size()
int kth_selection(const vector<int>& v, size_t k) {
    vector<int> left, mid, right;
    if(k == 1)
        return v[0];
     
    for(size_t i = 1; i <= k; i++){
        if(v[i] < v[0])
            left.push_back(v[i]);
        else if(v[i] > v[0])
            right.push_back(v[i]);
        else
            mid.push_back(v[i]);
    }
    
    if(left.size() > 0)
        kth_selection(left, left.size());                
    else
        return mid[0];   
}

int main(){
    vector<int> v = {3, 2, 5, 7, 6, 8, 1, 9, 4};
    size_t k = 4;
    cout << kth_selection(v, k) << endl;
}