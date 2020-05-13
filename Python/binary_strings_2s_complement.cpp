#include <bits/stdc++.h> 

using namespace std;

string findTwoscomplement(string str) 
{ 
    int n = str.length(); 
  
    int i; 
    for (i = n-1 ; i >= 0 ; i--) 
        if (str[i] == '1') 
            break; 
  
    if (i == -1) 
        return '1' + str; 
  

    for (int k = i-1 ; k >= 0; k--) 
    { 

        if (str[k] == '1') 
            str[k] = '0'; 
        else
            str[k] = '1'; 
    } 
  
    return str;
} 


string addBinary(string a, string b) 
{ 
    string result = ""; 
    int s = 0;          
  

    int i = a.size() - 1, j = b.size() - 1; 
    while (i >= 0 || j >= 0 || s == 1) 
    {
        s += ((i >= 0)? a[i] - '0': 0); 
        s += ((j >= 0)? b[j] - '0': 0); 

        result = char(s % 2 + '0') + result; 

        s /= 2; 

        i--; j--; 
    } 
    return result; 
} 


bool checkIfBinary(string s) 
{ 
    int len = s.length(); 

    int first = s.size() + 1; 
    for (int i = 0; i < len; i++) { 
        if (s[i] == '1') { 
            first = i; 
            break; 
        } 
    } 

    int last = 0; 
    for (int i = len - 1; i >= 0; i--) { 
        if (s[i] == '1') { 
            last = i; 
            break; 
        } 
    } 
  
    for (int i = first; i <= last; i++) 
        if (s[i] == '0') 
            return false; 
  
    return true; 
} 


string ArithmeticCircuit(string num1, string num2, bool op, bool err){
    err = false;
    if(num1.length() > 32 || num2.length() > 32 || checkIfBinary(num1) == false || checkIfBinary(num2) == false){
        err = true;
        return "";
    }
    else{
        string sum, diff;
    
        string num1_twosC = findTwoscomplement(num1); 
        string num2_twosC = findTwoscomplement(num2);
        
        if(op == true){
            
            sum = addBinary(num1_twosC, num2_twosC);
            if(sum.length()>32){
                err = true;
            }
            return sum;
        }
        else if(op == false){
            
            diff = addBinary(num1,num2_twosC);
            if(diff.length()>32){
                err = true;
            }
            
            return diff;
        }
    }
}

int main() 
{ 
    bool err;
    string result;
    
    string num1 = "1110", num2 = "1100"; 
    
    result = ArithmeticCircuit(num1,num2,false,err);
    
    int max_length = num1.length();
    if(num2.length() > max_length) { max_length = num2.length();}
    if (result.length() > max_length){
        result.erase(0,1);
    }
    
    cout<<"result - "<<result;
    cout<<"\nerr - "<<err;
    return 0;
} 