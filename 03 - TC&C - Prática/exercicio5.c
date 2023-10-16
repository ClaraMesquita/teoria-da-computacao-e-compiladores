#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUM_CITY 4

int aloc(int ***matrix);
void init_matrix(int **matrix);
void show_matrix(int **matrix);
int cityDistance(int **matrix, int city_a, int city_b, bool ac_city[NUM_CITY]);

int main(int argc, char const *argv[])
{
    int **city_matrix, city_a, city_b, distance;
    bool visited[NUM_CITY] = {false};

    aloc(&city_matrix);
    init_matrix(city_matrix);
    show_matrix(city_matrix);

    printf("\nInforme a primeira cidade ");
    scanf("%i", &city_a);
    printf("\nInforme a segunda cidade ");
    scanf("%i", &city_b);

    distance = cityDistance(city_matrix, city_a, city_b, visited);

    printf("\nDistancia entre as cidades = %i", distance);

    return 0;
}

void show_matrix(int **matrix)
{
    printf("\n\n");
    for (int i = -1; i < NUM_CITY; i++)
    {
        for (int j = -1; j < NUM_CITY; j++)
        {
            if (i == -1 && j == -1)
            {
                printf("    |");
            }
            else if (i == -1)
            {
                printf("%4d|", j);
            }
            else if (j == -1)
            {
                printf("%4d|", i);
            }
            else
            {
                printf("%4d|", matrix[i][j]);
            }
        }
        printf("\n");
        if (i == -1)
        {
            for (int j = 0; j < NUM_CITY + 1; j++)
            {
                printf("------");
            }
            printf("\n");
        }
    }
}

int aloc(int ***matrix)
{
    *matrix = (int **)calloc(NUM_CITY, sizeof(int *));
    if (*matrix == NULL)
    {
        return 0;
    }

    for (int i = 0; i < NUM_CITY; i++)
    {
        (*matrix)[i] = (int *)calloc(NUM_CITY, sizeof(int));
        if ((*matrix)[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free((*matrix)[j]);
            }
            free(*matrix);
            return 0;
        }
    }

    return 1;
}

void init_matrix(int **matrix)
{
    for (int i = 0; i < NUM_CITY; i++)
    {
        for (int j = 0; j < NUM_CITY; j++)
        {
            // Input para o exemplo do exercicio = 4 0 5 2 4 3
            if (i == j)
            {
                matrix[i][j] == 0;
            }
            else if (i > j)
            {
                matrix[i][j] = matrix[j][i];
            }
            else
            {
                printf("Distancia entre cidade %i e %i = ", i, j);
                scanf("%i", &matrix[i][j]);
            }
        }
    }
}

int cityDistance(int **matrix, int city_a, int city_b, bool ac_city[NUM_CITY])
{
    if (city_a == city_b)
    {
        return 0;
    }

    ac_city[city_a] = true; // Troca a cidade como visitada
    int minDistance = 0;

    for (int i = 0; i < NUM_CITY; i++)
    {
        if (!ac_city[i] && matrix[city_a][i] != 0)
        {
            int currentDistance = matrix[city_a][i] + cityDistance(matrix, i, city_b, ac_city);
            if (currentDistance < minDistance || minDistance == 0)
            {
                minDistance = currentDistance;
            }
        }
    }

    return minDistance;
}
