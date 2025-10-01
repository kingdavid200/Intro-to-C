#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2){
        printf("Usage: %s <test_number>\n", argv[0]);
        return 1;
    }
    int test_number = atoi(argv[1]);
    printf("DEBUG: test_number = %d, argc = %d\n", test_number, argc);
    
    if (test_number == 1){
        int sum = 0;
for (int i = 0; i < 1000; i++){
    int random_number = (int)(10.0 * rand() / ( RAND_MAX + 1.0));
    sum += random_number;
}
float avg = sum / 1000.0;
printf("The average is %.1f\n", avg);
printf("\n");
}
else if (test_number == 2){
    int counts[10];
    for (int i = 0; i<10; i++){
        counts[i]=0;
    }
    for(int i=0; i<10000; i++){
        int random_number = (int)(10.0 * rand() / ( RAND_MAX + 1.0));
        counts[random_number]++;
    }
    for (int i = 0; i < 10; i++) {
        float percentage = (counts[i] / 10000.0) * 100;
        printf("Digit %d: %.2f%%\n", i, percentage);
        printf("\n");
        
    }
}


else if (test_number == 3){
    int counts[100];

    for (int i = 0; i< 100; i++){
        counts[i] = 0;
    }
    for (int i = 0; i<10000; i++){
        int num1 = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        int num2 = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        int pair = num1 * 10 + num2;
        counts[pair]++;
    }
    for (int i = 0; i<100; i++){
        float percentage = (counts[i] / 10000.0) * 100;
        printf("Pair %02d: %.2f%%\n", i, percentage);
        printf("\n");
    }
    }

else if (test_number == 4){

    int all_same = 0;
    int three_same = 0;
    int two_pairs = 0;
    int one_pair = 0;
    int none_identical = 0;

for (int i = 0; i < 1000; i++) {
    int firstnum = (int)(10.0 * rand() / (RAND_MAX + 1.0));
    int secondnum = (int)(10.0 * rand() / (RAND_MAX + 1.0));
    int thirdnum = (int)(10.0 * rand() / (RAND_MAX + 1.0));
    int fourthnum = (int)(10.0 * rand() / (RAND_MAX + 1.0));


    int freq[10] = {0};
    freq[firstnum]++;
    freq[secondnum]++;
    freq[thirdnum]++;
    freq[fourthnum]++;


    /*for checking parameters*/
    int has_four = 0, has_three = 0, has_two = 0;
        for (int j = 0; j < 10; j++) {
            if (freq[j] == 4) has_four = 1;
            if (freq[j] == 3) has_three = 1;
            if (freq[j] == 2) has_two++;

        }
        if (has_four) {
            all_same++;
        } else if (has_three) {
            three_same++;
        } else if (has_two == 2) {
            two_pairs++;
        } else if (has_two == 1) {
            one_pair++;
        } else {
            none_identical++;
        }

    }
    printf("All same: %d\n", all_same);
    printf("Three same: %d\n", three_same);
    printf("Two pairs: %d\n", two_pairs);
    printf("One pair: %d\n", one_pair);
    printf("None identical: %d\n", none_identical);
    printf("\n");

    }


else if (test_number == 5) {
/*make file*/
    FILE *file = fopen("random_digits.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    for (int i = 0; i < 1000; i++) {
        int d1 = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        int d2 = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        int d3 = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        int d4 = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        fprintf(file, "%d %d %d %d\n", d1, d2, d3, d4);
    }
    fclose(file);
    
    /*check file*/
    file = fopen("random_digits.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int all_same = 0, three_same = 0, two_pairs = 0, one_pair = 0, none_identical = 0;
    
    for (int i = 0; i < 1000; i++) {
        int firstnum, secondnum, thirdnum, fourthnum;
        fscanf(file, "%d %d %d %d", &firstnum, &secondnum, &thirdnum, &fourthnum);
        
        int freq[10] = {0};
        freq[firstnum]++;
        freq[secondnum]++;
        freq[thirdnum]++;
        freq[fourthnum]++;
        
        int has_four = 0, has_three = 0, has_two = 0;
        for (int j = 0; j < 10; j++) {
            if (freq[j] == 4) has_four = 1;
            if (freq[j] == 3) has_three = 1;
            if (freq[j] == 2) has_two++;
        }
        
        if (has_four) all_same++;
        else if (has_three) three_same++;
        else if (has_two == 2) two_pairs++;
        else if (has_two == 1) one_pair++;
        else none_identical++;
    }
    fclose(file);
    
    printf("All same: %d\n", all_same);
    printf("Three same: %d\n", three_same);
    printf("Two pairs: %d\n", two_pairs);
    printf("One pair: %d\n", one_pair);
    printf("None identical: %d\n", none_identical);
}
return 0;
}


    





