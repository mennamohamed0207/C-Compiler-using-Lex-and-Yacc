int add(int a, int b)
{
    int c = a + b;

    return c;
}

float calculate(float x)
{
    int y = 2;
    return x * 2.0;
}

int main()
{
    int a = 5;
    int result=0;
    result = add(a, 3);
    float value=0.0;
    value = calculate(4.0);

    return 0;
}