int main() {
    int num = 5;
    
    do {
        // printf("Number: %d", num);
        num=num-1;
    } while(num > 0);

    // Will execute once even if false
    int flag = 0;
    do {
        // printf("This will print once");
        string s = "Hello";
    } while(flag == 1);
    
    return 0;
}