#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("REGISTRO DE VENTAS.txt", "w");

    int count = 30;
    char temp[50];

    if (fp == NULL)
    {
        printf("\n\tERROR AL LEER REGISTRO\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("\n\tProducto: %d", i + 1);

            printf("\nIngrese la clave del producto: ");
            scanf("%s", temp);
            fprintf(fp, "%s ", temp);

            printf("\nIngrese el nombre del producto: ");
            scanf("%s", temp);
            fprintf(fp, "%s ", temp);

            printf("\nIngrese la cantidad de producto: ");
            scanf("%s", temp);
            fprintf(fp, "%s ", temp);

            printf("\nIngrese el precio del producto: ");
            scanf("%s", temp);
            fprintf(fp, "%s ", temp);

            printf("\nIngrese el provedor del producto: ");
            scanf("%s", temp);
            fprintf(fp, "%s ", temp);

            fprintf(fp, "1 ");

            fprintf(fp, "\n");
        }
    }

    fclose(fp);

    return 0;
}