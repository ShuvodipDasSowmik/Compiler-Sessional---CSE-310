int g[3];

int main(){
    int local[3];
    int i;
    int v;

    g[0] = 0;
    g[1] = 100;
    g[2] = 200;

    local[0] = 0;
    local[1] = 10;
    local[2] = 20;

    i = 0;
    while (i < 3){
        v = g[i];
        println(v);
        i++;
    }

    i = 0;
    while (i < 3){
        v = local[i];
        println(v);
        i++;
    }

    return 0;
}
