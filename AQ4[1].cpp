#include <iostream>
#include <queue>
using namespace std;

int main() {
    int fre[26] = {0};
    queue<char> qu;
    char arr[] = {'a','a','b','c'};
    int sze = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<sze;i++){
        char ch = arr[i];
        fre[ch-'a']++;
        qu.push(ch);

        while(!qu.empty() && fre[qu.front()-'a']>1){
            qu.pop();
        }

        if(qu.empty()){
            cout<<-1<<" ";
        } else {
            cout<<qu.front()<<" ";
        }
    }
    return 0;
}
