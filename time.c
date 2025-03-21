#include <stdio.h>
#include <time.h>

int main() {
    char name[50];
    time_t t;
    struct tm *current_time;

    printf("Hello! Enter Name Here: ");
    scanf("%49s", name);  // %49s prevents buffer overflow

    // Get current time
    t = time(NULL);
    current_time = localtime(&t);
    int hour = current_time->tm_hour;

    // Determine greeting based on the hour
    if (hour >= 5 && hour < 12) {
        printf("Good Morning, %s!\n", name);
    } else if (hour >= 12 && hour < 17) {
        printf("Good Afternoon, %s!\n", name);
    } else {
        printf("Good Night, %s!\n", name);
    }

    // Print the current time in HH:MM:SS AM/PM format
    printf("The current time is: %02d:%02d:%02d %s\n",
           (hour % 12 == 0) ? 12 : hour % 12, // Convert 24-hour to 12-hour format
           current_time->tm_min,
           current_time->tm_sec,
           (hour < 12) ? "AM" : "PM");

    return 0;
}
