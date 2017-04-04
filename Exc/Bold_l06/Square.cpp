#include "Square.h"

void Square::Draw () const
{
  // Prints a square in the screen using # symbols.
  // f_WIDTH and f_HEIGHT denote size of the printable area, which is fixed for all figures 

  using namespace std;
    
  for (pos_t i = 0; i < f_WIDTH; ++i)
    cout<<"-";
  cout<<"\n";

  const pos_t top_margin = f_HEIGHT - f_size - f_y;
  for (pos_t i = 0; i < top_margin; ++i)
    cout<<"\n";
    
  for (pos_t i = 0; i < f_size; ++i) {
    for (pos_t j = 0; j < f_x; ++j)
      cout<<" ";

    for (pos_t j = 0; j < f_size; ++j)
      cout<<"#";

    cout<<"\n";
  }

  for (pos_t i = 0; i < f_y; ++i)
    cout<<"\n";

  for (pos_t i = 0; i < f_WIDTH; ++i)
    cout<<"-";
  cout<<"\n";
}
