///////////////////////////////////////////////////////////////////////////////
//
/// \file       simple_private.h
/// \brief      Private definitions for so called simple filters
//
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

#ifndef LZMA_SIMPLE_PRIVATE_H
#define LZMA_SIMPLE_PRIVATE_H

#include "simple_coder.h"


typedef struct lzma_simple_s lzma_simple;

struct lzma_coder_s {
	/// Next filter in the chain
	lzma_next_coder next;

	/// True if the next coder in the chain has returned LZMA_STREAM_END
	/// or if we have processed uncompressed_size bytes.
	bool end_was_reached;

	/// True if filter() should encode the data; false to decode.
	/// Currently all simple filters use the same function for encoding
	/// and decoding, because the difference between encoders and decoders
	/// is very small.
	bool is_encoder;

	/// Size of the data *left* to be processed, or LZMA_VLI_VALUE_UNKNOWN
	/// if unknown.
	lzma_vli uncompressed_size;

	/// Pointer to filter-specific function, which does
	/// the actual filtering.
	size_t (*filter)(lzma_simple *simple, uint32_t now_pos,
			bool is_encoder, uint8_t *buffer, size_t size);

	/// Pointer to filter-specific data, or NULL if filter doesn't need
	/// any extra data.
	lzma_simple *simple;

	/// The lowest 32 bits of the current position in the data. Most
	/// filters need this to do conversions between absolute and relative
	/// addresses.
	uint32_t now_pos;

	/// Size of the memory allocated for the buffer.
	size_t allocated;

	/// Flushing position in the temporary buffer. buffer[pos] is the
	/// next byte to be copied to out[].
	size_t pos;

	/// buffer[filtered] is the first unfiltered byte. When pos is smaller
	/// than filtered, there is unflushed filtered data in the buffer.
	size_t filtered;

	/// Total number of bytes (both filtered and unfiltered) currently
	/// in the temporary buffer.
	size_t size;

	/// Temporary buffer
	uint8_t buffer[];
};


extern lzma_ret lzma_simple_coder_init(lzma_next_coder *next,
		lzma_allocator *allocator, const lzma_filter_info *filters,
		size_t (*filter)(lzma_simple *simple, uint32_t now_pos,
			bool is_encoder, uint8_t *buffer, size_t size),
		size_t simple_size, size_t unfiltered_max, bool is_encoder);

#endif
