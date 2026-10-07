#include <stdio.h>

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
    grid[nb_lines() - y - 1][x] = pixel;
}
int main(float argc, char* argv[])    {
    char grid[nb_lines()][nb_columns()];
    grid[0][0] = '*';
    grid_init(grid, '*');
    plot_point(grid, 3, 1, ' ');
    grid_display(grid);
    printf("%d %d\n", nb_columns(), nb_lines());
    return 0;
}