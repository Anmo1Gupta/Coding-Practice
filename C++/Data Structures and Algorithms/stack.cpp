//Stack using C++ Array
#include <iostream>
using namespace std;

int stack[100], n = 100, top = -1;

void push(int val)
{
    if (top >= n - 1) {
        cout << "Stack Overflow" << endl;
    }
    else {
        top++;
        stack[top] = val;
    }
}

void pop() {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int main() {
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}


//Stack Using STL
// #include<bits/stdc++.h>

// using namespace std;

// void showStack(stack <int> s){
//     while(!s.empty()){
//         cout<<" "<<s.top();
//         s.pop();
//     }
//     cout<<endl;
// }

// int main(){
//     stack <int> s ;
//     s.push(10);
//     s.push(30);
//     s.push(20);
//     s.push(5);
//     s.emplace(1);

//     showStack(s);

//     cout<<"size of stack = "<<s.size();

//     cout<<"\ns.top() = "<<s.top();

//     cout<<"\nPopping from stack. New stack = "; s.pop();

//     showStack(s);
// }