#include<iostream>    // 15956_���ڵ� [���ڿ�ó��]
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

/** ���ڿ� ��ū �Լ�;
*   @brief  ���ڿ��� ���ڿ��� ��ū�� ������ �ִ� �Լ�
*   @param s_   ��ū���� �ڸ� ���ڿ� 
*   @param k_   �������� �� ���ڿ� 
*   @return vector<string> �߷��� ���ڿ� 
*   ���ڿ��� �޾� ������ ���ڿ��� �������� ��ū�� �ڸ� �� 
*   vector<string>���� ��ȯ�ϴ� �Լ� 
*/
vector<string> strTok(string s_, string k_){
    vector<size_t> tokLocation = {0};
    vector<string> tok;
    
    int n;
    for(n=1;; n++){
        tokLocation.push_back(s_.find(k_, tokLocation[n-1]+1));
        if(tokLocation[n] == std::string::npos)
            break;
    }
    
    for(auto i=tokLocation.begin(); (i+1)!=tokLocation.end(); i++){
        if(i != tokLocation.begin())
            tok.push_back(s_.substr(*i+k_.size(), *(i+1) - *i-k_.size()));
        else
            tok.push_back(s_.substr(*i, *(i+1) - *i));
    }
    return tok;
}

bool checkString(string s_){
    if(s_[0] >= 'A' && s_[0] <= 'Z' ||
       s_[0] >= 'a' && s_[0] <= 'z' )
        return 0;
    else
        return 1;
}
struct Variable{
    string name;
    int value;
    
    bool operator!=(Variable &T){
        return (this->value != T.value || this->name != T.name);
    }
    bool operator==(Variable &T){
        return (this->value == T.value || this->name == T.name);
    }
};

int main() {
    string s;
	cin >> s;
    vector<string> token = strTok(s, "&&");

    for(auto i : token){
        cout << i << " ";
    }
    vector<Variable> var;
    vector<string> o_same;
    for(auto i : token){
        if(i.find("==")){
            o_same = strTok(i, "==");
            if(checkString(o_same[1])){
                Variable v_temp;
                v_temp.value = atoi(o_same[1].c_str());
            }
        }
        if(i.find("!=")){
            o_same = strTok(i, "==");

        }
    }
	return 0;
}