#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
// this file gives sleep function which updates ui acc. to our prefered time
const int Bar_Length = 60;
const int MAX_TASKS = 5;
 typedef struct {
    int id;
    int progress;
    int steps;
}Task;

void print_bar(Task tasks);
void clear_screen();

int main() {
    srand(time(NULL));
    Task tasks [MAX_TASKS];
    for(int i = 0; i < MAX_TASKS; i++){
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        // initially sabki progress 0 hi hogi
        tasks[i].steps = rand() % 5 + 1; // randomly gives value between 1 - 5
    }
    int tasks_incomplete = 1; // we are assuming initially tasks are incomplete
    while(tasks_incomplete){
        tasks_incomplete = 0; // first iteration me we assume are tasks are completed
        // so that to check each time through each iteration
        clear_screen();
        // it will clear screen so that the ui looks static and non increasing
         for(int i = 0; i < MAX_TASKS; i++){
            tasks[i].progress += tasks[i].steps;
            if(tasks[i].progress > 100){
                tasks[i].progress = 100;
            }else if(tasks[i].progress < 100){
                tasks_incomplete = 1;
            }
           
            print_bar(tasks[i]);
        }
        
        sleep(1); // sleep for one second
    }
    printf("All Tasks Are Completed!\n");
    return 0;
}

void clear_screen(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void print_bar(Task tasks){
    int bars_to_show = (tasks.progress * Bar_Length)/100;
    if(tasks.id < 10){
        printf("Task %d: [",tasks.id);
    }else{
        printf("Task %d:[",tasks.id);
    }
    // main code
    for(int i = 0; i < Bar_Length; i++){
        if(i < bars_to_show){
            printf("=");
        }else{
            printf(" ");
        }
    }
    printf("] %d%%\n",tasks.progress);
}