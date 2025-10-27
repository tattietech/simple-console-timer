#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#endif

bool get_options(int argc, char *argv[], int *h, int *m, int *s);
void send_beep();
void print_time(int total_seconds);
void wait_one_second();

int main(int argc, char *argv[]) {
    int seconds = 0;
    int minutes = 0;
    int hours = 0;

    // default to 25 minute timer if no args provided
    if (argc == 1 || !get_options(argc, argv, &hours, &minutes, &seconds)) {
        minutes = 25;
    }

    // convert h,m,s to seconds to simplify counting
    int total_seconds = hours * 3600 + minutes * 60 + seconds;

    while(total_seconds > 0) {
        print_time(total_seconds);
        total_seconds--;
        
        wait_one_second();
    }

    printf("\rTimer finished!\n");
    send_beep();
    return 0;
}

// Get -h -m and -s args and set the hours minutes and seconds accordingly
// return false if no correct options are set, if non int is set it just
// defaults to 0
bool get_options(int argc, char *argv[], int *h, int *m, int *s) {
    int response = false;

    for(int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 && i+1 < argc) {
            *h = atoi(argv[i+1]);
            response = true;
        }
        else if (strcmp(argv[i], "-m") == 0 && i+1 < argc) {
            *m = atoi(argv[i+1]);
            response = true;
        }
        else if (strcmp(argv[i], "-s") == 0 && i+1 < argc) {
            *s = atoi(argv[i+1]);
            response = true;
        }
    }

    return response;
}

// send 3 beeps on timer completion
void send_beep() {
    for(int i =0; i<3; i++) {
        #ifdef _WIN32
            Beep(700, 800);
            Sleep(800);
        #elif __linux__
            fprintf(stdout, "\aBeep!\n" );
            sleep(1);
        #endif
    }
}

// print timer out to console
void print_time(int total_seconds) {
        int h = total_seconds / 3600;
        int m = (total_seconds % 3600) / 60;
        int s = total_seconds % 60;

        printf("\r%02d:%02d:%02d", h, m, s);
        fflush(stdout);
}

void wait_one_second() {
        #ifdef _WIN32
            Sleep(1000);
        #elif __linux__
            sleep(1);
        #endif
}

