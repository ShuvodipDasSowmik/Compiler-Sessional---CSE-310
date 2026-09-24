int main(){
    int a, b, p;

    a = 1;
    b = 0;

    p = a && b;
    println(p);
    p = a || b;
    println(p);
    p = !a;
    println(p);
    p = !b;
    println(p);

    p = a < b;
    println(p);
    p = a > b;
    println(p);
    p = a == b;
    println(p);
    p = a != b;
    println(p);
    p = a <= b;
    println(p);
    p = a >= b;
    println(p);

    p = ((a < 5) && (b < 5)) || (a == 1);
    println(p);

    return 0;
}
