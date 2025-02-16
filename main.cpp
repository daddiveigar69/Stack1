#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int transfer_disk(stack<int>& a,stack<int>& b){
    if(b.empty()==true){
        b.push(a.top());
        a.pop();
        return 1;               //checks if either of the two stacks are empty
                                // and pushes the top element of the one which is not empty into the one which is empty
    }
    else if(a.empty()==true){
        a.push(b.top());
        b.pop();
        return 2;
    }
    else{                       //If neither the stacks are empty it compares the top element of both and pushes the smaller one into the stack which has the bigger top element
        if(b.top()>a.top()){
            b.push(a.top());
            a.pop();
            return 1;
        }
        else{
            a.push(b.top());
            b.pop();
            return 2;
        }
    }
}
void push_number_of_disk(stack<int> &a, int nrdisks){       //inputs the numbers into the source rod
    for(int i=nrdisks;i>=1;i--){
        a.push(i);
    }
}
int main(){
    stack<int> source,aux,destination;
    int n=0;
    cout<<"How many disks do you want to insert?"<<endl;cin>>n;cout<<endl;
    push_number_of_disk(source,n);
    int total_moves=pow(2,n)-1;
    int i=1;
//splits the program into the    2 cases:
if(n%2==0){
    while(i<=total_moves){
            if(i%3==1){
            int y=transfer_disk(source,aux);
            if(y==1){
                cout<<"Move the disk "<<aux.top()<<" from source to auxiliary"<<endl;
            }
            else
                cout<<"Move the disk "<<source.top()<<" from auxiliary to source"<<endl;
            }
            else if(i%3==2){
            int y=transfer_disk(source,destination);
            if(y==1){
                cout<<"Move the disk "<<destination.top()<<" from source to destination"<<endl;
            }
            else
                cout<<"Move the disk "<<source.top()<<" from destination to source"<<endl;
            }
            else{
            int y=transfer_disk(aux,destination);
            if(y==1){
                cout<<"Move the disk "<<destination.top()<<" from auxiliary to destination"<<endl;
            }
            else
                cout<<"Move the disk "<<aux.top()<<" from destination to auxiliary"<<endl;
            }
            i++;
    }
}
else{
    while(i<=total_moves){
            if(i%3==1){
            int y=transfer_disk(source,destination);
            if(y==1){
                cout<<"Move the disk "<<destination.top()<<" from source to destination"<<endl;
            }
            else
                cout<<"Move the disk "<<source.top()<<" from destination to source"<<endl;
            }
            else if(i%3==2){
            int y=transfer_disk(source,aux);
            if(y==1){
                cout<<"Move the disk "<<aux.top()<<" from source to auxiliary"<<endl;
            }
            else
                cout<<"Move the disk "<<source.top()<<" from auxiliary to source"<<endl;
            }
            else{
            int y=transfer_disk(aux,destination);
            if(y==1){
                    cout<<"Move the disk "<<destination.top()<<" from auxiliary to destination"<<endl;
            }
            else
                cout<<"Move the disk "<<aux.top()<<" from destination to auxiliary"<<endl;
            }
            i++;
    }
}
                                        //couts the destination rod after it's been arranged
cout<<endl<<"Final outcome:"<<endl;
while(destination.empty()!=true){
        cout<<destination.top()<<endl;
        destination.pop();
    }


return 0;
}