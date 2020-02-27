#include<bits/stdc++.h>
using namespace std;

int lsearch(int buffer[], int n, int key){
    for(int i = 0; i < n; i++){
        if(key == buffer[i]){
            return i;
        }
    }
    return -1;
}
void dispArray(int a[], int n){
    for(int i = 0; i < n; cout<<a[i++]<<" ");
    cout<<endl;
}

int fifo(int pages[], int n, int frames){
    int pagefaults = 0;
    int buffer[frames];
    memset(buffer, -1, sizeof(buffer));
    int k = 0;
    for(int i = 0; i < n; i++){
        if(lsearch(buffer, frames, pages[i]) == -1){
            buffer[k] = pages[i];
            k = (k+1)%frames;
            pagefaults++;
        }
        dispArray(buffer, frames);
    }
    return pagefaults;
}

int main(){
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; 
    int n = sizeof(pages)/sizeof(pages[0]); 
    int capacity = 4; 
    cout << fifo(pages, n, capacity) << endl; 
    return 0; 
}