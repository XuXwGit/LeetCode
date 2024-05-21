/*
2024.5.15-HW-第二题-塔子哥的编译原理实验
题目描述
塔子哥这学期有一门压力巨大的专业课，编译原理，这到底是谁在听懂啊？啊？！还要做恁多实验。有一个实验要求塔子哥将C语言翻译成对应的汇编程序，这就需要对文本进行切词，聪明的塔子哥决定使用正则表达式来完成切词任务。

已知存在种字符串解析语法,其中的语法元素如下

 N：用于江配单个数字(0-9)

 A：用于四配单个字母(a-z，A-Z)

 n()：用于表示一个分组，分组中至少有一个N语法元素或者A语法元素，n为个数值,表示匹配n次，1<=n<=200

 输入给定的解析语法和字符串，要求从中找到第一个满足解析语法的字符串。
*/

#ifndef _EXAMINATION_HUAWEI_0515_LEXICAL_H_
#define _EXAMINATION_HUAWEI_0515_LEXICAL_H_

string get_pattern(string s){
    stack<int> nums;
    stack<string> strs;

    int num = 0;
    string str = "";
    
    for(int i = 0; i<s.size(); ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + s[i] - '0';
        }else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            str += s[i];
        }else if(s[i] == '('){
            nums.push(num);
            num = 0;
            strs.push(str);
            str = "";
        }else if(s[i] == ')'){
            int k = nums.top();
            nums.pop();
            for(int j = 0; j<k; ++j){
                strs.top() += str;
            }
            str = strs.top();
            strs.pop();
        }
    }

    return str;
}

bool check_char(char c1, char c2){
    if(c2 == 'N'){
        return c1 <= '9' && c1 >= '0';
    }else if(c2 == 'A'){
        return (c1 <= 'z' && c1 >= 'a') || (c1 <= 'Z' && c1 >= 'A');
    }
    return false;
}

int solution(string object, string pattern){
    vector<int> next(pattern.size());

    next[0] = 0;
    int left = 1;
    int prefix_len = 0;
    while(left < pattern.size()){
        if(pattern[prefix_len] == pattern[left]){
            prefix_len ++;
            next[left] = prefix_len;
            left ++;
        }else{
            if(prefix_len != 0){
                // here is pre_fix - 1 
                prefix_len = next[prefix_len - 1];
            }else{
                next[left] = 0;
                left ++;
            }
        }
    }

    int i = 0, j = 0;
    while(i < object.size()){
        if(check_char(object[i], pattern[j])){
            i ++;
            j ++;
        }else{
            if(j > 0){
                j = next[j - 1];                
            }else{
                i ++;
            }
        }

        if(j == pattern.size()){
            return i - j;
        }
    }

    return -1;
}

void test_0515_02(){

    string needle, object;
    // cin >> needle >> object;
    // 2(AN)
    // BA3A3ABB
    needle = "2(AN)";
    object = "BA3A3ABB";
    
    string pattern = get_pattern(needle);

    int begin = solution(object, pattern);
    if(begin == -1){
        cout << "-1" << endl;
    }else{
        cout << object.substr(begin, pattern.size()) << endl;
    }



    // 3(A)N4(A)5(N)11(A)N4(A)NA2(N)AN18(A)N8(A)2(N)8(A)N2(A)N8(A)N4(A)
    // 62FMta7vsDlZhGEfa5AA2aydv5JjltGc0QOh2E9fmcmW7lRJjjgwu7ZnL3088P0MVuytHfjkFXbgUJzlKkxWP3p1aKaeTYqcdgBuFXsGUexyP8Ns8ZwDPhtcu8UfHxra6bxujtngC6EsAV7FiVwdRwrTgufgsgKEsyEnvWZQZq685hleCJWAHfMtLwwy8zSCMIqXXGcw5tDTT902oCnzEJHQnpvJ7sleMXO8oMZLMNVXfiJhUUP4JqkmFPUUIwi3NWFYDnCo40jxoKv83zaIt6rhwx32XV4OV06NRpCPe8DTRHHpTb2fPz39nVR6HvvXA9pHQxyXPTDvpzXLW8YL5nNkda6OS5kC4MvNB4qEX1Zhrvb9zImMuGF8VSEz79138dOJXHXqNEuk5qLlM1D37e8gfaavPuteEvnqSvDtG3EoQXxeJP31PUgDZzwf4rG3uOCndLGh9TXyVvPJao55cOFwyTE1r38x8qbnf3Pg1P3
    needle = "3(A)N4(A)5(N)11(A)N4(A)NA2(N)AN18(A)N8(A)2(N)8(A)N2(A)N8(A)N4(A)";
    object = "62FMta7vsDlZhGEfa5AA2aydv5JjltGc0QOh2E9fmcmW7lRJjjgwu7ZnL3088P0MVuytHfjkFXbgUJzlKkxWP3p1aKaeTYqcdgBuFXsGUexyP8Ns8ZwDPhtcu8UfHxra6bxujtngC6EsAV7FiVwdRwrTgufgsgKEsyEnvWZQZq685hleCJWAHfMtLwwy8zSCMIqXXGcw5tDTT902oCnzEJHQnpvJ7sleMXO8oMZLMNVXfiJhUUP4JqkmFPUUIwi3NWFYDnCo40jxoKv83zaIt6rhwx32XV4OV06NRpCPe8DTRHHpTb2fPz39nVR6HvvXA9pHQxyXPTDvpzXLW8YL5nNkda6OS5kC4MvNB4qEX1Zhrvb9zImMuGF8VSEz79138dOJXHXqNEuk5qLlM1D37e8gfaavPuteEvnqSvDtG3EoQXxeJP31PUgDZzwf4rG3uOCndLGh9TXyVvPJao55cOFwyTE1r38x8qbnf3Pg1P3";

    pattern = get_pattern(needle);
    begin = solution(object, pattern);
    if(begin == -1){
        cout << "-1" << endl;
    }else{
        cout << object.substr(begin, pattern.size()) << endl;
    }
}


#endif // !_EXAMINATION_HUAWEI_0515_LEXICAL_H_