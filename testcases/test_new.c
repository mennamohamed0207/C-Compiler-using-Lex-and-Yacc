
int add(int a, int b)
{
    {
        int a = 1;
        a += b;
    }
    return a + b;
}

void func()
{
    return;
}

int main()
{
    int i = 0;
    int j = 5;
    bool flag = true;
    char ch = 'X';
    float f = 2.5;
    string s = "foo";
    string t = "bar";

    {
        int i = 3;
        i += j;
    }

    for (int k = 0; k < 3; k++)
    {
        i += k;
        while (i < 10)
        {
            flag = (i & 1) == 0;
            if (flag)
            {
                int x = 20;
            }
            else
            {
                k++;
            }
            if (++i >= 7)
                break;
        }
        do
        {
            i--;
            if (i == 4)
                continue;
        } while (i == 0);
    }

    switch (i)
    {
    case 0:

        int h = 0;
        break;

    case 1:

        int y = 0;

        break;

    case 2:

        int z = 0;

        break;

    default:

        i++;
    }
    i += 2;
    i -= 1;
    i *= 3;
    i /= 2;
    i %= 5;
    i &= 1;
    i |= 2;
    i ^= 3;
    i <<= 1;
    i >>= 1;
    i = ~i;

    ch++;
    --ch;

    f -= 0.5;
    f *= 2.0;
    f /= 2.0;

    bool q = true;
    flag = !flag && !q || (i >= j);

    s += t;
    return add(i, j);
}
