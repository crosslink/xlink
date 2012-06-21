/******************************************************************************
 * This file is part of the Simple Text Processing Library(STPL).
 * (c) Copyright 2007-2008 TYONLINE TECHNOLOGY PTY. LTD.
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU LESSER GENERAL PUBLIC LICENSE, Version 3 as published by the Free Software
 * Foundation and appearing in the file LICENSE.LGPL included in the
 * packaging of this file.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 *******************************************************************************
 *
 * @author				Ling-Xiang(Eric) Tang 
 *
 *******************************************************************************/

#ifndef STPL_TYPETRAITS_H_
#define STPL_TYPETRAITS_H_

namespace stpl {
	template <typename T>
	struct TypeTrait{
		typedef	typename T::string_type	string_type;
		typedef typename T::iterator	iterator;
	};
	
	template <typename T>
	struct EntityTrait{
		typedef	typename T::entity_type	entity_type;
	};
}

#endif /*STPL_TYPETRAITS_H_*/
