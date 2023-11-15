#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){if(a%b==0) return b; else return gcd(b, a%b);}
int lcm(int a, int b) {return (a*b)/gcd(a,b);}

int n;
int arr[13][3]; // 13 coz statement spicifies that the maximum number of studnets is 10
                // in cp, it's a common practice to declare the size of the array slightly larger 
                // than the maximum limit to avoid any off-by-one errors or overflow issues
int status[13];


// checks how many students are awake and updates thier status
// returns true if everyone is awake, false otherwise
bool update(){
    int count = 0;
    for(int i=0; i<n; i++){
        if(status[i]<=arr[i][0]) count++;
    }
    if(count==n) return true;
    for(int i=0; i<n; i++){
        if(status[i]==arr[i][0] + arr[i][1] || (status[i] == arr[i][0] && n<= count*2)) status[i] = 1;
        else status[i]++;
    }
    return false;
}

int main(){
    int caseno = 1;
    while(1){
        cin>>n;
        if(n==0) break;

        int l = 1; // to hold lcm

        for(int i=0; i<n; i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
            status[i] = arr[i][2];
            l = lcm(l, arr[i][0]+arr[i][1]);
        }

        bool found;
        for(int t=1; t<=l; t++){ // here, no. of iterations it takes for all students to be awake is the output
            found = update();
            if(found){
                cout<<"Case "<< caseno++ <<": "<< t <<'\n';
                break;
            }
        }
        if(!found){
            cout<<"Case "<< caseno++ <<": -1"<<'\n';
        }
    }

    return 0;
}

// Time Complexity: O(n*l)
// n = number of students
// l is the least common multiple of all students' cycles

