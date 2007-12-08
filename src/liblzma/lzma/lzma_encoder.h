///////////////////////////////////////////////////////////////////////////////
//
/// \file       lzma_encoder.h
/// \brief      LZMA method handler API
//
//  Copyright (C) 1999-2006 Igor Pavlov
//  Copyright (C) 2007 Lasse Collin
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LZMA_LZMA_ENCODER_H
#define LZMA_LZMA_ENCODER_H

#include "common.h"

extern lzma_ret lzma_lzma_encoder_init(lzma_next_coder *next,
		lzma_allocator *allocator, const lzma_filter_info *filters);

extern bool lzma_lzma_encode_properties(
		const lzma_options_lzma *options, uint8_t *byte);

/// Initializes the lzma_fastpos[] array.
extern void lzma_fastpos_init(void);

#endif
