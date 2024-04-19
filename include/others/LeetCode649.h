#ifndef _LeeCode649_H_
#define _LeeCode649_H_

#include <string>

using namespace std;

class Solution649 {
public:
    string predictPartyVictory(string senate) {
        bool flag_R = true;
        bool flag_D = true;
        int count_R = 0;
        int count_D = 0;
        while(flag_D && flag_R){
            flag_R = false;
            flag_D = false;
            for(int i = 0; i<senate.size(); ++i){
                if(senate[i] == 'R'){
                    if(count_D > count_R){
                        senate[i] = '-';
                        count_D --;
                    }else{
                        flag_R = true;
                        count_R ++;
                    }
                }else if(senate[i] == 'D'){
                    if(count_D < count_R){
                        senate[i] = '-';
                        count_R --;
                    }else{
                        flag_D = true;
                        count_D ++;
                    }
                }
            }
        }
    
        return flag_R? "Radiant" : "Dire";   
    }
};


void test649(){
    Solution649 s;
    string senate = "RDD";
    cout << s.predictPartyVictory(senate) << endl;
}

#endif