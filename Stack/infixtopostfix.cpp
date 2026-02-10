#include<iostream>
#include<string>
using namespace std;

class stack
{
    int top;
    char arr[100];
public:
    stack(){
        top=-1;
    }
    void push(char x){
        if(top==99){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            arr[++top]=x;
        }
    }
    char pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return '\0';
        }
        else{
            return arr[top--];
        }
    }
    char empty(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return '\0';
        }
        else{
            return arr[top];
        }
    }
};

int main(){
    char n[100];
    int size;
    char s[100]; 
    stack st;
    cout<<"Enter the number of elements in the array: ";
    cin>>size;
    cout<<"Enter the infix expression: ";
    for(int i=0; i<size; i++){
        cin>>n[i];
    }
    for(int j=0; j<size; j++){
        if(n[j]=='A' || n[j]=='B' || n[j]=='C' || n[j]=='D' || n[j]=='E' || n[j]=='F'){
            s[j]=n[j];
        }
        else{
            st.push(n[j]);
        }
    }
    cout<<"The postfix expression is: ";
    for(int k=0; k<size; k++){
        cout<<s[k];        
    }
    cout<<st.pop();
    cout<<st.pop();
}
