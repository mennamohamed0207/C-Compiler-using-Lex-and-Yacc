int main()
{
    int a = 10;
    int b = 20;
    a = 10;
    const int c = 30;

    if (a < b)
    {
        int d = a + b;
        int e = c + d;
    }
    else
    {
        int y = a - b;
        int x = c - a;
    }

    char f;
    bool h = true;
    char j = 'a';
    string i = "Hello, World!";
    return 0;
}