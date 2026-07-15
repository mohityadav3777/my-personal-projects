#include <stdio.h>

const int Bar_Length =50;
void print_bar(int id, int progress);
int main() {
    int id = 3, progress = 50;
    print_bar(1,10);
    print_bar(2,30);
    print_bar(id,progress);
    print_bar(4,70);
    print_bar(5,100);
    return 0;
}

void print_bar(int id, int progress){
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
    printf("] %d%%\n",progress);
}