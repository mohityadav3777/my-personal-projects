#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// this file gives sleep function which updates ui acc. to our prefered time
const int Bar_Length =50;
const int MAX_TASKS = 5;
 typedef struct {
    int id;
    int progress;
    int steps;
}Task;

void print_bar(Task tasks);


int main() {
    Task tasks [MAX_TASKS];
    for(int i = 0; i < MAX_TASKS; i++){
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        // initially sabki progress 0 hi hogi
        tasks[i].steps = 3; // initially 3 - 3 karke bar increase hoga
    }
    int tasks_incomplete = 1; // we are assuming initially tasks are incomplete
    while(tasks_incomplete){
        tasks_incomplete = 0; // first iteration me we assume are tasks are completed
        // so that to check each time through each iteration
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


void print_bar(Task tasks){
    int bars_to_show = (tasks.progress * Bar_Length)/100;
    printf("Task %d: [",tasks.id);
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