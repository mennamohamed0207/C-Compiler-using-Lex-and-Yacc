int main() {
    int counter = 5;
    
    // Simple while
    while(counter > 0) {
        // printf("Count: %d", counter);
        int x=10;
        counter=counter-1;
    }

    // Nested while
    int i = 2;
    while(i > 0) {
        int j = 3;
        while(j > 0) {
            // printf("%d%d", i, j);
            int y=10;
            j=j-1;
        }
        i=i-1;
    }
    
    return 0;
}