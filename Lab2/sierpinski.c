#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[])    {
    char grid[nb_lines()][nb_columns()];
    grid[0][0] = '*';
    grid_init(grid, ' ');
    // plot_point(grid, 3, 1, ' ');
    plot_vline(grid, 1, 2, 3, '|');
    plot_vline(grid, 2, 1.7, 3.3, '|');
    plot_vline(grid, 3, 1.2, 3.8, '|');
    plot_vline(grid, 7, 0.5, 1.5, '|');
    grid_display(grid);
    printf("%d %d\n", nb_columns(), nb_lines());
    return 0;
}