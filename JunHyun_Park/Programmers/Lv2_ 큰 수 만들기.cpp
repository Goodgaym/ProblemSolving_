#include <string>   // Level2_ ū �� ����� [�׸���]
#include <vector>

#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    int n = number.size()-k, idx = -1;

    for(int i=0; i<n; i++){
        char max = 0;
        for (int j=idx+1; j<=k+i; j++){
            if(max < number[j]){
                max = number[j];
                idx = j;
            }
        }
        answer += max;
    }

    return answer;
}