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
// file          : include/CGAL/Arithmetic_filter/predicates/sign_of_determinant.h
// package       : Interval_arithmetic
// author(s)     : Sylvain Pion <Sylvain.Pion@sophia.inria.fr>
//
// coordinator   : INRIA Sophia-Antipolis (<Mariette.Yvinec@sophia.inria.fr>)
// ======================================================================

// This file is automatically generated by the script
// examples/Interval_arithmetic/filtered_predicate_converter.

#ifndef CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H
#define CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H

CGAL_BEGIN_NAMESPACE

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* inline */
Sign
sign_of_determinant2x2(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11)
{
  CGAL_assertion(Interval_nt_advanced::want_exceptions);
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant2x2(
		a00.interval(),
		a01.interval(),
		a10.interval(),
		a11.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant2x2(
		a00.exact(),
		a01.exact(),
		a10.exact(),
		a11.exact());
  }
}

inline
Sign
sign_of_determinant2x2(
    const Static_adaptatif_filter &a00,
    const Static_adaptatif_filter &a01,
    const Static_adaptatif_filter &a10,
    const Static_adaptatif_filter &a11)
{
  bool re_adjusted = false;
  static double SAF_bound = -1.0;
  static double SAF_epsilon_0;

  // Check the bounds.  All arguments must be <= SAF_bound.
  if (	fabs(a00.value()) > SAF_bound ||
	fabs(a01.value()) > SAF_bound ||
	fabs(a10.value()) > SAF_bound ||
	fabs(a11.value()) > SAF_bound)
  {
re_adjust:
      // Re-adjust SAF_bound.
      SAF_bound = std::max(0.0, fabs(a00.value()));
      SAF_bound = std::max(SAF_bound, fabs(a01.value()));
      SAF_bound = std::max(SAF_bound, fabs(a10.value()));
      SAF_bound = std::max(SAF_bound, fabs(a11.value()));

      // recompute the epsilons: "just" call it over Static_filter_error.
      // That's the tricky part that might not work for everything.
      (void) sign_of_determinant2x2_SAF(
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		SAF_epsilon_0);

      // TODO: We should verify that all epsilons have really been updated.
  }

  try  // Try the epsilon variant of the predicate.
  {
    return sign_of_determinant2x2_SAF(
		Restricted_double(a00.value()),
		Restricted_double(a01.value()),
		Restricted_double(a10.value()),
		Restricted_double(a11.value()),
		SAF_epsilon_0);
  }
  catch (Restricted_double::unsafe_comparison)
  {
    // It failed, we re-adjust once.
    if (!re_adjusted) {
      re_adjusted = true;
      goto re_adjust;
    }
    // This scheme definitely fails => exact computation (filtered_exact<> ?).
    return sign_of_determinant2x2(
		a00.exact(),
		a01.exact(),
		a10.exact(),
		a11.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* inline */
Sign
sign_of_determinant3x3(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a02,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a12,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a20,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a21,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a22)
{
  CGAL_assertion(Interval_nt_advanced::want_exceptions);
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant3x3(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant3x3(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact());
  }
}

inline
Sign
sign_of_determinant3x3(
    const Static_adaptatif_filter &a00,
    const Static_adaptatif_filter &a01,
    const Static_adaptatif_filter &a02,
    const Static_adaptatif_filter &a10,
    const Static_adaptatif_filter &a11,
    const Static_adaptatif_filter &a12,
    const Static_adaptatif_filter &a20,
    const Static_adaptatif_filter &a21,
    const Static_adaptatif_filter &a22)
{
  bool re_adjusted = false;
  static double SAF_bound = -1.0;
  static double SAF_epsilon_0;

  // Check the bounds.  All arguments must be <= SAF_bound.
  if (	fabs(a00.value()) > SAF_bound ||
	fabs(a01.value()) > SAF_bound ||
	fabs(a02.value()) > SAF_bound ||
	fabs(a10.value()) > SAF_bound ||
	fabs(a11.value()) > SAF_bound ||
	fabs(a12.value()) > SAF_bound ||
	fabs(a20.value()) > SAF_bound ||
	fabs(a21.value()) > SAF_bound ||
	fabs(a22.value()) > SAF_bound)
  {
re_adjust:
      // Re-adjust SAF_bound.
      SAF_bound = std::max(0.0, fabs(a00.value()));
      SAF_bound = std::max(SAF_bound, fabs(a01.value()));
      SAF_bound = std::max(SAF_bound, fabs(a02.value()));
      SAF_bound = std::max(SAF_bound, fabs(a10.value()));
      SAF_bound = std::max(SAF_bound, fabs(a11.value()));
      SAF_bound = std::max(SAF_bound, fabs(a12.value()));
      SAF_bound = std::max(SAF_bound, fabs(a20.value()));
      SAF_bound = std::max(SAF_bound, fabs(a21.value()));
      SAF_bound = std::max(SAF_bound, fabs(a22.value()));

      // recompute the epsilons: "just" call it over Static_filter_error.
      // That's the tricky part that might not work for everything.
      (void) sign_of_determinant3x3_SAF(
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		SAF_epsilon_0);

      // TODO: We should verify that all epsilons have really been updated.
  }

  try  // Try the epsilon variant of the predicate.
  {
    return sign_of_determinant3x3_SAF(
		Restricted_double(a00.value()),
		Restricted_double(a01.value()),
		Restricted_double(a02.value()),
		Restricted_double(a10.value()),
		Restricted_double(a11.value()),
		Restricted_double(a12.value()),
		Restricted_double(a20.value()),
		Restricted_double(a21.value()),
		Restricted_double(a22.value()),
		SAF_epsilon_0);
  }
  catch (Restricted_double::unsafe_comparison)
  {
    // It failed, we re-adjust once.
    if (!re_adjusted) {
      re_adjusted = true;
      goto re_adjust;
    }
    // This scheme definitely fails => exact computation (filtered_exact<> ?).
    return sign_of_determinant3x3(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* inline */
Sign
sign_of_determinant4x4(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a02,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a03,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a12,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a13,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a20,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a21,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a22,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a23,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a30,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a31,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a32,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a33)
{
  CGAL_assertion(Interval_nt_advanced::want_exceptions);
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant4x4(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant4x4(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact());
  }
}

inline
Sign
sign_of_determinant4x4(
    const Static_adaptatif_filter &a00,
    const Static_adaptatif_filter &a01,
    const Static_adaptatif_filter &a02,
    const Static_adaptatif_filter &a03,
    const Static_adaptatif_filter &a10,
    const Static_adaptatif_filter &a11,
    const Static_adaptatif_filter &a12,
    const Static_adaptatif_filter &a13,
    const Static_adaptatif_filter &a20,
    const Static_adaptatif_filter &a21,
    const Static_adaptatif_filter &a22,
    const Static_adaptatif_filter &a23,
    const Static_adaptatif_filter &a30,
    const Static_adaptatif_filter &a31,
    const Static_adaptatif_filter &a32,
    const Static_adaptatif_filter &a33)
{
  bool re_adjusted = false;
  static double SAF_bound = -1.0;
  static double SAF_epsilon_0;

  // Check the bounds.  All arguments must be <= SAF_bound.
  if (	fabs(a00.value()) > SAF_bound ||
	fabs(a01.value()) > SAF_bound ||
	fabs(a02.value()) > SAF_bound ||
	fabs(a03.value()) > SAF_bound ||
	fabs(a10.value()) > SAF_bound ||
	fabs(a11.value()) > SAF_bound ||
	fabs(a12.value()) > SAF_bound ||
	fabs(a13.value()) > SAF_bound ||
	fabs(a20.value()) > SAF_bound ||
	fabs(a21.value()) > SAF_bound ||
	fabs(a22.value()) > SAF_bound ||
	fabs(a23.value()) > SAF_bound ||
	fabs(a30.value()) > SAF_bound ||
	fabs(a31.value()) > SAF_bound ||
	fabs(a32.value()) > SAF_bound ||
	fabs(a33.value()) > SAF_bound)
  {
re_adjust:
      // Re-adjust SAF_bound.
      SAF_bound = std::max(0.0, fabs(a00.value()));
      SAF_bound = std::max(SAF_bound, fabs(a01.value()));
      SAF_bound = std::max(SAF_bound, fabs(a02.value()));
      SAF_bound = std::max(SAF_bound, fabs(a03.value()));
      SAF_bound = std::max(SAF_bound, fabs(a10.value()));
      SAF_bound = std::max(SAF_bound, fabs(a11.value()));
      SAF_bound = std::max(SAF_bound, fabs(a12.value()));
      SAF_bound = std::max(SAF_bound, fabs(a13.value()));
      SAF_bound = std::max(SAF_bound, fabs(a20.value()));
      SAF_bound = std::max(SAF_bound, fabs(a21.value()));
      SAF_bound = std::max(SAF_bound, fabs(a22.value()));
      SAF_bound = std::max(SAF_bound, fabs(a23.value()));
      SAF_bound = std::max(SAF_bound, fabs(a30.value()));
      SAF_bound = std::max(SAF_bound, fabs(a31.value()));
      SAF_bound = std::max(SAF_bound, fabs(a32.value()));
      SAF_bound = std::max(SAF_bound, fabs(a33.value()));

      // recompute the epsilons: "just" call it over Static_filter_error.
      // That's the tricky part that might not work for everything.
      (void) sign_of_determinant4x4_SAF(
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		SAF_epsilon_0);

      // TODO: We should verify that all epsilons have really been updated.
  }

  try  // Try the epsilon variant of the predicate.
  {
    return sign_of_determinant4x4_SAF(
		Restricted_double(a00.value()),
		Restricted_double(a01.value()),
		Restricted_double(a02.value()),
		Restricted_double(a03.value()),
		Restricted_double(a10.value()),
		Restricted_double(a11.value()),
		Restricted_double(a12.value()),
		Restricted_double(a13.value()),
		Restricted_double(a20.value()),
		Restricted_double(a21.value()),
		Restricted_double(a22.value()),
		Restricted_double(a23.value()),
		Restricted_double(a30.value()),
		Restricted_double(a31.value()),
		Restricted_double(a32.value()),
		Restricted_double(a33.value()),
		SAF_epsilon_0);
  }
  catch (Restricted_double::unsafe_comparison)
  {
    // It failed, we re-adjust once.
    if (!re_adjusted) {
      re_adjusted = true;
      goto re_adjust;
    }
    // This scheme definitely fails => exact computation (filtered_exact<> ?).
    return sign_of_determinant4x4(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* CGAL_KERNEL_LARGE_INLINE */
Sign
sign_of_determinant5x5(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a02,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a03,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a04,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a12,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a13,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a14,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a20,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a21,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a22,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a23,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a24,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a30,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a31,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a32,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a33,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a34,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a40,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a41,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a42,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a43,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a44)
{
  CGAL_assertion(Interval_nt_advanced::want_exceptions);
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant5x5(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a04.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a14.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a24.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval(),
		a34.interval(),
		a40.interval(),
		a41.interval(),
		a42.interval(),
		a43.interval(),
		a44.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant5x5(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact());
  }
}

inline
Sign
sign_of_determinant5x5(
    const Static_adaptatif_filter &a00,
    const Static_adaptatif_filter &a01,
    const Static_adaptatif_filter &a02,
    const Static_adaptatif_filter &a03,
    const Static_adaptatif_filter &a04,
    const Static_adaptatif_filter &a10,
    const Static_adaptatif_filter &a11,
    const Static_adaptatif_filter &a12,
    const Static_adaptatif_filter &a13,
    const Static_adaptatif_filter &a14,
    const Static_adaptatif_filter &a20,
    const Static_adaptatif_filter &a21,
    const Static_adaptatif_filter &a22,
    const Static_adaptatif_filter &a23,
    const Static_adaptatif_filter &a24,
    const Static_adaptatif_filter &a30,
    const Static_adaptatif_filter &a31,
    const Static_adaptatif_filter &a32,
    const Static_adaptatif_filter &a33,
    const Static_adaptatif_filter &a34,
    const Static_adaptatif_filter &a40,
    const Static_adaptatif_filter &a41,
    const Static_adaptatif_filter &a42,
    const Static_adaptatif_filter &a43,
    const Static_adaptatif_filter &a44)
{
  bool re_adjusted = false;
  static double SAF_bound = -1.0;
  static double SAF_epsilon_0;

  // Check the bounds.  All arguments must be <= SAF_bound.
  if (	fabs(a00.value()) > SAF_bound ||
	fabs(a01.value()) > SAF_bound ||
	fabs(a02.value()) > SAF_bound ||
	fabs(a03.value()) > SAF_bound ||
	fabs(a04.value()) > SAF_bound ||
	fabs(a10.value()) > SAF_bound ||
	fabs(a11.value()) > SAF_bound ||
	fabs(a12.value()) > SAF_bound ||
	fabs(a13.value()) > SAF_bound ||
	fabs(a14.value()) > SAF_bound ||
	fabs(a20.value()) > SAF_bound ||
	fabs(a21.value()) > SAF_bound ||
	fabs(a22.value()) > SAF_bound ||
	fabs(a23.value()) > SAF_bound ||
	fabs(a24.value()) > SAF_bound ||
	fabs(a30.value()) > SAF_bound ||
	fabs(a31.value()) > SAF_bound ||
	fabs(a32.value()) > SAF_bound ||
	fabs(a33.value()) > SAF_bound ||
	fabs(a34.value()) > SAF_bound ||
	fabs(a40.value()) > SAF_bound ||
	fabs(a41.value()) > SAF_bound ||
	fabs(a42.value()) > SAF_bound ||
	fabs(a43.value()) > SAF_bound ||
	fabs(a44.value()) > SAF_bound)
  {
re_adjust:
      // Re-adjust SAF_bound.
      SAF_bound = std::max(0.0, fabs(a00.value()));
      SAF_bound = std::max(SAF_bound, fabs(a01.value()));
      SAF_bound = std::max(SAF_bound, fabs(a02.value()));
      SAF_bound = std::max(SAF_bound, fabs(a03.value()));
      SAF_bound = std::max(SAF_bound, fabs(a04.value()));
      SAF_bound = std::max(SAF_bound, fabs(a10.value()));
      SAF_bound = std::max(SAF_bound, fabs(a11.value()));
      SAF_bound = std::max(SAF_bound, fabs(a12.value()));
      SAF_bound = std::max(SAF_bound, fabs(a13.value()));
      SAF_bound = std::max(SAF_bound, fabs(a14.value()));
      SAF_bound = std::max(SAF_bound, fabs(a20.value()));
      SAF_bound = std::max(SAF_bound, fabs(a21.value()));
      SAF_bound = std::max(SAF_bound, fabs(a22.value()));
      SAF_bound = std::max(SAF_bound, fabs(a23.value()));
      SAF_bound = std::max(SAF_bound, fabs(a24.value()));
      SAF_bound = std::max(SAF_bound, fabs(a30.value()));
      SAF_bound = std::max(SAF_bound, fabs(a31.value()));
      SAF_bound = std::max(SAF_bound, fabs(a32.value()));
      SAF_bound = std::max(SAF_bound, fabs(a33.value()));
      SAF_bound = std::max(SAF_bound, fabs(a34.value()));
      SAF_bound = std::max(SAF_bound, fabs(a40.value()));
      SAF_bound = std::max(SAF_bound, fabs(a41.value()));
      SAF_bound = std::max(SAF_bound, fabs(a42.value()));
      SAF_bound = std::max(SAF_bound, fabs(a43.value()));
      SAF_bound = std::max(SAF_bound, fabs(a44.value()));

      // recompute the epsilons: "just" call it over Static_filter_error.
      // That's the tricky part that might not work for everything.
      (void) sign_of_determinant5x5_SAF(
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		SAF_epsilon_0);

      // TODO: We should verify that all epsilons have really been updated.
  }

  try  // Try the epsilon variant of the predicate.
  {
    return sign_of_determinant5x5_SAF(
		Restricted_double(a00.value()),
		Restricted_double(a01.value()),
		Restricted_double(a02.value()),
		Restricted_double(a03.value()),
		Restricted_double(a04.value()),
		Restricted_double(a10.value()),
		Restricted_double(a11.value()),
		Restricted_double(a12.value()),
		Restricted_double(a13.value()),
		Restricted_double(a14.value()),
		Restricted_double(a20.value()),
		Restricted_double(a21.value()),
		Restricted_double(a22.value()),
		Restricted_double(a23.value()),
		Restricted_double(a24.value()),
		Restricted_double(a30.value()),
		Restricted_double(a31.value()),
		Restricted_double(a32.value()),
		Restricted_double(a33.value()),
		Restricted_double(a34.value()),
		Restricted_double(a40.value()),
		Restricted_double(a41.value()),
		Restricted_double(a42.value()),
		Restricted_double(a43.value()),
		Restricted_double(a44.value()),
		SAF_epsilon_0);
  }
  catch (Restricted_double::unsafe_comparison)
  {
    // It failed, we re-adjust once.
    if (!re_adjusted) {
      re_adjusted = true;
      goto re_adjust;
    }
    // This scheme definitely fails => exact computation (filtered_exact<> ?).
    return sign_of_determinant5x5(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/* CGAL_KERNEL_LARGE_INLINE */
Sign
sign_of_determinant6x6(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a00,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a01,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a02,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a03,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a04,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a05,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a10,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a11,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a12,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a13,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a14,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a15,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a20,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a21,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a22,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a23,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a24,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a25,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a30,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a31,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a32,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a33,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a34,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a35,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a40,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a41,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a42,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a43,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a44,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a45,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a50,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a51,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a52,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a53,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a54,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &a55)
{
  CGAL_assertion(Interval_nt_advanced::want_exceptions);
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Sign result = sign_of_determinant6x6(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a04.interval(),
		a05.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a14.interval(),
		a15.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a24.interval(),
		a25.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval(),
		a34.interval(),
		a35.interval(),
		a40.interval(),
		a41.interval(),
		a42.interval(),
		a43.interval(),
		a44.interval(),
		a45.interval(),
		a50.interval(),
		a51.interval(),
		a52.interval(),
		a53.interval(),
		a54.interval(),
		a55.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return sign_of_determinant6x6(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a05.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a15.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a25.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a35.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact(),
		a45.exact(),
		a50.exact(),
		a51.exact(),
		a52.exact(),
		a53.exact(),
		a54.exact(),
		a55.exact());
  }
}

inline
Sign
sign_of_determinant6x6(
    const Static_adaptatif_filter &a00,
    const Static_adaptatif_filter &a01,
    const Static_adaptatif_filter &a02,
    const Static_adaptatif_filter &a03,
    const Static_adaptatif_filter &a04,
    const Static_adaptatif_filter &a05,
    const Static_adaptatif_filter &a10,
    const Static_adaptatif_filter &a11,
    const Static_adaptatif_filter &a12,
    const Static_adaptatif_filter &a13,
    const Static_adaptatif_filter &a14,
    const Static_adaptatif_filter &a15,
    const Static_adaptatif_filter &a20,
    const Static_adaptatif_filter &a21,
    const Static_adaptatif_filter &a22,
    const Static_adaptatif_filter &a23,
    const Static_adaptatif_filter &a24,
    const Static_adaptatif_filter &a25,
    const Static_adaptatif_filter &a30,
    const Static_adaptatif_filter &a31,
    const Static_adaptatif_filter &a32,
    const Static_adaptatif_filter &a33,
    const Static_adaptatif_filter &a34,
    const Static_adaptatif_filter &a35,
    const Static_adaptatif_filter &a40,
    const Static_adaptatif_filter &a41,
    const Static_adaptatif_filter &a42,
    const Static_adaptatif_filter &a43,
    const Static_adaptatif_filter &a44,
    const Static_adaptatif_filter &a45,
    const Static_adaptatif_filter &a50,
    const Static_adaptatif_filter &a51,
    const Static_adaptatif_filter &a52,
    const Static_adaptatif_filter &a53,
    const Static_adaptatif_filter &a54,
    const Static_adaptatif_filter &a55)
{
  bool re_adjusted = false;
  static double SAF_bound = -1.0;
  static double SAF_epsilon_0;

  // Check the bounds.  All arguments must be <= SAF_bound.
  if (	fabs(a00.value()) > SAF_bound ||
	fabs(a01.value()) > SAF_bound ||
	fabs(a02.value()) > SAF_bound ||
	fabs(a03.value()) > SAF_bound ||
	fabs(a04.value()) > SAF_bound ||
	fabs(a05.value()) > SAF_bound ||
	fabs(a10.value()) > SAF_bound ||
	fabs(a11.value()) > SAF_bound ||
	fabs(a12.value()) > SAF_bound ||
	fabs(a13.value()) > SAF_bound ||
	fabs(a14.value()) > SAF_bound ||
	fabs(a15.value()) > SAF_bound ||
	fabs(a20.value()) > SAF_bound ||
	fabs(a21.value()) > SAF_bound ||
	fabs(a22.value()) > SAF_bound ||
	fabs(a23.value()) > SAF_bound ||
	fabs(a24.value()) > SAF_bound ||
	fabs(a25.value()) > SAF_bound ||
	fabs(a30.value()) > SAF_bound ||
	fabs(a31.value()) > SAF_bound ||
	fabs(a32.value()) > SAF_bound ||
	fabs(a33.value()) > SAF_bound ||
	fabs(a34.value()) > SAF_bound ||
	fabs(a35.value()) > SAF_bound ||
	fabs(a40.value()) > SAF_bound ||
	fabs(a41.value()) > SAF_bound ||
	fabs(a42.value()) > SAF_bound ||
	fabs(a43.value()) > SAF_bound ||
	fabs(a44.value()) > SAF_bound ||
	fabs(a45.value()) > SAF_bound ||
	fabs(a50.value()) > SAF_bound ||
	fabs(a51.value()) > SAF_bound ||
	fabs(a52.value()) > SAF_bound ||
	fabs(a53.value()) > SAF_bound ||
	fabs(a54.value()) > SAF_bound ||
	fabs(a55.value()) > SAF_bound)
  {
re_adjust:
      // Re-adjust SAF_bound.
      SAF_bound = std::max(0.0, fabs(a00.value()));
      SAF_bound = std::max(SAF_bound, fabs(a01.value()));
      SAF_bound = std::max(SAF_bound, fabs(a02.value()));
      SAF_bound = std::max(SAF_bound, fabs(a03.value()));
      SAF_bound = std::max(SAF_bound, fabs(a04.value()));
      SAF_bound = std::max(SAF_bound, fabs(a05.value()));
      SAF_bound = std::max(SAF_bound, fabs(a10.value()));
      SAF_bound = std::max(SAF_bound, fabs(a11.value()));
      SAF_bound = std::max(SAF_bound, fabs(a12.value()));
      SAF_bound = std::max(SAF_bound, fabs(a13.value()));
      SAF_bound = std::max(SAF_bound, fabs(a14.value()));
      SAF_bound = std::max(SAF_bound, fabs(a15.value()));
      SAF_bound = std::max(SAF_bound, fabs(a20.value()));
      SAF_bound = std::max(SAF_bound, fabs(a21.value()));
      SAF_bound = std::max(SAF_bound, fabs(a22.value()));
      SAF_bound = std::max(SAF_bound, fabs(a23.value()));
      SAF_bound = std::max(SAF_bound, fabs(a24.value()));
      SAF_bound = std::max(SAF_bound, fabs(a25.value()));
      SAF_bound = std::max(SAF_bound, fabs(a30.value()));
      SAF_bound = std::max(SAF_bound, fabs(a31.value()));
      SAF_bound = std::max(SAF_bound, fabs(a32.value()));
      SAF_bound = std::max(SAF_bound, fabs(a33.value()));
      SAF_bound = std::max(SAF_bound, fabs(a34.value()));
      SAF_bound = std::max(SAF_bound, fabs(a35.value()));
      SAF_bound = std::max(SAF_bound, fabs(a40.value()));
      SAF_bound = std::max(SAF_bound, fabs(a41.value()));
      SAF_bound = std::max(SAF_bound, fabs(a42.value()));
      SAF_bound = std::max(SAF_bound, fabs(a43.value()));
      SAF_bound = std::max(SAF_bound, fabs(a44.value()));
      SAF_bound = std::max(SAF_bound, fabs(a45.value()));
      SAF_bound = std::max(SAF_bound, fabs(a50.value()));
      SAF_bound = std::max(SAF_bound, fabs(a51.value()));
      SAF_bound = std::max(SAF_bound, fabs(a52.value()));
      SAF_bound = std::max(SAF_bound, fabs(a53.value()));
      SAF_bound = std::max(SAF_bound, fabs(a54.value()));
      SAF_bound = std::max(SAF_bound, fabs(a55.value()));

      // recompute the epsilons: "just" call it over Static_filter_error.
      // That's the tricky part that might not work for everything.
      (void) sign_of_determinant6x6_SAF(
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		SAF_epsilon_0);

      // TODO: We should verify that all epsilons have really been updated.
  }

  try  // Try the epsilon variant of the predicate.
  {
    return sign_of_determinant6x6_SAF(
		Restricted_double(a00.value()),
		Restricted_double(a01.value()),
		Restricted_double(a02.value()),
		Restricted_double(a03.value()),
		Restricted_double(a04.value()),
		Restricted_double(a05.value()),
		Restricted_double(a10.value()),
		Restricted_double(a11.value()),
		Restricted_double(a12.value()),
		Restricted_double(a13.value()),
		Restricted_double(a14.value()),
		Restricted_double(a15.value()),
		Restricted_double(a20.value()),
		Restricted_double(a21.value()),
		Restricted_double(a22.value()),
		Restricted_double(a23.value()),
		Restricted_double(a24.value()),
		Restricted_double(a25.value()),
		Restricted_double(a30.value()),
		Restricted_double(a31.value()),
		Restricted_double(a32.value()),
		Restricted_double(a33.value()),
		Restricted_double(a34.value()),
		Restricted_double(a35.value()),
		Restricted_double(a40.value()),
		Restricted_double(a41.value()),
		Restricted_double(a42.value()),
		Restricted_double(a43.value()),
		Restricted_double(a44.value()),
		Restricted_double(a45.value()),
		Restricted_double(a50.value()),
		Restricted_double(a51.value()),
		Restricted_double(a52.value()),
		Restricted_double(a53.value()),
		Restricted_double(a54.value()),
		Restricted_double(a55.value()),
		SAF_epsilon_0);
  }
  catch (Restricted_double::unsafe_comparison)
  {
    // It failed, we re-adjust once.
    if (!re_adjusted) {
      re_adjusted = true;
      goto re_adjust;
    }
    // This scheme definitely fails => exact computation (filtered_exact<> ?).
    return sign_of_determinant6x6(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a05.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a15.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a25.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a35.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact(),
		a45.exact(),
		a50.exact(),
		a51.exact(),
		a52.exact(),
		a53.exact(),
		a54.exact(),
		a55.exact());
  }
}

CGAL_END_NAMESPACE

#endif // CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H
