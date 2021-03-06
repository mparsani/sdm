// Copyright (C) 2010-2013 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef cf3_sdm_equations_navierstokes_BCWall_hpp
#define cf3_sdm_equations_navierstokes_BCWall_hpp

////////////////////////////////////////////////////////////////////////////////

#include "cf3/sdm/core/BC.hpp"
#include "cf3/sdm/equations/navierstokes/LibNavierStokes.hpp"

namespace cf3 {
namespace sdm {
namespace equations {
namespace navierstokes {

////////////////////////////////////////////////////////////////////////////////

/// @brief Viscous adiabatic moving wall boundary condition for Navier-Stokes equations
///
/// The velocity inside the wall is reversed, so that a velocity flux results in zero.
/// The wall temperature is interpolated from inside.
///
/// By default the wall is not moving.
class sdm_equations_navierstokes_API BCWall1D : public sdm::core::BC<1,3>
{
public:
  BCWall1D(const std::string& name) : sdm::core::BC<1,3>(name) {}
  virtual ~BCWall1D() {}
  static std::string type_name() { return "BCWall1D"; }
  
  virtual void compute_boundary_solution( const RowVector_NEQS& inner_solution, 
                                          const ColVector_NDIM& coords,
                                          const ColVector_NDIM& face_normal, 
                                          RowVector_NEQS& boundary_solution );
};

////////////////////////////////////////////////////////////////////////////////

/// @brief Viscous adiabatic moving wall boundary condition for Navier-Stokes equations
///
/// The velocity inside the wall is reversed, so that a velocity flux results in zero.
/// The wall temperature is interpolated from inside.
///
/// By default the wall is not moving.
class sdm_equations_navierstokes_API BCWall2D : public sdm::core::BC<2,4>
{
public:
  BCWall2D(const std::string& name);
  virtual ~BCWall2D() {}
  static std::string type_name() { return "BCWall2D"; }
  
   virtual void compute_boundary_solution( const RowVector_NEQS& inner_solution,
                                          const ColVector_NDIM& coords,
                                          const ColVector_NDIM& face_normal, 
                                          RowVector_NEQS& boundary_solution );
private:
  Real m_wall_velocity;
};

////////////////////////////////////////////////////////////////////////////////

} // navierstokes
} // equations
} // sdm
} // cf3

////////////////////////////////////////////////////////////////////////////////

#endif // cf3_sdm_equations_navierstokes_BCWall_hpp
