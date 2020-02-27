#include<bits/stdc++.h>
using namespace std;
class Hash{
    int BUCKET;
    int *table;
    public: 
    Hash(int);
    void Insert(int);
    void Delete(int);
    int Hashfunc(int k){
        return k % BUCKET;
    }
    void Display();
};

Hash::Hash(int b){
    this->BUCKET = b;
    table = new int[BUCKET];
    for(int i = 0; i < BUCKET; table[i++] = -1);
}

void Hash::Insert(int key){
    int index = Hashfunc(key);
    if(table[index] == -1){
        table[index] = key;
        return;
    } else {
        int i;
        for(i = 0; i < BUCKET; i++){
            index = (index + 1) % BUCKET;
            if(table[index] == -1){
                table[index] = key;
                return;
            }
        }
        if(i == BUCKET){
            cout<<"Array is full..."<<endl;
            return;
        }
    }
}

void Hash::Delete(int key){
    int index = Hashfunc(key);
    if(table[index] == key){
        table[index] = -1;
        return;
    }
    else {
        int i ;
        for(i = 0; i < BUCKET; i++){
            index = (index + 1) % BUCKET;
            if(table[index] == key){
                table[index] = -1;
                return;
            }
        }
        if(i == BUCKET){
            cout<<"Item not found\n";
        }
    }
}

void Hash::Display(){
    for(int i = 0; i < BUCKET; i++){
        cout<<i;
        if(table[i] != -1){
            cout<<" : "<<table[i]<<endl;
        } else {
            cout<<" : "<<endl;
        }
    }
}

int main()
{
    int a[] = {15,25,11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);

    // insert the keys into the hash table
    Hash h(7); // 7 is count of buckets in
               // hash table
    for (int i = 0; i < n; i++)
        h.Insert(a[i]);
    // delete 12 from hash table
    // h.deleteItem(12);

    // display the Hash table
    h.Display();

    return 0;
}