int main() {
    // Standard for loop
    for(int i = 0; i < 5; i=i+1) {
        printf("Iteration: %d", i);
    }

    // For loop with complex condition
    for(int x = 0,int y=0; y = 10, x < y; x=x+1, y=y-1) {
        printf("X: %d, Y: %d", x, y);
    }
    
    return 0;
}