int fatorial(int num) 
{
    int fat = 1;

    for(int i = 1; i < num; i++) {
        fat = fat * (i + 1);
    }

    return fat;
}

int area_square(int value)
{
    return area_retangle(value, value);
}

int area_retangle(int side, int base) 
{
    return side * base;
}