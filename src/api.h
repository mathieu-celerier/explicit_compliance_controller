#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define ExplicitCompCtrl_DLLIMPORT __declspec(dllimport)
#  define ExplicitCompCtrl_DLLEXPORT __declspec(dllexport)
#  define ExplicitCompCtrl_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define ExplicitCompCtrl_DLLIMPORT __attribute__((visibility("default")))
#    define ExplicitCompCtrl_DLLEXPORT __attribute__((visibility("default")))
#    define ExplicitCompCtrl_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define ExplicitCompCtrl_DLLIMPORT
#    define ExplicitCompCtrl_DLLEXPORT
#    define ExplicitCompCtrl_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef ExplicitCompCtrl_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define ExplicitCompCtrl_DLLAPI
#  define ExplicitCompCtrl_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef ExplicitCompCtrl_EXPORTS
#    define ExplicitCompCtrl_DLLAPI ExplicitCompCtrl_DLLEXPORT
#  else
#    define ExplicitCompCtrl_DLLAPI ExplicitCompCtrl_DLLIMPORT
#  endif // ExplicitCompCtrl_EXPORTS
#  define ExplicitCompCtrl_LOCAL ExplicitCompCtrl_DLLLOCAL
#endif // ExplicitCompCtrl_STATIC
