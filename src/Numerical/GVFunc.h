//____________________________________________________________________________
/*!

\class    genie::GVFunc

\brief    GENIE vector function ABC

\author   Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
          CCLRC, Rutherford Appleton Laboratory

\created  July 01, 2004

*/
//____________________________________________________________________________

#ifndef _GENIE_VECTOR_FUNCTION_H_
#define _GENIE_VECTOR_FUNCTION_H_

#include <vector>

#include "Numerical/GFunc.h"

using std::vector;

namespace genie {

class GVFunc : public GFunc
{
public:
  virtual ~GVFunc();
  virtual vector<double> operator () (const vector<double> & x) = 0;

protected:
  GVFunc(unsigned int nds);
};

}        // genie namespace
#endif   // _GENIE_VECTOR_FUNCTION_H_

