int multiply(int a, int b){
    return a * b;
}

int add_three(int a, int b, int c){
    return a + b + c;
}

int factorial(int n){
    if (n <= 1){
        return 1;
    }
    return n * factorial(n - 1);
}

int main(){
    int g;

    g = multiply(6, 7);
    println(g);

    g = add_three(1, 2, 3);
    println(g);

    g = factorial(5);
    println(g);

    g = factorial(1);
    println(g);

    g = factorial(0);
    println(g);

    return 0;
}
