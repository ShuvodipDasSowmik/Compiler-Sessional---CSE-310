int helper(){
    int x;
    x = 42;
    return x;
}

int main(){
    int a;
    {
        int b;
        b = 7;
        a = b * 2;
    }
    println(a);
    {
    }
    return 0;
}
