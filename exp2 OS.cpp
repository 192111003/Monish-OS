#include <stdio.h>

int main() {
    int frames[3], pages[8], faults = 0, frame_index = 0;
    int i, j, k, found;

    
    for (i = 0; i < 3; i++) {
        frames[i] = -1;
    }

    
    printf("Enter page reference sequence: ");
    for (i = 0; i < 8; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < 8; i++) {
        found = 0;
        
        for (j = 0; j < 3; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            frames[frame_index] = pages[i];
            frame_index = (frame_index + 1) % 3;
            faults++;
        }
        
        printf("Frames: ");
        for (k = 0; k < 3; k++) {
            if (frames[k] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[k]);
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", faults);
}
