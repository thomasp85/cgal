// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
// 
// release       : 
// release_date  : 
// 
// file          : leda_real.h
// package       : Number_types
// revision      : $Revision$
// revision_date : $Date$
// author(s)     : Stefan Schirra
//
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra@mpi-sb.mpg.de>)
// ======================================================================
 

#ifndef CGAL_REAL_H
#define CGAL_REAL_H

/*
#if !defined(LEDA_ROOT_INCL_ID)
#define LEDA_ROOT_INCL_ID 349117
#include <LEDA/REDEFINE_NAMES.h>
#endif
*/

#include <CGAL/basic.h>
#include <CGAL/LEDA_basic.h>

#ifndef CGAL_PROTECT_LEDA_REAL_H
#include <LEDA/real.h>
#define CGAL_PROTECT_LEDA_REAL_H
#endif // CGAL_PROTECT_LEDA_REAL_H

CGAL_BEGIN_NAMESPACE

template <> struct Number_type_traits<leda_real> {
  typedef Tag_false Has_gcd_tag;
  typedef Tag_true  Has_division_tag;
  typedef Tag_true  Has_sqrt_tag;
};

#ifndef CGAL_NO_NAMESPACE
inline
double
to_double(const leda_real & r)
{ return r.to_double(); }
#endif // CGAL_NO_NAMESPACE

inline
leda_real
sqrt(const leda_real & r)
{ return CGAL_LEDA_SCOPE::sqrt(r); }

inline
bool
is_finite(const leda_real &)
{ return true; }

inline
bool
is_valid(const leda_real &)
{ return true; }

inline
io_Operator
io_tag(const leda_real &)
{ return io_Operator(); }

#ifndef CGAL_CFG_NO_NAMESPACE
inline
Sign
sign(const leda_real& r)
{ return (Sign)CGAL_LEDA_SCOPE::sign(r); }

inline
Comparison_result
compare(const leda_real& r1, const leda_real& r2)
{
  int c = CGAL_LEDA_SCOPE::compare(r1,r2);
  return (c < 0) ? SMALLER : ((0 < c) ?  LARGER : EQUAL);
}
#endif // CGAL_CFG_NO_NAMESPACE

inline
Interval_base
to_interval (const leda_real & z)
{
  Protect_FPU_rounding<true> P (CGAL_FE_TONEAREST);
  double approx = z.to_double();
  double rel_error = z.get_double_error();
  FPU_set_cw(CGAL_FE_UPWARD);
  return ( Interval_nt_advanced(-rel_error,rel_error) + 1 ) * approx;
}


CGAL_END_NAMESPACE


#if ( __LEDA__ < 362 )
inline
leda_real
operator/= (leda_real&x, const leda_real&y)
{ x = x / y; return x; }
#endif // __LEDA__ < 362

/*
#if LEDA_ROOT_INCL_ID == 349117
#undef LEDA_ROOT_INCL_ID
#include <LEDA/UNDEFINE_NAMES.h>
#endif
*/

#endif // CGAL_REAL_H
