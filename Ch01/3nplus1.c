#include <stdio.h>

int calc_cycle_length(int n){
    int count = 1;
    while (n != 1){
        count++;
        if (n%2==0){
            n/=2;
        }
        else{
            n = 3*n + 1;
        }
    }
    return count;    
}

int find_longest_cycle(int start, int end){
    int largest_cycle = 0, cycle = 0, n;

    for (n = start; n < end+1; n++){
        cycle = calc_cycle_length(n);
        if (cycle > largest_cycle){
            largest_cycle = cycle;
        }
    }
    return largest_cycle;
}


int main(void)
{   
    /*
    test inputs 
    int starts[4] = {1, 100, 201, 900};
    int ends[4] = {10, 200, 210, 1000};
    int largest = 0;
    for (int i = 0; i < 4; i++){
        largest = find_longest_cycle(starts[i], ends[i]);
        printf("%d %d %d\n", starts[i], ends[i], largest);
    }
    */

    int start, end, largest;
    while (scanf("%d %d", &start, &end) == 2)
    {
        largest = find_longest_cycle(start, end);
        printf("%d %d %d\n", start, end, largest);
    }

    return 0;
}