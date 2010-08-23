#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include "libarduino2.h"
#include "sensor.h"

typedef enum {
    MODE_MENU,
    MODE_FOLLOW,
    MODE_TRAIN
} mode_t;

int main(void) {
    mode_t mode = MODE_MENU;
    char cmd[16];

    sensor_init();
    serial_init();

    for (;;)
    switch (mode) {
    case MODE_MENU:
        /* Prompt the user for a command. */
        printf(" >>> ");
        readline(cmd, cmd + sizeof(cmd));

        /* Calibrate the line following sensors. */
        if (!strcmp(cmd, "line")) {
            sensor_line();
            printf("Line calibration complete.\n");
        } else if (!strcmp(cmd, "floor")) {
            sensor_floor();
            printf("Floor calibration complete.\n");
        }
        /* Follow the line with a machine learning algorithm. */
        else if (!strcmp(cmd, "follow")) {
            mode = MODE_FOLLOW;
        } else if (!strcmp(cmd, "train")) {
            mode = MODE_TRAIN;
        }
        /* Unrecognized command. */
        else {
            printf("Unrecognized command.\n");
        }
        break;

    case MODE_FOLLOW:
        break;

    case MODE_TRAIN:
        break;
    }
}
