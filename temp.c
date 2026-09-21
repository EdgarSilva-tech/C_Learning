#include <stdio.h>

/* print Farenheit-Celsius table
 * for fahr = 0,20, ..., 300 */

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0; /* lower limit of temperature scale */
  upper = 300; /* upper limit */
  step = 20; /* step size */

  /*fahr = lower;
  printf("FAHR CELSIUS\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);

    fahr = fahr + step;
  }*/
  celsius = lower;
  printf("CELSIUS FAHR\n");
  while (celsius <= upper) {
    fahr = (celsius * 9/5) + 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;

  }
    
  return 0;
}
