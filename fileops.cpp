#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void reset()
{
    fstream f;
    f.open("file.txt",ios::out | ios::in | ios::trunc);
    f.close();
}

void Find()
{
    fstream f;
    f.open("file.txt",ios::in);
    string key,s;
    int pos;
    cout<<"Enter string to find : ";
    cin>>key;
    while(!f.eof())
    {
        getline(f,s);
        pos=s.find(key);
        if(pos<s.size())
        {
            cout<<"Found at position "<<pos<<endl;
            return;
        }
    }
    cout<<"String not found!"<<endl;
    f.close();
}

void read()
{
    fstream f;
    f.open("file.txt",ios::in);
    string s;
    while(!f.eof())
    {
        getline(f,s);
        cout<<s;
        cout<<endl;
    }
    f.close();
}

void findnext()
{
    fstream f;
    f.open("file.txt",ios::in);
    string key,s;
    bool flag=false;
    int pos;
    cout<<"Enter string to find : ";
    cin>>key;
    char ch;

    while(!f.eof())
    {
        pos=0;
        getline(f,s);
        // cout<<s<<endl;
        pos=s.find(key);
        if(pos<s.size())
        {
            flag=true;
            cout<<"Found at position "<<pos<<endl;
            cout<<"Find next? (y/n) : ";
            cin>>ch;
            if(ch=='n' || ch=='N') return;
            while((pos = s.find(key,pos+1) ) >=0)
            {
                cout<<"Found at position "<<pos<<endl;
                cout<<"Find next? (y/n) : ";
                cin>>ch;
                if(ch=='n' || ch=='N') return;
            }
        }
    }
    if(!flag)
    {
        cout<<"String not found!"<<endl;
    }
    f.close();
}

void Delete()
{
    fstream f;
    f.open("file.txt",ios::in);
    string key,s;
    int choice,pos;
    cout<<"Enter the string to delete : ";
    cin>>key;
    cout<<"Delete 1)all instances\n2)first instance\nEnter choice : ";
    cin>>choice;
    bool flag=true;
    vector <string> filearr;
    while(!f.eof())
    {
        getline(f,s);
        pos=s.find(key);
        if(pos<s.size() && flag)
        {
            cout<<"Found at position "<<pos<<endl;
            s.erase(pos,key.size());
            if(choice==2)
                flag=false;
        }
        filearr.push_back(s);
    }
    f.close();
    for(int i=0;i<filearr.size();i++)
        cout<<filearr[i]<<endl;
    f.open("file.txt",ios::out | ios::trunc);
    for(int i=0;i<filearr.size();i++)
    {
        filearr[i] = filearr[i] + '\n';
        f.write(filearr[i].c_str(),filearr[i].size());
    }
    f.close();
}

void modify()
{
    fstream f;
    f.open("file.txt",ios::in);
    string key,s,replacement;
    int choice,pos;
    cout<<"Enter the string to replace : ";
    cin>>key;
    cout<<"Replace with : ";
    cin>>replacement;
    cout<<"Delete 1)all instances\n2)first instance\nEnter choice : ";
    cin>>choice;
    bool flag=true;
    vector <string> filearr;
    while(!f.eof())
    {
        getline(f,s);
        pos=s.find(key);
        if(pos<s.size() && flag)
        {
            cout<<"Found at position "<<pos<<endl;
            s.replace(pos,key.size(),replacement);
            if(choice==2)
                flag=false;
        }
        filearr.push_back(s);
    }
    f.close();
    f.open("file.txt",ios::out | ios::trunc);
    for(int i=0;i<filearr.size();i++)
    {
        filearr[i] = filearr[i] + '\n';
        f.write(filearr[i].c_str(),filearr[i].size());
    }
    f.close();
}

void Insert()
{
    fstream f;
    f.open("file.txt",ios::out | ios::app);
    string s;
    cout<<"Enter the string to insert : ";
    getchar();
    getline(cin,s);
    s = s + '\n';
    f.write(s.c_str(),s.size());
    f.close();
}

int main()
{
    fstream f;
    f.open("file.txt",ios::out | ios::app);
    cout<<"File opened!"<<endl;

    int choice;
    do
    {
        cout<<"1)Reset\n2)Find\n3)Read\n4)Find Next\n5)Delete\n6)Modify\n7)Insert\n8)Close\n";
        cout<<"Enter a choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: reset();
                    break;
            case 2: Find();
                    break;
            case 3: read();
                    break;
            case 4: findnext();
                    break;
            case 5: Delete();
                    break;
            case 6: modify();
                    break;
            case 7: Insert();
                    break;
            case 8: f.close();
                    break;
            default:cout<<"Invalid option!"<<endl;
        }
    }
    while(choice!=8);
    return 0;
}
