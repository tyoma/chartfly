#pragma once

#include <memory>

namespace cf
{
	typedef long long timestamp_t;
	typedef std::shared_ptr<void> request_t;

	template <typename X, typename SampleT>
	struct sample
	{
		X x;
		SampleT value;
	};
}
