int main()
{
    int x = 5;
    int y = 10;
    int z = 15;

    // Test postfix increment
    int a = x++; // a should be 5, x becomes 6
    int b = y--; // b should be 10, y becomes 9

    // Test prefix increment
    int c = ++x; // x becomes 7, c should be 7
    int d = --y; // y becomes 8, d should be 8

    // Test multiple increments in expressions
    int e = x++ + ++y; // e should be 7 + 9 = 16, x becomes 8, y becomes 9
    int f = --z + z--; 

    return 0;
}