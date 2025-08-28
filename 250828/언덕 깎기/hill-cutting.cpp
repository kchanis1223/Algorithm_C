#include <iostream>
#include <climits>
using namespace std;

int N;
int heights[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    // Please write your code here.
    int minSum = INT_MAX;
    for(int hl=0;hl<=83;hl++){
        int hh = hl+17;
        int sum = 0;
        for(int i=0;i<N;i++){
            if(heights[i] >= hl && heights[i] <= hh) continue;
            int cost = min(abs(heights[i] - hl) , abs(heights[i] - hh));
            sum += cost * cost;
        }
        //cout<<"sum : "<<sum<<endl;
        if(minSum > sum) minSum = sum;
    }

    cout<<minSum;
    return 0;
}