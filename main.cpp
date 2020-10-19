#include <iostream>
#include <unistd.h>;
using namespace std;

int main(int argc, char** argv)
{
  char *cvalue = NULL;
  int index;
  int c;

  while ((c = getopt(argc, argv, "abc:")) != -1)
    switch (c)
      {
      case 'c':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  printf ("cvalue = %s\n", cvalue);
  return 0;
}