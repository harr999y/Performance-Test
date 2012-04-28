/**
**********************************************************************
*	@defgroup CommonHeader common header for perfomance test 
*	@author Li Suyong
*  @version 1.0
*  @date 2011/10/7
***********************************************************************
@{ */

#pragma  once

/** for unicode */
#ifndef UNICODE
#ifndef _UNICODE
#define _UNICODE
#endif
#define UNICODE
#endif

/* for windows.h's warning level */
#pragma warning(push, 3)
#include <windows.h>
#pragma warning(pop)

/* for common headers */
#pragma warning(push, 4)
#include <iosfwd>
#include <stdlib.h>
#include <memory> // for shared_ptr
#include <assert.h>

#define PROCESS_WIN_ERROR(x) \
	if (!x) MessageBox(0, TEXT("Getting Error£¡"), NULL, 0);

#define SAFE_DELETE(x) \
	if (x) { \
	delete x; \
	x = NULL; }

#define IF_NULL_RETURN(x) \
	if (!x) return;
#define IF_NULL_RETURN_VALUE(x, y) \
	if (!x) return y;
#define IF_NULL_CONTINUE(x) \
	if (!x) continue;
#define IF_NULL_BREAK(x) \
	if (!x) break;

 /** Define DISALLOW_COPY_AND_ASSIGN macro for copy-constructor
       and operator =. */
#define DISALLOW_COPY_AND_ASSIGN(Type)\
	Type(Type const &);\
	void operator=(Type const &);

#ifdef DLL_AS_EXPORT
#define PERFORMANCE_TEST_API _declspec(dllexport)
#else
#define PERFORMANCE_TEST_API _declspec(dllimport)
#endif
	
/** @} */