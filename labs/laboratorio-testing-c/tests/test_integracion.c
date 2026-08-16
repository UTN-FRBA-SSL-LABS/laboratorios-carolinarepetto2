#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");

    Carrito c;
    carrito_init(&c);

    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};

    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);

    ASSERT_IGUAL(1300, carrito_total(&c));

    // 10% de descuento
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");

    Carrito c;
    carrito_init(&c);

    Producto p1 = {"Pan", 200, 1};
    Producto p2 = {"Leche", 350, 1};
    Producto p3 = {"Huevos", 500, 1};
    Producto p4 = {"Arroz", 300, 1};
    Producto p5 = {"Fideos", 250, 1};

    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    carrito_agregar(&c, p3);
    carrito_agregar(&c, p4);

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

    ASSERT_IGUAL(0, carrito_agregar(&c, p5));

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}


int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
