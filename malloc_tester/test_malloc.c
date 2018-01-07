/*
** main.c for  in /home/hazer/PSU_2016_malloc/test_proj
**
** Made by hazer
** Login   <david.munoz@epitech.eu>
**
** Started on  Tue Jan 31 12:05:00 2017 hazer
** Last update Fri Feb 10 15:29:33 2017 hazer
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>

int main() {

  int nombre = 0;
  int *tableau = NULL;
  int x = 0;

  printf ("Veuillez entrer la taille du tableau : ");
  scanf ("%d", &nombre);

  tableau = malloc(sizeof(int) * nombre);

  for (x = 0; x < nombre; ++x) {
    printf ("Veuillez entrer un nombre : ");
    scanf ("%d", &tableau[x]);
  }

  for (x = 0; x < nombre; ++x) {
    printf ("Nombre %d : %d\n", (x + 1), tableau[x]);
  }
  printf("tableau[nombre=%d]:%d\n", nombre, tableau[nombre]);
  printf("tableau[nombre=%d]:%d\n", nombre-1, tableau[nombre-1]);
  tableau = realloc(tableau, sizeof(int) * (nombre + 1));
  printf("realloc tableau[nombre=%d]:%d\n", nombre, tableau[nombre]);
  tableau[nombre] = 100;
  printf("tableau[nombre=%d]:%d\n", nombre, tableau[nombre]);

  for (x = 0; x < nombre + 1; ++x)
    {
      printf ("Nombre %d : %d\n", (x + 1), tableau[x]);
    }
  free(tableau);
  return 0;
}
