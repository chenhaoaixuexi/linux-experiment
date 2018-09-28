  /*
 * =====================================================================================
 *
 *       Filename:  getitime.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/26/18 20:37:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
int main(){
  char temp1 [10] = {'a'};
  char * temp2 = (char *)calloc(10,1);
  for (size_t i = 0; i < 10; i++) {
    temp2[i]='b';
  }
  printf("%s\n", temp1);
  printf("%s\n", temp2);
}
