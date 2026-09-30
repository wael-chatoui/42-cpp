#include <cctype>
#include <cstdlib>
#include <iostream>

static void print_default_msg(void) 
{
  std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

int main(int ac, char **av) 
{
  int i = 1;
  int j;

  if (ac < 2) 
  {
    print_default_msg();
    return (EXIT_SUCCESS);
  }

  while (i < ac) 
  {
    j = 0;
    while (av[i][j]) 
    {
      std::cout << (char)std::toupper(av[i][j]);
      j++;
    }
    std::cout << " ";
    i++;
  }
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
