#include <stdio.h>
#include <stdlib.h>

struct point {
    float x;
    float y;
};

int sort_get_index(float tab[], int top, float val)   {
    for (int i = 0; i <= top; i++)   {
        if (tab[i] > val) {
            return i;
        }
    }
    return top;
}

void sort_insert_at(float tab[], int i, int top, float val)    {
    for (int j = top; j > i; j--)  {
        tab[j] = tab[j - 1];
    }
    tab[i] = val;
}

void sort_insert(float tab[], int top, float val)    {
    int ind = sort_get_index(tab, top, val);
    sort_insert_at(tab, ind, top, val);
}

int nb_columns()    {
    return 32;
}

int nb_lines()  {
    return 16;
}

void grid_init(char grid[nb_lines()][nb_columns()], char pixel) {
    for (int row = 0; row < nb_lines(); row++)    {
        for (int col = 0; col < nb_columns(); col++)    {
            grid[row][col] = pixel;
        }
    }
}

void grid_display(char grid[nb_lines()][nb_columns()])  {
    for (int row = 0; row < nb_lines(); row++)  {
        for (int col = 0; col < nb_columns(); col++)    {
            printf("%c", grid[row][col]);
        }
        printf("\n");
    }
}

void plot_point(char grid[nb_lines()][nb_columns()], int x, int y, char pixel)  {
    if (x >= nb_columns() || y >= nb_lines() || x < 0 || y < 0)   exit(EXIT_FAILURE);
    grid[nb_lines() - y - 1][x] = pixel;
}

void plot_vline(char grid[nb_lines()][nb_columns()], int x, float fy0, float fy1, char pixel)   {
    int y0 = fy0 + 0.5, y1 = fy1 + 0.5;
    if (fy0 == y0 - 0.5)    y0--;
    if (fy1 == y1 - 0.5)    y1--;
    for (int i = y0; i <= y1; i++)  {
        grid[nb_lines() - i - 1][x] = pixel;
    }
}

void plot_poly_sweep(char grid[nb_lines()][nb_columns()], struct point p[], int nb_pts, int x, char pixel)    {
    float vlines[nb_pts * 4];
    int top = 0;

    printf("sweep %d: ", x);
    int j = nb_pts - 1;
    for (int i = 0; i < nb_pts; i++)    {
        if ((x >= p[i].x && x <= p[j].x) || (x >= p[j].x && x <= p[i].x))    {
            float intersect = p[i].y + (x - p[i].x) * (p[j].y - p[i].y) / (p[j].x - p[i].x);
            sort_insert(vlines, top, intersect);
            top += 1;
        }
        j = i;
    }
    for (int j = 0; j < top; j+= 2)   {
        printf("%f ", vlines[j]);
        if (j < top - 1)    {
            plot_vline(grid, x, vlines[j], vlines[j + 1], pixel);
        }
    }
    printf("\n");
}

void plot_poly(char grid[nb_lines()][nb_columns()], struct point points[], int nb_pts, char pixel)    {
    for (int x = 0; x < nb_columns(); x++)    {
        plot_poly_sweep(grid, points, nb_pts, x, pixel);
    }
}

int main(int argc, char* argv[])    {
    char grid[nb_lines()][nb_columns()];
    struct point p[] = {{2, 13}, {10, 13}, {30, 7}, {10, 1}, {2, 1}, {18, 7}};
    int nb_pts = 6;
    grid[0][0] = '*';
    grid_init(grid, ' ');
    plot_poly(grid, p, nb_pts, '-');
    grid_display(grid);
    printf("%d %d\n", nb_columns(), nb_lines());
    return 0;
}