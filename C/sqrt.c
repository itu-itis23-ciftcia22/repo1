#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {

  double g=1;
  int x;
  double ig = 0;
  double threshold = 1e-4;
  double fark = 2 * threshold;


  printf("Hangi tam sayinin karekokunu hesaplamak istersiniz: ");
  scanf("%d", &x);

  int asama = 1;

  do
  {
      ig = (g + x/g) / 2;
      printf("Iteration: %d - Current guess: %.3lf  improved guess: %.3lf\n",asama,g,ig);
      g = ig;
      fark = fabs(g*g - x);
      asama++;
  } while(fark>=threshold);

  printf("%d sayisinin karekoku %.3lf",x, g);

  return 0;
}
