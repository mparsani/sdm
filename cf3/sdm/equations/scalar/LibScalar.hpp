// Copyright (C) 2010-2013 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef cf3_sdm_scalar_LibScalar_hpp
#define cf3_sdm_scalar_LibScalar_hpp

////////////////////////////////////////////////////////////////////////////////

#include "common/Library.hpp"

////////////////////////////////////////////////////////////////////////////////

/// Define the macro scalar_API
/// @note build system defines COOLFLUID_sdm_SCALAR_EXPORTS when compiling scalar files
#ifdef COOLFLUID_sdm_SCALAR_EXPORTS
#   define sdm_scalar_API      CF3_EXPORT_API
#   define sdm_scalar_TEMPLATE
#else
#   define sdm_scalar_API      CF3_IMPORT_API
#   define sdm_scalar_TEMPLATE CF3_TEMPLATE_EXTERN
#endif

////////////////////////////////////////////////////////////////////////////////

namespace cf3 {
namespace sdm {
namespace scalar {

////////////////////////////////////////////////////////////////////////////////

/// Class defines the scalar library
class sdm_scalar_API LibScalar : public common::Library
{
public:

  /// Constructor
  LibScalar ( const std::string& name) : common::Library(name) { }

  virtual ~LibScalar() { }

public: // functions

  /// @return string of the library namespace
  static std::string library_namespace() { return "cf3.sdm.scalar"; }

  /// Static function that returns the library name.
  /// Must be implemented for Library registration
  /// @return name of the library
  static std::string library_name() { return "scalar"; }

  /// Static function that returns the description of the library.
  /// Must be implemented for Library registration
  /// @return description of the library

  static std::string library_description()
  {
    return "This library implements scalar equations";
  }

  /// Gets the Class name
  static std::string type_name() { return "LibScalar"; }

}; // end LibScalar

////////////////////////////////////////////////////////////////////////////////

} // scalar
} // sdm
} // cf3

////////////////////////////////////////////////////////////////////////////////

#endif // cf3_sdm_scalar_LibScalar_hpp

