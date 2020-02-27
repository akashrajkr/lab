#include<bits/stdc++.h>
using namespace std;

bool find(int buffer[], bool second[], int frames, int key){
    for(int i = 0; i < frames; i++){
        if(buffer[i] == key){
            second[i] = true;
            return true;
        }
    }
    return false;
}
void dispArray(int a[], int n){
    for(int i = 0; i < n; cout<<a[i++]<<" ");
    cout<<endl;
}

int replace(int buffer[], bool second[], int n, int key, int pointer){
    while(true){
        if(!second[pointer]){
            buffer[pointer] = key;
            return (pointer + 1) % n;
        }
        second[pointer] = false;
        pointer = (pointer + 1) % n;
    }
}

int clock(int pages[], int n, int frames){
    int buffer[frames];
    bool second[frames] = {false};
    memset(buffer, -1, sizeof(buffer));
    dispArray(buffer, frames);
    int pointer = 0;
    int pagefaults = 0;
    for(int i = 0; i < n; i++){
        if(!find(buffer, second, frames, pages[i])){
            pointer =  replace(buffer, second, frames, pages[i], pointer);
            pagefaults++;
        }
        dispArray(buffer, frames);
    }
    return pagefaults;
}

int main(){
    int pages[] = {0, 4, 1, 4, 2, 4, 3, 4, 2, 4, 0, 4, 1, 4, 2, 4, 3, 4};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frames = 3;
    cout<<"Page faults: "<<clock(pages, n , frames)<<endl;
    return 0;
}