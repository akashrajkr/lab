#include <bits/stdc++.h>
using namespace std;
int  lru(int pages[], int n, int frames)
{
    set<int> s;
    map<int, int> indices;
    int pagefaults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frames)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                pagefaults++;
            }
            indices[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val;
                int lru = INT_MAX;
                set<int>::iterator it;
                for (it = s.begin(); it != s.end(); it++)
                {
                    if (indices[*it] < lru)
                    {
                        lru = indices[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                pagefaults++;
            }

            indices[pages[i]] = i;
        }
    }
    return pagefaults;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;
    cout << lru(pages, n, capacity) << endl;
    return 0;
}