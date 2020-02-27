#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> createBlocks(){
    int n = 100;
    vector<vector<int>> Blocks;
    for(int i = 0; i < n; i++){
        vector<int> block;
        for(int j = 0; j < 10; j+= 2){
            block.push_back(i*10+j);
        }
        Blocks.push_back(block);
    }
    return Blocks;
}

void binarySearch(vector<vector<int>> blocks, int key){
    int l = 0, u = 99, mid;
    while(u >= l){
        mid = (u + l) / 2;
        vector<int> temp = blocks[mid];
        if(key < temp.front())
            u = mid - 1;
        else if( key > temp.back())
            l = mid + 1;
        else {
            for(int i = 0; i < 4; i++){
                if(temp[i] == key){
                    cout<<"Found at block "<<mid<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Not found"<<endl;
}

int main(){
    vector<vector<int>> blocks = createBlocks();
    binarySearch(blocks, 242);
    return 0;
}