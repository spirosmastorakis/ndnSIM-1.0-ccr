/* -*- Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2011 University of California, Los Angeles
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Alexander Afanasyev <alexander.afanasyev@ucla.edu>
 */

#ifndef _CCNB_PARSER_UINT32T_BLOB_VISITOR_H_
#define _CCNB_PARSER_UINT32T_BLOB_VISITOR_H_

#include "no-argu-depth-first-visitor.h"

NDN_NAMESPACE_BEGIN

namespace wire {
namespace CcnbParser {

/**
 * \ingroup ccnx-ccnb
 * \brief Visitor to obtain nonce value from BLOB block
 *
 * Note, only first 32 bits will be actually parsed into nonce. If
 * original Nonce contains more, the rest will be ignored
 *
 * Will return empty boost::any() if called on anything except BLOB block
 */
class Uint32tBlobVisitor : public NoArguDepthFirstVisitor
{
public:
  virtual boost::any visit (Blob &n); 
  virtual boost::any visit (Udata &n); ///< Throws parsing error if BLOB object is encountered
};

} // CcnbParser
} // wire

NDN_NAMESPACE_END

#endif // _CCNB_PARSER_UINT32T_BLOB_VISITOR_H_
