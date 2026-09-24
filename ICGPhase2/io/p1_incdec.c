int main(){
    int a, b, c;

    a = 5;
    b = a++;
    println(b);
    println(a);

    c = a--;
    println(c);
    println(a);

    a = a + 0;
    a = a - 0;
    a = a * 1;
    println(a);

    return 0;
}
