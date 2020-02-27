#include<bits/stdc++.h>
using namespace std;
class Hash{
    int BUCKET;
    list<int> *table;
    public: 
    Hash(int);
    void Insert(int);
    void Delete(int);
    void Display();
};

Hash::Hash(int b){
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::Insert(int key){
    int index = key % BUCKET;
    table[index].push_back(key);
}

void Hash::Delete(int key){
    int index = key % BUCKET;
    list<int>::iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++){
        if(*i == key){
            break;
        }
    }
    if(i != table[index].end()){
        table[index].erase(i);
    }
}

void Hash::Display(){
    for(int i = 0; i < BUCKET; i++){
        cout<<i;
        for(auto x: table[i]){
            cout<<"-->"<<x;
        }
        cout<<endl;
    }
}
int main(){
    int data[] = {12, 23, 45, 34, 51};
    int n = sizeof(data)/ sizeof(data[1]);
    Hash h(7);
    for(int i = 0; i < n; i++){
        h.Insert(data[i]);
    }
    h.Display();
    return 0;
}