#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define HEIGHT 25
#define WIDTH 80

#define function x
 

void print_graph() {
	int **field = (int **)malloc(HEIGHT * sizeof(int*));
	for(int i = 0; i < HEIGHT; i++) 
		field[i] = (int *)malloc(WIDTH * sizeof(int));
	
	float width_pen = 0.05;

	float aspect = (float)WIDTH / HEIGHT;
	float pixelaspect = 11.0f / 24.0f;

	float xmin = M_PI;
    float xmax = -M_PI;
    float ymin = -1.0;
    float ymax = 1.0;

    float xstep = (xmax - xmin) / WIDTH;
    float ystep = (ymax - ymin) / HEIGHT;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			float x = xmin + j * xstep;
            float y = ymin + i * ystep;
            x *= aspect * pixelaspect;

            if (fabs(y - (function)) * aspect * pixelaspect < width_pen)
                field[i][j] = 1;
            else
                field[i][j] = 0;
		}
	}

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (field[i][j] == 1) 
				printf("#");
			else 
				printf("-");
		}
		printf("\n");
	}
	for (int i = 0; i < HEIGHT; i++)
        free(field[i]);
    free(field);
}

int main() {
	print_graph();
	getchar();

}
