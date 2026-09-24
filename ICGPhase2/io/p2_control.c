int main(){
    int x, i, one, zero;

    one = 1;
    zero = 0;

    x = -3;
    if (x > 0){
        println(one);
    }
    else{
        println(zero);
    }

    for (i = 1; i <= 4; i++){
        println(i);
    }

    i = 0;
    while (i < 3){
        println(i);
        i = i + 1;
    }

    return 0;
}
