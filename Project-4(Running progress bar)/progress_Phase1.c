#include <stdio.h>

const int Bar_Length =50;

int main() {
    int id = 3, progress = 50;
    int bars_to_show = (progress * Bar_Length)/100;
    printf("Task %d: [",id);
    // main code
    for(int i = 0; i < Bar_Length; i++){
        if(i < bars_to_show){
            printf("=");
        }else{
            printf(" ");
        }
    }
    printf("] %d%%",progress);
    return 0;
}