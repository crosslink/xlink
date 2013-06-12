/******************************************************************************
 * This file is part of the XLINK - The Link Discovery Toolkit.
 * (c) Copyright 2013 Queensland University of Technology
 *
 * This file may be distributed and/or modified under the terms of the
 * BSD 3-cause LICENSE appearing in the file BSD.txt included in the
 * packaging of this file.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *******************************************************************************
 *
 * @author				Eric Tang
 *
 *******************************************************************************/
 #ifndef __EXTRALIB_H__
#define __EXTRALIB_H__


#if defined (CYGWIN) || defined(cygwin) || defined(__WIN32__) || defined(__CYGWIN32__) || defined(_MSC_VER)

inline char *strndup(char const *s, size_t len)
{
 char *pc = NULL ;
 if (s != NULL) {
   pc = (char*) malloc((len + 1) * sizeof *pc ) ;
   if (pc != NULL) { strcpy (pc,s) ; }
 }
 return pc ;
}

inline char *strdup(char const *s)
{
  return strndup(s, strlen(s));
}


/*
 * http://cygwin.com/ml/cygwin/2003-06/msg01312.html
 */
#include <errno.h>

inline ssize_t getdelim(char **linebuf, size_t *linebufsz, int delimiter, FILE *file)
{
static const int GROWBY = 80; /* how large we will grow strings by */

	int ch;
	int idx = 0;


	if ((file == NULL || linebuf==NULL || *linebuf == NULL || *linebufsz == 0)
			&& !(*linebuf == NULL && *linebufsz ==0 )) {
	    errno=EINVAL;
	    return -1;
	}


	if (*linebuf == NULL && *linebufsz == 0){
		*linebuf = (char *)malloc(GROWBY);
		if (!*linebuf) {
			errno=ENOMEM;
			return -1;
		}
		*linebufsz += GROWBY;
	}


	while (1) {
		ch = fgetc(file);
		if (ch == EOF)
			break;
		/* grow the line buffer as necessary */
		while (idx > *linebufsz-2) {
			*linebuf = (char *)realloc(*linebuf, *linebufsz += GROWBY);
			if (!*linebuf) {
				errno=ENOMEM;
				return -1;
			}
		}
		(*linebuf)[idx++] = (char)ch;
		if ((char)ch == delimiter)
			break;
	}


	if (idx != 0)
	    (*linebuf)[idx] = 0;
	else if ( ch == EOF )
		return -1;
	return idx;
}



inline ssize_t getline(char **linebuf, size_t *n, FILE *file)
{
 return (getdelim (linebuf, n, '\n', file));
}



inline char *
basename (const char *filename)
{
 char *p = strrchr (filename, '/');
 return p ? p + 1 : (char *) filename;
}



# define __ptr_t void *

inline __ptr_t
__memrchr (const __ptr_t s, int c_in, size_t n)
{
 const unsigned char *char_ptr;
 const unsigned long int *longword_ptr;
 unsigned long int longword, magic_bits, charmask;
 unsigned char c;


c = (unsigned char) c_in;

 /* Handle the last few characters by reading one character at a time.
    Do this until CHAR_PTR is aligned on a longword boundary.  */
 for (char_ptr = (const unsigned char *) s + n;
      n > 0 && ((unsigned long int) char_ptr
		 & (sizeof (longword) - 1)) != 0;
      --n)
   if (*--char_ptr == c)
     return (__ptr_t) char_ptr;


 /* All these elucidatory comments refer to 4-byte longwords,
    but the theory applies equally well to 8-byte longwords.  */


longword_ptr = (const unsigned long int *) char_ptr;

 /* Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
    the "holes."  Note that there is a hole just to the left of
    each byte, with an extra at the end:


    bits:  01111110 11111110 11111110 11111111
    bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD


    The 1-bits make sure that carries propagate to the next 0-bit.
    The 0-bits provide holes for carries to fall into.  */


 if (sizeof (longword) != 4 && sizeof (longword) != 8)
   abort ();


#if LONG_MAX <= LONG_MAX_32_BITS
 magic_bits = 0x7efefeff;
#else
 magic_bits = ((unsigned long int) 0x7efefefe << 32) | 0xfefefeff;
#endif


 /* Set up a longword, each of whose bytes is C.  */
 charmask = c | (c << 8);
 charmask |= charmask << 16;
#if LONG_MAX > LONG_MAX_32_BITS
 charmask |= charmask << 32;
#endif


 /* Instead of the traditional loop which tests each character,
    we will test a longword at a time.  The tricky part is testing
    if *any of the four* bytes in the longword in question are zero.  */
 while (n >= sizeof (longword))
   {
     /* We tentatively exit the loop if adding MAGIC_BITS to
	 LONGWORD fails to change any of the hole bits of LONGWORD.


	 1) Is this safe?  Will it catch all the zero bytes?
	 Suppose there is a byte with all zeros.  Any carry bits
	 propagating from its left will fall into the hole at its
	 least significant bit and stop.  Since there will be no
	 carry from its most significant bit, the LSB of the
	 byte to the left will be unchanged, and the zero will be
	 detected.


	 2) Is this worthwhile?  Will it ignore everything except
	 zero bytes?  Suppose every byte of LONGWORD has a bit set
	 somewhere.  There will be a carry into bit 8.  If bit 8
	 is set, this will carry into bit 16.  If bit 8 is clear,
	 one of bits 9-15 must be set, so there will be a carry
	 into bit 16.  Similarly, there will be a carry into bit
	 24.  If one of bits 24-30 is set, there will be a carry
	 into bit 31, so all of the hole bits will be changed.


	 The one misfire occurs when bits 24-30 are clear and bit
	 31 is set; in this case, the hole at bit 31 is not
	 changed.  If we had access to the processor carry flag,
	 we could close this loophole by putting the fourth hole
	 at bit 32!


	 So it ignores everything except 128's, when they're aligned
	 properly.


	 3) But wait!  Aren't we looking for C, not zero?
	 Good point.  So what we do is XOR LONGWORD with a longword,
	 each of whose bytes is C.  This turns each byte that is C
	 into a zero.  */


longword = *--longword_ptr ^ charmask;

     /* Add MAGIC_BITS to LONGWORD.  */
     if ((((longword + magic_bits)


	    /* Set those bits that were unchanged by the addition.  */
	    ^ ~longword)


	   /* Look at only the hole bits.  If any of the hole bits
	      are unchanged, most likely one of the bytes was a
	      zero.  */
	   & ~magic_bits) != 0)
	{
	  /* Which of the bytes was C?  If none of them were, it was
	     a misfire; continue the search.  */


const unsigned char *cp = (const unsigned char *) longword_ptr;

#if LONG_MAX > 2147483647
	  if (cp[7] == c)
	    return (__ptr_t) &cp[7];
	  if (cp[6] == c)
	    return (__ptr_t) &cp[6];
	  if (cp[5] == c)
	    return (__ptr_t) &cp[5];
	  if (cp[4] == c)
	    return (__ptr_t) &cp[4];
#endif
	  if (cp[3] == c)
	    return (__ptr_t) &cp[3];
	  if (cp[2] == c)
	    return (__ptr_t) &cp[2];
	  if (cp[1] == c)
	    return (__ptr_t) &cp[1];
	  if (cp[0] == c)
	    return (__ptr_t) cp;
	}


     n -= sizeof (longword);
   }


char_ptr = (const unsigned char *) longword_ptr;

 while (n-- > 0)
   {
     if (*--char_ptr == c)
	return (__ptr_t) char_ptr;
   }


 return 0;
}

inline char *
dirname (char *path)
{
 static const char dot[] = ".";
 char *last_slash;


 /* Find last '/'.  */
 last_slash = path != NULL ? strrchr (path, '/') : NULL;


 if (last_slash != NULL && last_slash != path && last_slash[1] == '\0')
   {
     /* Determine whether all remaining characters are slashes.  */
     char *runp;


     for (runp = last_slash; runp != path; --runp)
	if (runp[-1] != '/')
	  break;


     /* The '/' is the last character, we have to look further.  */
     if (runp != path)
	last_slash = (char *)__memrchr (path, '/', runp - path);
   }


 if (last_slash != NULL)
   {
     /* Determine whether all remaining characters are slashes.  */
     char *runp;


     for (runp = last_slash; runp != path; --runp)
	if (runp[-1] != '/')
	  break;


     /* Terminate the path.  */
     if (runp == path)
	{
	  /* The last slash is the first character in the string.  We have to
	     return "/".  As a special case we have to return "//" if there
	     are exactly two slashes at the beginning of the string.  See
	     XBD 4.10 Path Name Resolution for more information.  */
	  if (last_slash == path + 1)
	    ++last_slash;
	  else
	    last_slash = path + 1;
	}


     last_slash[0] = '\0';
   }
 else
   /* This assignment is ill-designed but the XPG specs require to
      return a string containing "." in any case no directory part is
      found and so a static and constant string is required.  */
   path = (char *) dot;


 return path;
}
#endif
#endif //__EXTRALIB_H__
