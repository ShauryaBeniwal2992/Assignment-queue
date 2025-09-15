#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<int> q1,q2;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    // stack usin 2 que
    while(!q1.empty()){
        cout<<"poped: "<<q1.back()<<endl;
        queue<int> temp;
        while(q1.size()>1){
            temp.push(q1.front());
            q1.pop();
        }
        q1.pop();
        q1=temp;
    }

    // stack usin 1 que
    queue<int> q;
    q.push(4);
    q.push(5);
    q.push(6);

    for(int i=0;i<3;i++){
        cout<<"poped: "<<q.back()<<endl;
        queue<int> tmp;
        while(q.size()>1){
            tmp.push(q.front());
            q.pop();
        }
        q.pop();
        q=tmp;
    }

    return 0;
}
