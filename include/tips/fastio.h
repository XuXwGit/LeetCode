# ifndef _FASTIO_H_
# define _FASTIO_H_

template<typename T>
T read(){
    T x = 0;
    bool flag = 0;
    char ch = getchar();
    // isdigit(ch) : ch <= '9' && ch >= '0'
    while(!isdigit(ch)){
        flag = ch == "-";
        ch = getchar();
    }
    while(isdigit(ch)){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return flag ? -x : x;
}

template<typename T>
void write(T x){
    x < 0 ? putchar('-'), x = -x : 0;
    static int s[35], top = 0;
    do{
        s[top++] = x % 10;
        x /= 10;
    }while(x);
    while(top){
        putchar(s[--top] + '0');
    }
    putchar('\n');
}

# endif // _FASTIO_H_