#pragma once

#include "types.h"
#include "models.h"

#include <agge/types.h>
#include <functional>

namespace cf
{
	struct scroll_model
	{
		typedef std::function<void(agge::real_t position)> tracker_t;
		typedef std::shared_ptr<tracker_t> tracker_ptr_t;

		virtual ~scroll_model() { }
		virtual void set_visual_limits(agge::real_t lower, agge::real_t upper) = 0;
		virtual tracker_ptr_t drag(agge::real_t start) = 0;
		virtual tracker_ptr_t scale(agge::real_t start) = 0;
	};

	template <typename SampleT>
	struct time_scroll_model : scroll_model
	{
		typedef std::vector< sample<agge::real_t, SampleT> > positioned_samples_t;
		typedef std::shared_ptr<samples_t> positioned_samples_ptr_t;
		typedef std::function<void()> invalidated_cb;

		virtual void observe_series(request_t &request, const std::shared_ptr<async_series> &source,
			const positioned_samples_ptr_t &buffer, const invalidated_cb &invalidated) = 0;
	};
}
