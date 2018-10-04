#pragma once

#include "types.h"

#include <functional>
#include <vector>

namespace cf
{
	template <typename SampleT>
	struct async_series
	{
		typedef std::vector< sample<timestamp_t, SampleT> > samples_t;
		typedef std::shared_ptr<samples_t> samples_ptr_t;
		typedef std::function<void(samples_ptr_t buffer)> samples_ready_cb;
		typedef std::function<void(timestamp_t from, timestamp_t to)> boundaries_ready_cb;

		virtual ~async_series() { }
		virtual void get(request_t &request, timestamp_t from, timestamp_t to, const samples_ptr_t &buffer,
			const samples_ready_cb &ready) = 0;
		virtual void get_boundaries(request_t &request, const boundaries_ready_cb &ready) = 0;
	};
}
