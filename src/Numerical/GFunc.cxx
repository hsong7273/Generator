//____________________________________________________________________________
/*!

\class    genie::GFunc

\brief    ABC for GENIE scalar & vector functions

\author   Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
          CCLRC, Rutherford Appleton Laboratory

\created  July 01, 2004

*/
//____________________________________________________________________________

#include <cassert>

#include "Numerical/GFunc.h"

using namespace genie;

//____________________________________________________________________________
GFunc::GFunc()
{

}
//____________________________________________________________________________
GFunc::GFunc(unsigned int ndim)
{
  this->Init(ndim);
}
//____________________________________________________________________________
GFunc::GFunc(const GFunc & func)
{
  this->Init(func.fNDim);
  for(unsigned int i=0; i<fNDim; i++) {
     Range1D_t lim = func.ParamLimits(i);
     string   name = func.ParamName(i);
     this->SetParam(i, name, lim);
  }
}
//____________________________________________________________________________
GFunc::~GFunc()
{
  this->CleanUp();
}
//____________________________________________________________________________
void GFunc::Init(unsigned int ndim)
{
  assert(ndim>0);

  fNDim  = ndim;
  fVMin  = new vector<double>(fNDim);
  fVMax  = new vector<double>(fNDim);
  fVName = new vector<string>(fNDim);
}
//____________________________________________________________________________
void GFunc::CleanUp()
{
  delete fVMin;
  delete fVMax;
  delete fVName;
}
//____________________________________________________________________________
void GFunc::SetParam(unsigned int idim, string name, double min, double max)
{
  assert(idim<fNDim);

  (*fVMin) [idim] = min;
  (*fVMax) [idim] = max;
  (*fVName)[idim] = name;
}
//____________________________________________________________________________
void GFunc::SetParam(unsigned int idim, string name, Range1D_t & limits)
{
  this->SetParam(idim, name, limits.min, limits.max);
}
//____________________________________________________________________________
Range1D_t GFunc::ParamLimits(unsigned int idim) const
{
  assert(idim<fNDim);

  double min = (*fVMin)[idim];
  double max = (*fVMax)[idim];

  Range1D_t limits(min, max);
  return limits;
}
//____________________________________________________________________________
string GFunc::ParamName(unsigned int idim) const
{
  assert(idim<fNDim);

  string name = (*fVName)[idim];
  return name;
}
//____________________________________________________________________________

