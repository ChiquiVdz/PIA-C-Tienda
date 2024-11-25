#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

// ESTRUCTURA
struct registro
{
    int num;
    char nom[30];
    int cant;
    float cost;
    char dis[30];
    int est;
} producto[50];

struct venta
{
    int nume;
    char nomb[30];
    int cantid;
    float costo;
    float tot_t;
} ticket[50];

// DECLARACION
int lec();
int menu();
int agg();
int del();
int camb();
int ven();
int rep();
int rep_gral();
int rep_ven();
int man();

// VARIABLES
int n = 0;
int t = 0;

// LECTURA DE REGISTRO
int lec()
{
    FILE *fp;
    fp = fopen("REGISTRO DE VENTAS.txt", "r");

    if (fp == NULL)
    {
        printf("\n\tERROR AL LEER REGISTRO\n");
        exit(1);
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d ", &producto[n].num);
            fscanf(fp, "%s ", &producto[n].nom);
            fscanf(fp, "%d ", &producto[n].cant);
            fscanf(fp, "%f ", &producto[n].cost);
            fscanf(fp, "%s ", &producto[n].dis);
            fscanf(fp, "%d ", &producto[n].est);
            n++;
        }
        printf("\nRegistro Leido Correctamente");
    }

    fclose(fp);
}

// MENU
int menu()
{
    char val;
    int menu = 0;

    while (menu == 0)
    {
        printf("\n\n\t Hola!!");
        printf("\n\t Bienvenido al menu!! \n");

        printf("\n 1 - Nuevo Producto");
        printf("\n 2 - Borrado de Producto");
        printf("\n 3 - Cambio de Producto");
        printf("\n 4 - Venta de Producto");
        printf("\n 5 - Reporte de Productos");
        printf("\n 6 - Manual de Usuario");
        printf("\n 7 - Salir \n");

        printf("\n Seleccione la opcion que desea: ");
        val = getche();

        switch (val)
        {
        case '1':
            // Nueva Producto
            agg();
            break;

        case '2':
            // Borrado de Producto
            del();
            break;

        case '3':
            // Cambio de Producto
            camb();
            break;

        case '4':
            // Venta de Producto
            ven();
            break;

        case '5':
            // Reporte de Productos
            rep();
            break;

        case '6':
            // Manual de Usuario
            man();
            break;

        case '7':
            // Salir
            printf("\n\nGracias!! Hasta luego!!\n");
            menu++;
            break;

        default:
            printf("\n\nOpcion no valida\n");
        }
    }
}

// NUEVO PRODUCTO
int agg()
{
    printf("\n\n\tNuevo Producto");

    int v;

    do
    {
        v = 0;
        printf("\n\nIngresa el numero del producto o '0' para salir: ");
        scanf("%d", &producto[n].num);

        if (producto[n].num == 0)
        {
            return 0;
        }
        for (int c = 0; c < n; c++)
        {
            if (producto[n].num == producto[c].num)
            {
                printf("\nYa esta en uso");
                v = 1;
            }
        }
    } while (v == 1);

    printf("\nIngresa el nombre del producto: ");
    scanf("%s", &producto[n].nom);

    printf("\nIngresa la cantidad del producto: ");
    scanf("%d", &producto[n].cant);

    printf("\nIngresa el costo del producto: ");
    scanf("%f", &producto[n].cost);

    printf("\nIngresa el distribuidor del producto: ");
    scanf("%s", &producto[n].dis);

    producto[n].est = 1;

    n++;

    printf("\nProducto Agregado Correctamente");
}

// ELIMINAR
int del()
{
    int el;
    int q = 123;

    printf("\n\n\tEliminar Producto");

    printf("\n\nIngrese el codigo del producto a borar: ");
    scanf("%d", &el);

    for (int z = 0; z < n; z++)
    {
        if (el == producto[z].num)
        {
            producto[z].est = 0;
            q++;
            printf("\nProducto Eliminado Correctamente");
        }
    }

    if (q == 123)
    {
        printf("\nEl Producto no existe");
    }
}

// CAMBIO
int camb()
{
    int cb;
    int bc = 456;
    char s;

    printf("\n\n\tCambio de Producto");

    printf("\n\nIngrese el codigo del producto a cambiar: ");
    scanf("%d", &cb);

    for (int y = 0; y < n; y++)
    {
        if (cb == producto[y].num)
        {
            printf("\nNumero: %d", producto[y].num);
            printf("\n1 - Nombre: %s", producto[y].nom);
            printf("\n2 - Cantidad: %d", producto[y].cant);
            printf("\n3 - Costo: %.2f", producto[y].cost);
            printf("\n4 - Distribuidor: %s", producto[y].dis);

            printf("\n\nQue desea cambiar? ");
            s = getche();

            switch (s)
            {
            case '1':
                printf("\n\nIngrese el nuevo nombre: ");
                scanf("%s", &producto[y].num);
                printf("\n\nProducto Cambiado Correctamente");
                break;

            case '2':
                printf("\n\nIngrese la nueva cantidad: ");
                scanf("%d", &producto[y].cant);
                printf("\n\nProducto Cambiado Correctamente");
                break;

            case '3':
                printf("\n\nIngrese el nuevo costo: ");
                scanf("%f", &producto[y].cost);
                printf("\n\nProducto Cambiado Correctamente");
                break;

            case '4':
                printf("\n\nIngrese el nuevo distribuidor: ");
                scanf("%s", &producto[y].dis);
                printf("\n\nProducto Cambiado Correctamente");
                break;

            default:
                printf("\n\nOpcion no Valida");
                break;
            }

            bc++;
        }
    }

    if (bc == 456)
    {
        printf("\nEl Producto no existe");
    }
}

// VENTAS
int ven()
{
    int vt;
    int tv = 789;
    int res;
    float tot;

    printf("\n\n\tVentas");

    printf("\n\nIngrese el codigo del producto: ");
    scanf("%d", &vt);

    for (int x = 0; x < n; x++)
    {
        if (vt == producto[x].num)
        {
            if (producto[x].est == 1 && producto[x].cant > 0)
            {
                printf("\n\nProducto: %s", producto[x].nom);
                printf("\nCosto: %.2f", producto[x].cost);
                printf("\nCantidad: %d", producto[x].cant);

                printf("\n\nCuantos desea comprar? ");
                scanf("%d", &res);

                tot = (producto[x].cost * res);
                producto[x].cant = (producto[x].cant - res);

                printf("\n\n\tTICKET");
                printf("\nCodigo: %d", producto[x].num);
                printf("\nProducto: %s", producto[x].nom);
                printf("\nCosto: %.2f", producto[x].cost);
                printf("\nTOTAL: %.2f", tot);

                // struct ven
                ticket[t].nume = producto[x].num;
                strcpy(ticket[t].nomb, producto[x].nom);
                ticket[t].cantid = res;
                ticket[t].costo = producto[x].cost;
                ticket[t].tot_t = tot;

                t++;

                printf("\n\nProducto Vendido Correctamente");

                tv++;
            }
        }
    }
    if (tv == 789)
    {
        printf("\n\nEl Producto no existe");
    }
}

// REPORTE
int rep()
{
    char op_r;

    printf("\n\n\tReportes\n");

    printf("\n1 - Reporte General");
    printf("\n2 - Reporte Ventas del Dia");
    printf("\n3 - Salir");

    printf("\n\n Ingrese la opcion que desea: ");
    op_r = getche();

    switch (op_r)
    {
    case '1':
        rep_gral();
        break;

    case '2':
        rep_ven();
        break;

    case '3':
        return 0;
        break;

    default:
        printf("\nOpcion no valida");
        break;
    }
}

// REPORTE GRAL
int rep_gral()
{
    FILE *fp;
    fp = fopen("REGISTRO DE VENTAS.txt", "w");

    if (fp == NULL)
    {
        printf("\n\tERROR AL LEER REGISTRO\n");
        exit(1);
    }
    else
    {
        for (int g = 0; g < n; g++)
        {
            if (producto[g].est == 1)
            {
                fprintf(fp, "%d ", producto[g].num);
                fprintf(fp, "%s ", producto[g].nom);
                fprintf(fp, "%d ", producto[g].cant);
                fprintf(fp, "%f ", producto[g].cost);
                fprintf(fp, "%s ", producto[g].dis);
                fprintf(fp, "%d ", producto[g].est);
                fprintf(fp, "\n");
            }
        }
    }
    fclose(fp);
}

// REPORTE VEN
int rep_ven()
{
    float totot;

    FILE *fp;
    fp = fopen("VENTAS.txt", "w");

    if (fp == NULL)
    {
        printf("\n\tERROR AL LEER REGISTRO\n");
        exit(1);
    }
    else
    {
        for (int g = 0; g < t; g++)
        {
            fprintf(fp, "%d ", ticket[g].nume);
            fprintf(fp, "%s ", ticket[g].nomb);
            fprintf(fp, "%d ", ticket[g].cantid);
            fprintf(fp, "%.2f ", ticket[g].costo);
            fprintf(fp, "%f ", ticket[g].tot_t);
            fprintf(fp, "\n");

            totot = totot + ticket[g].tot_t;
        }

        fprintf(fp, "INGRESO TOTAL: %.2f", totot);
    }
    fclose(fp);
}

// MANUAL
int man()
{
    int u;

    printf("\n\n\tManual de Usario\n");

    printf("\n 1 - Nuevo Producto");
    printf("\n 2 - Borrado de Producto");
    printf("\n 3 - Cambio de Producto");
    printf("\n 4 - Venta de Producto");
    printf("\n 5 - Reporte de Productos");
    printf("\n 6 - Salir");

    printf("\n\nSeleccione el manual de la funcion que necesite: ");
    u = getche();

    switch (u)
    {
    case '1':
        printf("\n\nNuevo Producto");
        printf("\nEsta opcion lo que permite es almacenar una nueva cantidad de datos que se almacenaran en cierta posicion del arreglo ya predispuesto por el inventario de los productos, para el cual se utilizara una cierta estructura ya predefinida por el programa, se ingresan los datos de numero, nombre, cantidad, precio y distribuidor del producto.");
        break;

    case '2':
        printf("\n\nBorrado de Producto");
        printf("\nAqui lo que se hace con esta funcion es eliminar una posicion del arreglo en el que se almacenan todos los productos existentes en el inventario.");
        break;

    case '3':
        printf("\n\nCambio de Producto");
        printf("\nEn el cambio de producto la funcion esta preparada para hacer un cambio en una cierta posición del arreglo que contiene los productos del inventario, habilitando la opción para modificar el numero del producto, la cantidad de productos existentes, el nombre, el distribuidor, asi como el precio que tiene.");
        break;

    case '4':
        printf("\n\nVenta de Producto");
        printf("\nLa opcion nombrada venta de producto permite al usuario vender un producto, que modifica en arreglo de los productos existentes en el inventario.");
        break;

    case '5':
        printf("\n\nReporte de Productos");
        printf("\nEsta opcion lo que hace es darte a escoger entre dos opciones, una es imprimir el reporte general, y otra que es imprimir el reporte de las ventas del dia.");
        break;

    case '6':
        printf("\n\nSalir");
        printf("\nEsta opcion es dar fin al programa.");
        break;

    default:
        printf("\n\nOpcion no valida\n");
        break;
    }
}